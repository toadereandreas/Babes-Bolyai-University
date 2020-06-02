; Se da un sir S de dublucuvinte. 
; Sa se obtina sirul D format din octetii dublucuvintelor din sirul D sortati in ordine crescatoare in interpretarea fara semn.
; Exemplu :
;   s DD 12345607h, 1A2B3C15h,
;   d DB 07h, 12h, 15h, 1Ah, 2Bh, 34h, 3Ch, 56h

bits 32 
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class = data
    s  dd    12345607h, 1A2B3C15h   ; Sirul initial de dublucuvinte
    ls equ   ($-s)                  ; Lungimea sirului s in octeti
    d  times ls*8 db 0              ; d va fi sirul solutie
    ld db 0
    
segment code use32 class = code
    start:
        mov esi, s            ; setam sirul sursa ca fiind s
        cld                   ; vom parcurge sirul s de la stanga la dreapta
        mov ecx, ls           ; vom parcurge elementele sirului s
        jecxz invalid
        
        repeta :
        
            mov eax, 0
            lodsb             ; luam un octet
            push ecx          ; tinem minte valoarea contorului in stiva
            mov ecx, [ld]     ; punem in cl lungimea curenta a sirului destinatie
            
            jecxz neglijeaza  ; daca e primul element din s, nu il mai comparam
            
            dest_el_loop:           ; bucla parcurge sirul d de la dreapta la stanga
                cmp [d+ecx-1], al   ; comparam octetul curent din s cu octetii din d, incepand de la cel mai din dreapta
                jb neglijeaza       ; daca octetul curent din s este mai mare atunci il vom pune la final => nu e necesara mutarea altor elementele
                mov bl,[d+(ecx-1)]  ; "dublam" octetul curent din d pentru a face loc pt. octetulcurent din s 
                mov [d+ecx], bl
            loop dest_el_loop       ; vom iesi din bucla atunci cand vom gasi pozitia corecta a octetului curent din s si anume d+ecx
            
            neglijeaza:
            
            mov [d+ecx], al         ; asezam octetul curent din s in pozitia corecta
            inc byte [ld]           ; incrementam lungimea sirului d
            pop ecx                 ; repetam procesul de cate ori e necesar ( numarul de octeti )
            
        loop repeta
        
        invalid:
        push    dword 0     
        call    [exit]     