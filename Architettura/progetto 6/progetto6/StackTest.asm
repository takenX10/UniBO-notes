@256
D = A
@SP
M = D
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1

@17
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL1
D;JEQ
@SP
A = M - 1
M = 0
@LABEL2
0;JMP
(LABEL1)
@SP
A = M - 1
M = -1
(LABEL2)

@17
D = A
@SP
A = M
M = D
@SP
M = M + 1

@16
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL3
D;JEQ
@SP
A = M - 1
M = 0
@LABEL4
0;JMP
(LABEL3)
@SP
A = M - 1
M = -1
(LABEL4)

@16
D = A
@SP
A = M
M = D
@SP
M = M + 1

@17
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL5
D;JEQ
@SP
A = M - 1
M = 0
@LABEL6
0;JMP
(LABEL5)
@SP
A = M - 1
M = -1
(LABEL6)

@892
D = A
@SP
A = M
M = D
@SP
M = M + 1

@891
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL7
D;JLT
@SP
A = M - 1
M = 0
@LABEL8
0;JMP
(LABEL7)
@SP
A = M - 1
M = -1
(LABEL8)

@891
D = A
@SP
A = M
M = D
@SP
M = M + 1

@892
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL9
D;JLT
@SP
A = M - 1
M = 0
@LABEL10
0;JMP
(LABEL9)
@SP
A = M - 1
M = -1
(LABEL10)

@891
D = A
@SP
A = M
M = D
@SP
M = M + 1

@891
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL11
D;JLT
@SP
A = M - 1
M = 0
@LABEL12
0;JMP
(LABEL11)
@SP
A = M - 1
M = -1
(LABEL12)

@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1

@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL13
D;JGT
@SP
A = M - 1
M = 0
@LABEL14
0;JMP
(LABEL13)
@SP
A = M - 1
M = -1
(LABEL14)

@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1

@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL15
D;JGT
@SP
A = M - 1
M = 0
@LABEL16
0;JMP
(LABEL15)
@SP
A = M - 1
M = -1
(LABEL16)

@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1

@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
D = M - D
@LABEL17
D;JGT
@SP
A = M - 1
M = 0
@LABEL18
0;JMP
(LABEL17)
@SP
A = M - 1
M = -1
(LABEL18)

@57
D = A
@SP
A = M
M = D
@SP
M = M + 1

@31
D = A
@SP
A = M
M = D
@SP
M = M + 1

@53
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = D + M

@112
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = M - D

@SP
A = M - 1
M = -M

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = M&D

@82
D = A
@SP
A = M
M = D
@SP
M = M + 1

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = M|D

@SP
A = M - 1
M = !M

