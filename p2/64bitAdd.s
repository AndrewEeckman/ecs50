
.global _start

.data
  num1:
    n1_upper: #lower 32 bits
      .long -1
    n1_lower: #upper 32 bits
      .long 12
  num2:
    n2_upper: #lower 32 bits
      .long 255
    n2_lower: #upper 32 bits
      .long 7

.text
_start:
  
  #stores lower and upper parts into respective register
  movl n1_upper, %edx
  movl n1_lower, %eax

  #adds the lowers together
  addl n2_lower, %eax

  #if theres a carry add 1
  jnc didnt_exist
    addl $1, %edx #must add 1 to the upper if there is a carry

  #if no carry then add the uppers!
  didnt_exist:
    addl n2_upper, %edx

  #allows for gdb
  done:
    addl %eax, %eax 
 
