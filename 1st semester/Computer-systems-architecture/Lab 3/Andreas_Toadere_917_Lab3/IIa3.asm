; Write a program in assembly language which computes (8-a*b*100+c)/d+x considering the following domains for the variables in the unsigned representation:
; a - byte, b - byte, d - byte, c-doubleword, x-qword

bits 32 ; assembling for the 32 bits architecture
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

segment data use32 class=data
    a db 2
    b db 3
    c dw 8
    d db 100
    x dq 25
    aux db 100

segment code use32 class=code
    start:
        
        xor ebx, ebx  ; EBX = 0
        mov ebx, 8    ; EBX = 8
        
        xor eax, eax  ; EBX = 0
        mov al, 0
        mov al, [a]   ; AL = 2
        mul byte [b]  ; AX = AL * 3 = 2 * 3 = 6
        mul byte [aux]; AX = 6 * 100 = 600
        
        sub ebx, eax  ; EBX = EBX - EAX = 8 - 600 = -592
        
        xor eax, eax  ; EAX = 0
        mov eax, ebx  ; EAX = -592
        
        xor ecx, ecx  ; ECX = 0
        ;mov cx, [d]   ; CX = 50
        
        mov ebx, eax
        mov edx, [d]
        cbw
        mov cx, ax; cx = d
        mov eax, ebx
        shr edx, 16
        idiv cx     ; AX = DX:AX / CX, DX = DX:AX % CX
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
