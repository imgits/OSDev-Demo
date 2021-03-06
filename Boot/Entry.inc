;
; Boot/Entry.inc
;

                ORG             0000h

; On Entry, different BIOSes have different values for CS:IP.
; I want to use CS-relative addressing, so make sure CS is where I want it!
Boot.Entry:
                JMP             (BIOS.Entry>>4) : .Start ; Go to known location
.Start:
                XOR             AX,AX           ; Initialise the stack
                MOV             SS,AX           ; The BIOS's place is ludicrous
                MOV             SP,BIOS.Entry   ; So put SP somewhere sane
