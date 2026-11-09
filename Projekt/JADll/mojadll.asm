;.586
;INCLUDE C:\masm32\include\windows.inc 

.CODE
;-------------------------------------------------------------------------
; To jest przykładowa funkcja. 
;-------------------------------------------------------------------------
;parametry funkcji: RCX RDX R8 R9 stos, 
;lub zmiennoprzec.  XMM0 1 2 3
MyProc1 proc		
add RCX, 20
mov WORD PTR [RCX],12345
ret
MyProc1 endp

END 			;no entry point
;-------------------------------------------------------------------------
