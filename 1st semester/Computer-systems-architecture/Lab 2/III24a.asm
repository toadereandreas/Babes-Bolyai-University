bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DB 5
    b DB 4
    c DB 1
    d DW 20
    ; ...

; our code starts here
segment code use32 class=code
    start:
        ; We calculate ( 10 * a - 5 * b ) + ( d - 5 * c )
        mov EAX, 0   ; We make sure that EAX does not have random value : EAX = 0
        mov AL, [a]  ; AL = a = 5
        mov CL, 10   ; We use CL as an auxiliary register to multiply with AL : CL = 10  ????????  
        mul CL       ; AL = AL * CL = 5 * 10 = 50
        
        ; We store the result in CL then empty AL to calculate 5 * b
        mov CL, AL   ; CL = AL = 50
        mov AL, 0    ; AL = 0
        mov AL, [b]  ; AL = b = 4
        mov DL, 5    ; We use DL as an auxiliary register to multiply with Al : DL = 5
        mul DL       ; AL = AL * DL = 4 * 5 = 20
        
        ; Then we calculate ( 10 * a - 5 * b ) in CL
        sub CL, AL   ; CL = CL - AL = 50 - 20 = 30
        
        ; We calculate 5 * c
        mov AL, 0    ; AL = 0
        mov AL, [c]  ; AL = c = 1
        mul DL       ; Already DL = 5 => AL = AL * DL = 1 * 5 = 5
        mov DX, 0    ; We do not need DL to multiply by 5 so we give it the value 0 : DX = 0
        mov DX, [d]  ; Then store d in it : DX = d = 20
        sub DX, AX   ; DX = DX - AX = 20 - 5 = 15
        
        ; Now we have CX = CL = ( 10 * a - 5 * b ) = 30
        ; and  DX = ( d - 5 * c ) = 15 so we add them in CX
        add CX, DX   ; CX = CX + DC = 30 + 15 = 45
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
