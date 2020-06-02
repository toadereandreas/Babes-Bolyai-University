; Write a program in assembly language which computes (b+b+d)-(c+a) considering the following domains for the variables in the unsigned representation:
; a - byte, b - word, c - double word, d - qword

bits 32 ; assembling for the 32 bits architecture
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

segment data use32 class=data
    a db -2
    b dw 6
    c dd 4
    d dq 16

segment code use32 class=code
    start:
        xor eax, eax
        
        mov al, [a] ; AL = -2
        cbw         ; AL -> AX
        cwde        ; AX -> EAX
        add eax, [c]; EAX = -2 + 4 = 2
        
        push eax    ; for the moment we keep c + a in stack
        
        xor eax, eax; EAX = 0
        
        add ax, [b] ; AX = 0 + 6 = 6
        add ax, [b] ; AX = 6 + 6 = 12
        cwde        ; AX -> EAX
        cdq         ; EAX -> EDX:EAX
        add eax, [d]; EAX -> EAX = 12 + 16 = 28
        adc edx, 0  ; add potential carry to EDX
        
        pop ebx     ; EBX = c + a = 2
        
        sub eax, ebx ; EAX = 28 - 2 = 26
        sbb edx, 0   ; subtract potential carry from EDX
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
