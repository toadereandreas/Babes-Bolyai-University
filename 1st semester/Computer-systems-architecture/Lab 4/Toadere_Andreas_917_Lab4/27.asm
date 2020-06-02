; Se da quadwordul A. Sa se obtina numarul intreg N reprezentat de bitii 35-37 ai lui A.
; Sa se obtina apoi in B dublucuvantul rezultat prin rotirea spre dreapta a dublucuvantului inferior al lui A cu N pozitii.
; Sa se obtina octetul C astfel:
;   bitii 0-3 ai lui C sunt bitii 8-11 ai lui B
;   bitii 4-7 ai lui C sunt bitii 16-19 ai lui B

bits 32
global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
   a dq 1010101010101010101010101010101001010101010101010101010101010101b
   c db 0

segment code use32 class=code
    start:
        
        xor eax, eax     ; Vom stoca high doubleword-ul lui A in EAX
        mov eax, [a+4]   ; Mutam doubleword-ul high al lui A in EAX : acum vom aveam in EAx bitii 32-63 ai lui A
        
        ; Acum voi obtine pe N
        mov cl, 3        ; Pregatesc rotirea la dreaptea pentru a aduce bitii 35-37 pe pozitiile cele mai din dreapta
        ror eax, cl      ; Rotim bitii din EAX spre dreapta de 3 ori
        
        xor ebx, ebx     ; Voi stoca bitii 35-42 ai A-ului initial in BL
        mov bl, al       ;
        and bl, 00000111b; Izolam bitii 35-37 ai A-ului initial si 'stergem' ceilalti, astfel obtinand in BL reprezentarea binara ai lui N.
                         ; Pt. A-ul de mai sus N-ul va fi egal cu 101b = 5d
                         
        ; Acum voi obtine pe B                 
        xor eax, eax     ; Vom stoca low doubleword-ul lui A in EAX
        mov eax, [a]     ; Mutam doubleword-ul low al lui A in EAX : acum vom aveam in EAX bitii 0-31 ai lui A
        
        mov cl, bl       ; Mutam in CL pe N pentru ca ulterior sa rotesc spre dreaptea pe EAX de N ori
        ror eax, cl      ; Rotesc pe EAX spre dreapta de N ori => acum avem pe B in EAX
        
        mov edx, eax     ; Stochez valoarea lui B in EDX pentru ca ulterior voi avea nevoie din nou de bitii lui B
        
        ; Acum ma voi ocupa de obtinerea bitilor 16-19 ai lui B
        mov cl, 15       ; Pregatesc rotirea lui EDX spre dreapta
        ror edx, cl      ; Rotesc pe B spre dreapta de 15 ori pentru a avea bitii 16-19 ale B-ului initial pe pozitiile cele mai din dreapta
        and edx, 00000000000000000000000000001111b ; Izolam bitii 0-3 ai lui EDX ( bitii 16-19 ai B-ului initial)
                         ; Rezultatul final ( C ) va fi stocat in DL asa ca voi shifa spre stanga pentru a avea bitii 16-19 ai B-ului
                         ; initial pe pozitiile 4-7 ale lui C
        mov cl, 4        ; Voi shifta de 4 ori spre stanga pentru a aduce bitii de pe pozitiile 0-3 pe pozitiile 4-7
        sal dl, cl       ; Astfel vom avea bitii 16-19 ai B-ului initial pe pozitiile 4-7 ale lui DL
        
        ; Acum ma voi ocupa de obtinerea bitilor 8-11 ai lui B
        mov cl, 7        ; Pregatesc rotirea lui EAX spre dreapta
        ror eax, cl      ; Rotesc pe B spre dreapta de 8 ori pentru a avea bitii 8-11 ale B-ului initial pe pozitiile cele mai din dreapta
        
        mov bl, al       ; Acum avem in BL bitii 8-15 ai B-ului initial
        and bl, 00001111b; Izolam bitii 8-11 ai B-ului initial pe pozitiile 0-3 ale lui BL
        
        ; Obtinerea rezultatului
        or dl, bl        ; punem pe bl in dl => vom avea in dl pe C
        mov c, dl
        push    dword 0      
        call    [exit]
