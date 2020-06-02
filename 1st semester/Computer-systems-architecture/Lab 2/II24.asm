bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DB 9
    b DB 3
    c DB 1
    d DB 6
    ; ...

; our code starts here
segment code use32 class=code
    start:
        ; ( a - b - b - c ) + ( a - c - c - d )
        
        ; We calculate ( a - b - b - c ) in AX. The result will be stored in AX
        ; e.g. a = 9, b = 3, c = 1, d = 2 => ( a - b - b - c ) = ( 9 - 3 - 3 - 1 ) = 2
        mov EAX, 0   ; We make sure that EAX is 0
        mov AX, [a]  ; AX = a = 9
        sub AX, [b]  ; AX = AX - b = 9 - 3 = 6
        sub AX, [b]  ; AX = AX - b = 6 - 3 = 3
        sub AX, [c]  ; AX = AX - c = 3 - 1 = 2
        
        ; We calculate ( a - c - c - d ) in BX
        ; e.g. a = 9, b = 3, c = 1, d = 2 => ( a - c - c - d ) = ( 9 - 1 - 1 - 6 ) = 1
        mov EBX, 0   ; We make sure that EBX is 0
        mov BX, [a]  ; BX = a = 9
        sub BX, [c]  ; BX = BX - c = 9 - 1 = 8
        sub BX, [c]  ; BX = BX - c = 8 - 1 = 7
        sub BX, [d]  ; BX = BX - d = 7 - 6 = 1
        
        ; Now we calculate ( a - b - b - c ) + ( a - c - c - d )
        ; e. g. => ( a - b - b - c ) + ( a - c - c - d ) = 2 + 1 = 3
        add AX, BX   ; AX = AX + BX = 2 + 1 = 3
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
