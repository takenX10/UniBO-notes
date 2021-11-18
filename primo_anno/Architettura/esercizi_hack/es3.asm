(LOOP)
    @1
    A = M
    M = 1
    @1
    M = M - 1
    D = M
    @0
    D = D - M
    @LOOP
    D;JGE
(END)
    @END
    0;JMP