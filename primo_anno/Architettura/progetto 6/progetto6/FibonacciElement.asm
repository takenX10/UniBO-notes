@256
D = A
@SP
M = D
@7
D = A
@SP
A = M
M = D
@SP
M = M + 1

@LABEL1
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@1
D = D - A
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@FibonacciElement.fibonacci
0;JMP
(LABEL1)

(WHILE)

@WHILE
0;JMP

(FibonacciElement.fibonacci)

@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1

@2
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
@LABEL2
D;JLT
@SP
A = M - 1
M = 0
@LABEL3
0;JMP
(LABEL2)
@SP
A = M - 1
M = -1
(LABEL3)

@SP
M = M - 1
A = M
D = M
@IF_TRUE
D;JGT

D;JLT

@IF_FALSE
0;JMP

(IF_TRUE)

@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1

@5
D = A
@LCL
A = M - D
D = M
@R13
M = D
@SP
A = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = M
@SP
M = D + 1
@LCL
D = M
@FRAME
M = D - 1
@FRAME
M = M - 1
@FRAME
M = M - 1
A = M
D = M
@ARG
M = D
@FRAME
M = M - 1
A = M
D = M
@LCL
M = D
@R13
A = M
0;JMP

(IF_FALSE)

@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1

@2
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

@LABEL4
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@1
D = D - A
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@FibonacciElement.fibonacci
0;JMP
(LABEL4)

@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1

@1
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

@LABEL5
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@1
D = D - A
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@FibonacciElement.fibonacci
0;JMP
(LABEL5)

@SP
M = M - 1
A = M
D = M
@SP
A = M - 1
M = D + M

@5
D = A
@LCL
A = M - D
D = M
@R13
M = D
@SP
A = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = M
@SP
M = D + 1
@LCL
D = M
@FRAME
M = D - 1
@FRAME
M = M - 1
@FRAME
M = M - 1
A = M
D = M
@ARG
M = D
@FRAME
M = M - 1
A = M
D = M
@LCL
M = D
@R13
A = M
0;JMP

