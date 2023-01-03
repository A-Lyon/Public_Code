; P5 Assignment
; Author: <Andrew Lyon>
; Date:   <6/9/2021>
; Email:  <alyon@colostate.edu>
; Class:  CS270
;
; Description: Implements the arithmetic, bitwise, and shift operations

;------------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000
                BR Main

Functions       .FILL IntAdd         ; Address of IntAdd routine     (option 0)
                .FILL IntSub         ; Address of IntSub routine     (option 1)
                .FILL IntMul         ; Address of IntMul routine     (option 2)
                .FILL BinaryOr       ; Address of BinaryOr routine   (option 3)
                .FILL LeftShift      ; Address of LeftShift routine  (option 4)
                .FILL RightShift     ; Address of RightShift routine (option 5)

Main            LEA R0,Functions     ; The main routine calls one of the 
                LD  R1,Option        ; subroutines below based on the value of
                ADD R0,R0,R1         ; the Option parameter.
                LDR R0,R0,0          ;
                JSRR R0              ;
EndProg         HALT                 ;

; Parameters and return values for all functions
; Try changing the .BLKW 1 to .FILL xNNNN where N is a hexadecimal value or #NNNN
; where N is a decimal value, this can save you time by not having to set these 
; values in the simulator every time you run your code. This is the only change 
; you should make to this section.
Option          .FILL #0             ; Which function to call
Param1          .BLKW 1              ; Space to specify first parameter
Param2          .BLKW 1              ; Space to specify second parameter
Result          .BLKW 1              ; Space to store result

; End reserved section: do not change ANYTHING in reserved section!
;------------------------------------------------------------------------------

; You may add variables and functions after here as you see fit.

;NegCheck       .FILL x8000

;Numbers
      ;  .ZERO R0
	    ;  .ZERO R1
	    ;  .ZERO R2
      ;  .ZERO R3
      ;  .ZERO R4 ;to store x8000
       
      ;  LD R0, Param1
       ; LD R1, Param2
       ; LD R4, NegCheck
        
       ; AND R3, R0, R4
       ; BRp TwosCompR0 
       ; .ZERO R3
        
       ; AND R3, R1, R4
       ; BRp TwosCompR1


;TwosCompR0
      ;  NOT R0, R0
      ;  ADD R0, R0, #1
      ;  RET
        
;TwosCompR1       
      ;  NOT R1, R1
      ;  ADD R1, R1, #1
      ;  RET

;TwosCompR2
      ;  NOT R2, R2
      ;  ADD R2, R2, #1
      ;  RET
        
;------------------------------------------------------------------------------
IntAdd                               ; Result is Param1 + Param2
                                     ; Your code goes here (~4 lines)
              
       ; BRnzp Numbers

        LD R0, Param1
        LD R1, Param2
        ADD R2, R0, R1
        ST R2, Result
        
RET
	            
         
		
		
;------------------------------------------------------------------------------
IntSub                               ; Result is Param1 - Param2
                                     ; Your code goes here (~6 lines)                         
                                     
        LD R0, Param1
        LD R1, Param2
        NOT R1, R1
        ADD R1, R1, #1    
        ADD R2, R0, R1 
        ST R2, Result                             
RET

;------------------------------------------------------------------------------
IntMul                               ; Result is Param1 * Param2

       
        LD R0, Param1
        .ZERO R2
        LD R1, Param2
     		
        
Loop    BRNZ LoopEnd
        ADD R2, R2, R0
        ADD R1, R1, #-1
        BRNZP Loop
LoopEnd ADD R2, R2, #0 
        ST R2 ,Result 

                                     ; Your code goes here (~9 lines)
                RET
;------------------------------------------------------------------------------
BinaryOr                             ; Result is Param1 | Param2
                                     ; Your code goes here (~7 lines)
        LD R0, Param1
        LD R1, Param2 
        
        NOT R0, R0
        NOT R1, R1
        AND R2, R0, R1
        NOT R2, R2 
                        
        ST R2 ,Result                            
                                     
                RET
;------------------------------------------------------------------------------
LeftShift                            ; Result is Param1 << Param2
                                     ; (Fill vacant positions with 0's)
                                     ; Your code goes here (~7 lines)
                LD R0, Param1
                LD R1, Param2
                
Loop2           BRnz Loop2End
                ADD R0, R0, R0
                ADD R1, R1, #-1
                BRp Loop2
Loop2End        ST R0, Result 
                                          
                RET
;------------------------------------------------------------------------------
RightShift                           ; Result is Param1(R0) >> Param2(R1)
                                     ; (Fill vacant positions with 0's)
                                     ; Your code goes here (~16 lines)
  
      LD R0, Param1    ;R0 param1, to be shifted 
      LD R1, Param2     ;R1 para2, how far to shift
     .ZERO R2          ;result 
     .ZERO R3          ;source mask
     .ZERO R4          ;place holder temp
     
     ADD R3, R3, #1
                      
loop3 
      ADD R3, R3, R3     ;loop to make initial mask
      ADD R1, R1, #-1
      BRp loop3  
            
      .ZERO R1             ;USE THIS AS DESTINATION MASK
      ADD R1, R1, #1  
      
loop4   
      AND R4, R3, R0       ;and first mask position with param1 (R0) if its a one BRp, if its a zero BRz      
      BRz Skiptie          ;bit is a 0, need to increment pointers to next
      ADD R2, R1, R2       ;BIT WAS A 1 SO WE ADD IT TO RESULT, by anding with R0 and destination mask
      
      Skiptie 
          ADD R3, R3, R3
          ADD R1, R1, R1      ;shift DESTINATION POINTER
          ;LD R0, Param1       ;reload param1 into R0 after K vs Source comparison - temp
          BRp Loop4
          
          
      ST R2, Result                            
                                     
                RET
;------------------------------------------------------------------------------
                .END
