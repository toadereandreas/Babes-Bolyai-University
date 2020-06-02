; Read a sentence from the keyboard. Count the letters from each word and print the numbers on the screen. 
bits 32
global start

extern exit,scanf,printf

%include "modul.asm"

import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    formatC dd "%c",0
    formatS dd "%s",0
    caracter dd 0
    sir_litere dd 0
    
segment code use32 class=code
start:
    mov edi, numere
    CitesteCaracter:
        ; Citesc caracter
        push dword sir_litere
        push dword formatC
        call [scanf]
        add esp, 4 * 2
        
        ; Verific daca e cifra
        mov eax,[sir_litere]
        push eax
        call VerifyChar
        
        mov eax, [esp]
        add esp, 4 * 1
        cmp eax, 0
        je Sfarsit
        cmp eax, 1
        je CitesteCaracter
          mov esi, sir_litere
          movsb
          
        jmp CitesteCaracter
    
    Sfarsit:
    
    push dword numere
    push dword formatS
    call [printf]
    add esp, 4 * 2
    
    push dword 0
    call [exit]