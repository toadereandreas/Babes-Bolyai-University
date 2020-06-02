; Se dau doua numere naturale a si b (a, b: dword, definite in segmentul de date). 
; Sa se calculeze suma lor si sa se afiseze in urmatorul format: "<a> + <b> = <result>"
;   Exemplu: "1 + 2 = 3"
;   Valorile vor fi afisate in format decimal (baza 10) cu semn.
bits 32
global start        

extern exit, printf               
import exit   msvcrt.dll 
import printf msvcrt.dll

segment data use32 class = data
    a      dd 1
    b      dd 2
    res    dd 0
    format db "%d + %d = %d", 0

segment code use32 class = code
    start:
        ; Adunam pe a si pe b in eax, apoi stocam rezultatul in variabila res
        mov eax, [a]
        add eax, [b]
        mov [res], eax
        
        ; Afisam textul cerut
        push dword [res]
        push dword [b]
        push dword [a]
        push dword format
        call [printf]
        add esp, 4 * 4  ; Eliberam stiva
        
        push    dword 0
        call    [exit]       
