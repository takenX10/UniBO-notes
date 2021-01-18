// tracciare linea diagonale lunga 50px
// 2^(counter % 16) -> calcola il valore del byte da settare nello screen
// ogni volta che il mod e' 0 address = address + 1
@SCREEN
D = A
@address
M = D
@counter
M = 0
(LOOP)
    @counter
    D = M
    @0
    M = D
    @16
    D = D - A
    @MINORE         //if counter >= 16
    D;JLT
    (MOD)       // then counter % 16
        @16
        D = A
        @0
        D = M - D
        M = D
        @16
        D = D - A
        @MOD
        D;JGE
    @0
    D = M
    @MINORE         // if esponente == 0 then vai una colonna a destra
    D;JNE
    @address
    M = M + 1       
    (MINORE)    //continuo dei 2 if precedenti
    @1
    M = 1
    @0
    D = M
    @MINORE2
    D;JEQ       //  if RAM0 (l'esponente) != 0 then 2^RAM0
    (POW)
        @1
        D = M
        M = M + D
        @0
        M = M - 1
        D = M
        @POW
        D;JGT
    (MINORE2)   //continuo
    @1
    D = M
    @address
    A = M
    M = D   //disegna byte schermo
    @address
    D = M
    @32
    D = D + A   //scendi di una riga
    @address
    M = D
    @counter
    M = M + 1
    D = M       //counter++
    @50
    D = A - D
    @LOOP
    D;JGT
(END)
@END
0;JMP
