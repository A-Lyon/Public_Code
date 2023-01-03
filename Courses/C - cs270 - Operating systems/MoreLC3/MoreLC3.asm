    ; Recitation MoreLC3
    ; Author: Andrew Lyon
    ; Date:   6/8/2021
    ; Email:  alyon@colostate.edu
    ; Class:  CS270
    ; Description: Mirrors least significant byte to most significant

                    .ORIG x3000

                    JSR mirror           ; call function
                    HALT


    ; Parameter and return value
    Param           .BLKW 1              ; space to specify parameter
    Result          .BLKW 1              ; space to store result
    ; R1 will hold result
    
        

    ; Constants
    One             .FILL #1             ; the number 1       
    Eight           .FILL #8             ; the number 8
    Mask            .FILL x00ff          ; mask top bits
    Mask2           .FILL xff00          ; mask bottom bits

    ;--------------------------------------------------------------------------
    mirror                               ; Mirrors bits 7:0 to 15:8
     
                                         ; ~20 lines of assembly code
     
                    LD R0, Param          ; load pattern
                                         ; your code here
                    .COPY R1, R0 

                    LD R2, Mask 
                    AND R1, R2, R1  ; keeps only last 2 digits in Param
                   
                    .ZERO R2       ; bottom bits
                    ADD R2, R2, R1                        
                    
                    LD R5, xFF03

                    .ZERO R3        ; top mask
                    LD R3, Mask2                     
  
  		    .ZERO R4         ;top bits
                    ADD R4, R4, R1                             
             
                    .ZERO R5      ;COUNTER 
                    ADD R5, R5, #8

                    Loop 
                       ADD R2, R2, R2
                       ADD R5, R5, #-1
                       BRp Loop

                    ADD R1, R2, R4  


                    ST R1,Result         ; store result
                    RET
    ;--------------------------------------------------------------------------
                   .END
