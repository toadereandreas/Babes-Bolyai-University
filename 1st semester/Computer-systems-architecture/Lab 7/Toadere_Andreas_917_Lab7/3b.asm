; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de cifre pare si sa se afiseze aceasta valoare. 
; Numele fisierului text este definit in segmentul de date.
bits 32
global start        

extern exit, fread, fopen, fclose, printf   
import printf msvcrt.dll  
import exit   msvcrt.dll
import fread  msvcrt.dll
import fopen  msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db    "input_file.txt", 0
    mod_acces   db    "r"             , 0
    descriptor  dd      -1
    lungime_max equ   1000
    format_rez  db    "In fisier sunt %d cifre pare.", 0
    format_nr   db    "%c,", 0
    nr_cif_pare dd       0
    sir_fisier  times lungime_max db 0
    aux         db      -1
    
segment code use32 class=code
    start:
        ; Deschid fisierul
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2
        
        ; Verific daca s-a deschis in mod corect
        cmp eax, 0
        je invalid
        mov [descriptor], eax
        
        ; Citesc fisierul byte cu byte si stochez in sir_fisier
        push dword [descriptor]
        push dword lungime_max
        push dword 1
        push dword sir_fisier
        call [fread]
        add esp, 4 * 4
     
        ; Inchid fisierul
        push dword [descriptor]
        call [fclose]
        add esp, 4 * 1
        
        ; Parcurg sirul de la dreapta spre stanga
        mov esi, sir_fisier
        mov ecx, 16
        cld
        
        ; exemplu : input_file.txt = "2468135788776655"
        repeta:
            push ecx         ; salvez valoarea lui ecx
            xor eax, eax
            lodsb            ; incarc byte
            cmp al, 0        ; compar byte-ul cu 0
            jpo e_impar      ; daca este impar sar
            add byte [nr_cif_pare], 1   ; daca este par, incrementez nr cifrelor pare
            push dword eax              ; afisez cifra
            push dword format_nr        
            call [printf]
            add esp, 4 * 2
            e_impar:
            pop ecx          
        loop repeta
        
        ; Afisez numarul de cifre pare
        push dword [nr_cif_pare]
        push dword format_rez
        call [printf]
        add esp, 4 * 2
        
        invalid :
        
        push    dword 0  
        call    [exit]    