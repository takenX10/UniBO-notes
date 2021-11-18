// RAM[2] = RAM[1] * (2^RAM[0])
// penso sia sbagliata per ram1 = 0
    @3
    M = 1
    @0
    D = M
    @PART2
    D;JEQ
(LOOP1)
    @3
    D = M
    M = D + M
    @0
    M = M - 1
    D = M
    @LOOP1
    D;JNE
(PART2)
    @2
    M=0 
(LOOP) 
    @1
    D=M 
    @2
    M=D+M 
    @3
    MD=M-1 
    @LOOP
    D;JGT
(END)
    @END
    0;JMP
    
