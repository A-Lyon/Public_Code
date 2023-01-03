; Begin reserved section: do not change ANYTHING in reserved section!
; The ONLY exception to this is that you MAY change the .FILL values for
; Option, Value1 and Value2. This makes it easy to initialize the values in the
; program, so that you do not need to continually re-enter them. This
; makes debugging easier as you need only change your code and re-assemble.
; Your test value(s) will already be set.
;------------------------------------------------------------------------------
; Author: Fritz Sieker
;
; Description: Tests the implementation of a simple string library and I/O
;

            .ORIG x3000
            BR Main
Functions
            .FILL Test_pack         ; (option 0)
            .FILL Test_unpack       ; (option 1)
            .FILL Test_printCC      ; (option 2)
            .FILL Test_strlen       ; (option 3)
            .FILL Test_strcpy       ; (option 4)
            .FILL Test_strcat       ; (option 5)
            .FILL Test_strcmp       ; (option 6)

; Parameters and return values for all functions
Option      .FILL 0                 ; which function to call
String1     .FILL x4000             ; default location of 1st string
String2     .FILL x4100             ; default location of 2nd string
Result      .BLKW 1                 ; space to store result
Value1      .FILL 0                 ; used for testing pack/unpack
Value2      .FILL 0                 ; used for testing pack/unpack
lowerMask   .FILL 0x00FF            ; mask for lower 8 bits
upperMask   .FILL 0xFF00            ; mask for upper 8 bits

Main        LEA R0,Functions        ; get base of jump table
            LD  R1,Option           ; get option to use, no error checking
            ADD R0,R0,R1            ; add index of array
            LDR R0,R0,#0            ; get address to test
            JMP R0                  ; execute test

Test_pack   
            LD R0,Value1            ; load first character
            LD R1,Value2            ; load second character
            JSR pack                ; pack characters
            ST R0,Result            ; save packed result
End_pack    HALT                    ; done - examine Result

Test_unpack 
            LD R0,Value1            ; value to unpack
            JSR unpack              ; test unpack
            ST R0,Value1            ; save upper 8 bits
            ST R1,Value2            ; save lower 8 bits
End_unpack  HALT                    ; done - examine Value1 and Value2

Test_printCC    
            LD R0,Value1            ; get the test value
            .ZERO R1                ; reset condition codes
            JSR printCC             ; print condition code
End_printCC HALT                    ; done - examine output

Test_strlen 
            LD R0,String1           ; load string pointer
            GETS                    ; get string
            LD R0,String1           ; load string pointer
            JSR strlen              ; calculate length
            ST R0,Result            ; save result
End_strlen  HALT                    ; done - examine memory[Result]

Test_strcpy 
            LD R0,String1           ; load string pointer
            GETS                    ; get string
            LD R0,String2           ; R0 is dest
            LD R1,String1           ; R1 is src
            JSR strcpy              ; copy string
            PUTS                    ; print result of strcpy
            NEWLN                   ; add newline
End_strcpy  HALT                    ; done - examine output

Test_strcat 
            LD R0,String1           ; load first pointer
            GETS                    ; get first string
            LD R0,String2           ; load second pointer
            GETS                    ; get second string
            LD R0,String1           ; dest is first string
            LD R1,String2           ; src is second string
            JSR strcat              ; concatenate string
            PUTS                    ; print result of strcat
            NEWLN                   ; add newline
End_strcat  HALT                    ; done - examine output

Test_strcmp 
            LD R0,String1           ; load first pointer
            GETS                    ; get first string
            LD R0,String2           ; load second pointer
            GETS                    ; get second string
            LD R0,String1           ; dest is first string
            LD R1,String2           ; src is second string
            JSR strcmp              ; compare strings
            JSR printCC             ; print result of strcmp
End_strcmp  HALT                    ; done - examine output

;------------------------------------------------------------------------------
; End of reserved section
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; on entry R0 contains first value, R1 contains second value
; on exit  R0 = (R0 << 8) | (R1 & 0xFF)

pack        ; fill in your code, ~11 lines of code
            


            
            .ZERO R3
            LD R3, lowermask
            AND R1, R1, R3  ;get lower two bits USING LOWER MASK R3. 
            
            .ZERO R2
            ADD R2, R2, #8
            
            
           
Loop1         
            ADD R0, R0, R0
            ADD R2, R2, #-1
            BRp Loop1          ;loop for building mask
            
            
            NOT R0, R0
            NOT R1, R1
            AND R0, R0, R1 
            NOT R0, R0

            RET

;------------------------------------------------------------------------------
; on entry R0 contains a value
; on exit  (see instructions)

unpack      ; fill in your code, ~14 lines of code

            .ZERO R3
            LD R3, lowerMask  ;prepare mask with R3
            AND R1, R0, R3   ; save lower bits initial R0 into R1
            .ZERO R3
            ST R1, Value2    ; save R1 into memory value2
            .ZERO R1
            
            LD R2, upperMask    ; prep top mask 
            AND R0, R0, R2      ; save top bits 
            .ZERO R2
            
            ADD R2, R2, #8     ; PREP COUNTER
            ADD R3, R3, #1     ;PREP SOURCE MASK
            .ZERO R4
            ADD R4, R4, #1     ;CLEAR AND PREP DESTINATION MASK
            
Loop2                 ;set up left shift loop
            ADD R3, R3, R3
            ADD R2, R2, #-1
            BRp Loop2
            
            .ZERO R2          ;gonna need that counter again mothaFudger
            ADD R2, R2, #8
            
Shift       
            AND R1, R0, R3
            BRz iterate          ;if 0 go to iterate
            ADD R0, R0, R4

Iterate
            ADD R3, R3, R3   ;right shift
            ADD R4, R4, R4
            ADD R2, R2, #-1       
            BRz end
            BRnzp Shift    ;keep shifting if we aint done fool!
            
end         LD R2, lowerMask
            AND R0, R0, R2
            LD R1, Value2     
            
            
            
            


            RET

;------------------------------------------------------------------------------
; on entry R0 contains value
; on exit  (see instructions)

StringNEG   .STRINGZ "NEGATIVE\n"   ; output strings
StringZERO  .STRINGZ "ZERO\n"
StringPOS   .STRINGZ "POSITIVE\n"

printCC     ; fill in your code, ~11 lines of code
            
            
            ST R7, Value1      ; preparE R7
            ADD R0, R0, #0   
            BRn NEG               
            BRz ZERO            
            BRp POS             

 NEG         
            LEA R0, StringNEG   
            PUTS                  
            BRnzp done
            
 ZERO         
            LEA R0, StringZERO    
            PUTS                  
            BRnzp done            

 POS         
            LEA R0, StringPOS   
            PUTS 
                  
            
 done     
          LD R7, Value1         
            
            RET


;------------------------------------------------------------------------------
; size_t strlen(char *s)
; on entry R0 points to string
; on exit  (see instructions)

strlen      ; fill in your code, ~7 lines of code
            .ZERO R1
            
LoopL    LDR R2, R0, #0
           BRz endLoopL           ;if R2=0 at end of string
           ADD R1, R1, #1         ;LENGTH 
           ADD R0, R0, #1         ; adress counter
           BRnzp LoopL

endLoopL  .ZERO R0
          add R0, R1, #0  ;store length into R0 from R1
          RET
           
    

            RET

;------------------------------------------------------------------------------
; char *strcpy(char *dest, char *src)
; on entry R0 points to destination string, R1 points to source string
; on exit  (see instructions)

strcpy      ; fill in your code, ~8 lines of code

LoopStrC
            LDR R2, R1, #0      ;load char from R1 into R2
            STR R2, R0, #0      ; store address
            Brz endLoopSt       ;if 0, stored
            ADD R0, R0, #1      ; ++R0
            ADD R1, R1, #1      ; ++R1
            BRnzp LoopStrC 
            
endLoopSt   LD R0, String2      ;put string2 into R0    
            
            RET
            

;------------------------------------------------------------------------------
; char *strcat(char *dest, char *src)
; on entry R0 points to destination string, R1 points to source string
; on exit  (see instructions)

strcat_RA   .BLKW 1                 ; space for return address
strcat_dest .BLKW 1                 ; space for dest
strcat_src  .BLKW 1                 ; space for src

strcat      ST R7,strcat_RA         ; save return address
            ST R0,strcat_dest       ; save dest
            ST R1,strcat_src        ; save src

            ; fill in your code, ~5 lines of code
            ; HINT: call strlen and strcpy
            
            JSR strlen              ; get length
            ADD R2, R2, R0          ; 
            LD R0, strcat_dest      ; R0 = str1
            LD R1, strcat_src       ; R1 = str2
            ADD R0, R0, R2          ; move pointer 
            JSR strcpy              ; copies str2 into the end of str1
            

            LD R0, strcat_dest       ; restore dest
            LD R7, strcat_RA         ; restore return address
            RET

;------------------------------------------------------------------------------
; int strcmp(char *s1, char *s2)
; on entry R0 points to first string, R1 points to second string
; on exit  (see instructions)

strcmp      ; fill in your code, ~12 lines of code

            LDR R2, R0, #0            ; LD from R0 
            LDR R3, R1 ,#0            ; LD from R1 
            ADD R4, R3, R2            ; check if both chars are null (
            BRz exitStrCmp
            NOT R3, R3                ;if not null, take two's comp
            ADD R3, R3, #1            
            ADD R4, R3, R2            ; subtracts from each other
            BRnp exitStrCmp           ; if difference, break loop
            ADD R0, R0, #1            ; ++R0 
            ADD R1, R1, #1            ; ++R1 
            
            
exitStrCmp
            .ZERO R0                
            ADD R0,R0,R4            ; return R4 in R0
            RET

;------------------------------------------------------------------------------
            .END
