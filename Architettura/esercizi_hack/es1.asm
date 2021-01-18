//D = RAM[1]
//D = D - RAM[0] - 2
//RAM[2] = D

    @1
    D = M
    @0
    D = D - M
    @2
    D = D - A
    M = D
(END)
    @END
    0;JMP