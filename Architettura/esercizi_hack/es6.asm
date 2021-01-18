// traccia una riga verticale da colonna 20 lunga 50px
@SCREEN
D = A
@address
M = D + 1
@counter
M = 0
(LOOP)
    @16
    D = A 
    @address
    A = M
    M = D
    @address
    D = M
    @32
    D = D+A
    @address
    M=D 
    @counter
    M = M + 1
    D = M
    @20
    D = A - D
    @LOOP
    D;JGT
(END)
@END
0;JMP
    