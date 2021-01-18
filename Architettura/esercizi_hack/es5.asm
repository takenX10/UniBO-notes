// non considera caso /0 e 0/n
//RAM2 = RAM1 / RAM0, RAM3 = RAM1 mod RAM0
@2
M = 0
@1
D = M
@3
M = D
@0
D = M
(LOOP)
 @2
 M = M + 1      //RAM2 ++
 @0
 D = M
 @3
 M = M - D     //RAM3 += RAM0
 D = M
 @0
 D = D - M
 @LOOP
 D;JGT          //if RAM3 -RAM0 > 0 LOOP
(END)
 @END
 0;JMP
