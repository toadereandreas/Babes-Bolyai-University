bits 32
global VerifyChar

segment code use32 class = code
VerifyChar:
    mov eax,[esp+4]
    
            cmp al,0Ah
            je Set0
            
            cmp al,  97 ;30h
            jb Set1
            cmp al, 122 ;39h
            ja Set1
            
            mov [esp+4],dword(2)
            ret
            Set0:
            mov [esp+4],dword(0)
            ret
            Set1:
            mov [esp+4],dword(1)
            ret