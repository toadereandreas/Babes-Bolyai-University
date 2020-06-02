; Se dau doua siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel: fiecare element de pe pozitiile pare din D 
; este suma elementelor de pe pozitiile corespunzatoare din S1 si S2, iar fiecare element de pe pozitiile impare are ca si valoare diferenta 
; elementelor de pe pozitiile corespunzatoare din S1 si S2. 
;
; Exemplu :
; S1: 1,  2,  3,  4
; S2: 5,  6,  7,  8
; D : 6, -4, 10, -4

bits 32 
global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    s1 db 1, 2, 3, 4
    l  equ $-s1
    s2 db 5, 6, 7, 8
    d  times l db 0


segment code use32 class=code
    start:
        xor ecx, ecx
    
        mov ax, 0                ; Initializam AX cu 0 ( pt. impartirea ulterioara )
        mov al, l                ; Mutam lungimea sirurilor in AL
        mov bl, 2                ; Dorim sa impartim cu 2 lungimea pt. a obtine nr. incrementarilor necesare pt. fiecare bucla
        div bl                   ; Impartim pe AX cu 2 => astfel obtinem in AL jumatatea lungimii sirurilor
        mov dl, al               ; Stocam jumatatea lungimii sirurilor in DL
           
        ; Preconditii bucla pozitii pare
        mov cl,  dl              ; Punem jumatatea lungimii sirurilor in ECX pentru a putea realiza prima bucla loop ( pt. pozitiile pare )
        mov esi,  0              ; Vom folosi ESI pe post de indice ( in prima bucla ESI va fi 0, 2, 4, ... )
        jecxz InvalidPar         ; Daca lui ECX nu i-a fost atribuita o valoare, evitam bucla
        
        RepetaPar:               ; Repeta bucla pt. pozitii pare de l/2 ori
                mov al, [s1+esi] ; AL = s1[esi]
                mov bl, [s2+esi] ; BL = s2[esi]
                add al, bl       ; AL = AL + BL 
                mov [d+esi], al  ; d[esi] = AL = s1[esi] + s2[esi]
                inc esi     
                inc esi          ; ESI = ESI + 2 ( pt. a lucra doar cu indicii pari ai sirurilor )
        loop RepetaPar           ; Sfarsit bucla pt. pozitii pare
        
        InvalidPar               ; ECX a fost invalid
        
        ; In acest punct vom avea sirul d = [  s1[0]+s2[0], 0, s1[2]+s2[2], 0, ...  ]
        
        ; Preconditii bucla pozitii impare
        mov cl , dl              ; Punem jumatatea lungimii sirurilor in ECX pentru a putea realiza a2a bucla loop ( pt. pozitiile impare )
        mov esi,  1              ; Vom folosi ESI pe post de indice ( in cea de a doua bucla ESI va fi 1, 3, ... )
        jecxz InvalidImpar       ; Daca lui ECX nu i-a fost atribuita o valoare, evitam bucla
     
        RepetaImpar:             ; Repeta bucla pt. pozitii pare de l/2 ori
                mov al, [s1+esi] ; AL = s1[esi]
                mov bl, [s2+esi] ; BL = s2[esi]
                sub al, bl       ; AL = AL - BL 
                mov [d+esi], al  ; d[esi] = AL = s1[esi] - s2[esi]
                inc esi
                inc esi          ; ESI = ESI + 2 ( pt. a lucra doar cu indicii impari ai sirurilor )
        loop RepetaImpar         ; Sfarsit bucla pt. pozitii impare
        
        InvalidImpar             ; ECX a fost invalid
        
        ; In acest punct vom avea sirul d = [  s1[0]+s2[0], s1[1]+s2[1], s1[2]+s2[2], s1[3]+s2[3], ...  ]
        
        push    dword 0     
        call    [exit]      
