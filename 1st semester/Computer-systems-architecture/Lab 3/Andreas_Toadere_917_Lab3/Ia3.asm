; Write a program in assembly language which computes (c+d)-(a+d)+b considering the following domains for the variables in the unsigned representation :
; a - byte, b - word, c - double word, d - qword

bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 5
    b dw 9
    c dd 12
    d dq 2  

; our code starts here
segment code use32 class=code
    start:
        xor eax, eax ; EAX = 0
    
        mov eax, [c] ; EAX = 12
        cdq          ; EAX -> EDX:EAX
        add eax, [d] ; EDX:EAX = 12 + 2 = 14
        
        mov ebx, edx
        mov ecx, eax
        
        xor eax, eax
        xor edx, edx
        
        mov al, [a] ; EAX = 5
        cbw
        cwd
        cwde
        cdq          ; EAX -> EDX:EAX
        add eax, [d] ; EAX = 5 + 2 = 7
        
        add eax, ecx ; EAX = EAX + ECX = 7 + 14 = 21
        adc edx, ebx
        
        add ax, [b]  ; AX = 21 + bits 32 ; assembling for the 32 bits architecture

        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
