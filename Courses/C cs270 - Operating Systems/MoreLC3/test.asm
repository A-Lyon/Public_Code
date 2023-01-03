            .ORIG x3000
            AND R0, R0, #0        ; R0 = 0
            ADD R1, R0, #3       ; R1 = 3
INCR0       ADD R0, R0, #1        ; R0++
            LD  R2, INCR0         ; R2 = M[INCR0]
            ADD R2, R2, #1        ; R2++
            ST  R2, INCR0         ; M[INCR0] = R2
            ADD R1, R1, #-1       ; R1--
            BRp INCR0             ; If R1 > 0, GOTO: INCR0
            HALT
            .END

