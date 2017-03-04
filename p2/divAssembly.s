.globl _start

.data

dividend:
  .long 0

divisor:
  .long 0
#variables to store my constants
max: .long 2147483647
a: .long 0
b: .long 1

.text

 
_start:
  #initialize, moves the stuff into right register
  movl divisor, %ebx 
  movl divisor, %edi #copy so dont lose the data
  movl dividend, %eax 
  movl dividend, %edx #copy so dont lose the data
  shrl $1, %edx #shifts the dividend left
  movl $1, %ecx #ecx = 1
 
  jmp comparisons 
  
 
  rearrange:
    shll $1, %ebx #shifts divisor by 1
    shll $1, %ecx #shift ecx 1 
  
   comparisons:
    cmpl %edx, %ebx #is the shifted dividended greater than the divisor?
    jb rearrange  #if it is then jump 
    movl $0, %edx #edx is now set to 0
    movl $0, %esi #esi is also 0 
  

  jmp comparison2 #check conditions for second while loop

  rearrange2:
    #need to check if dividended - divisor is greater/equal to 0
    cmpl %ebx, %eax #if dividended is greater/equal to divisor
    jb nextChar 
    subl %ebx, %eax #subtract divisor from dividend
    addl %ecx, %edx #add the two together holla 

    nextChar:
      shrl $1, %ecx #
      shrl $1, %ebx #divisor is shifted by 1

  #if (result > dividend)
    #equiv to if (0 > dividend - result)
     #quotient = 0, remainder = dividend

  comparison2:
    cmpl %esi, %ecx 
    ja rearrange2 
  
  cmpl %eax, %edi #subtract edi - eax 
  ja nextChar2  
    subl %edi, %eax #subtract the saved version
    incl %edx  
   
  nextChar2:
    movl %eax, %esi 
    movl %edx, %eax   
    movl %esi, %edx 

  
done: movl %eax, %eax
