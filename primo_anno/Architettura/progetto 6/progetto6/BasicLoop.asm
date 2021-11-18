@256
D = A
@SP
M = D
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1

@0
D = A
@LCL
D = M + D
@5
M = D
@SP
M = M - 1
A = M
D = M
@5
A = M
M = D

(LOOP_START)

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

@0
D = A
@LCL
A = M + D
D = M
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

@0	
D = A
@LCL
D = M + D
@5
M = D
@SP
M = M - 1
A = M
D = M
@5
A = M
M = D

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

@0
D = A
@ARG
D = M + D
@5
M = D
@SP
M = M - 1
A = M
D = M
@5
A = M
M = D

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

@SP
M = M - 1
A = M
D = M
@LOOP_START
D;JGT

D;JLT

@0
D = A
@LCL
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1

