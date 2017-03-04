
.equ wordsize, 4
.global _start

.data 
string1:
  .space 100
string2:
  .space 100
string1Len:
  .long 0
string2Len:
  .long 0
oldDist:
  .space wordsize * 100
currentDist:
  .space wordsize * 100

.text

#this initializes the beginning distance and stores the length of string2
#ecx is the count, edi is the pointer to the starting distance
beginning:
  movl $0, %ecx
  movl $oldDist, %edi

  oldDistance:
    cmpb $0, string2(%ecx)
    jz endOld
    movl %ecx, (%edi, %ecx, wordsize)
    incl %ecx
    jmp oldDistance
  endOld:
    movl %ecx, (%edi, %ecx, wordsize)
    movl %ecx, string2Len
    ret

#esi is the pointer to current distance and edi is the pointer to old distance
#ecx is the counter
#this updates the current distance
copy:
  movl $currentDist, %esi
  movl $oldDist, %edi
  movl string2Len, %ecx
  incl %ecx
  rep movsl
  ret  

#this finds the minimum of the esi, edi, ebp
min:
  comparison1:
    cmpl %esi, %edi
    jge comparison2
    movl %edi, %esi
  comparison2:
    cmpl %esi, %ebp
    jge woo
    movl %ebp, %esi
  woo:
    ret

_start:
  #eax = i
  #j = ebx
  #ecx = temp
  call beginning 

  movl $1, %eax
  outerLoop:
    cmpb $0, (string1 - 1)(%eax)
    jz endOuterLoop

    movl %eax, currentDist
    movl $1, %ebx
    innerLoop:
      cmpb $0, (string2 - 1)(%ebx)
      jz endInnerLoop
      movb (string2 - 1)(%ebx), %cl
      cmpb (string1 - 1)(%eax), %cl
      jnz differentChar
      sameChar:
        movl (oldDist - wordsize)(, %ebx, wordsize), %ecx
        movl %ecx, currentDist(, %ebx, wordsize)
        jmp end
      endSame:
      differentChar:
        movl oldDist(, %ebx, wordsize), %esi
        movl (currentDist - wordsize)(, %ebx, wordsize), %edi
        movl (oldDist - wordsize)(, %ebx, wordsize), %ebp
        call min
        incl %esi
        movl %esi, currentDist(, %ebx, wordsize)
      end:
        incl %ebx
        jmp innerLoop
    endInnerLoop:
    call copy
    incl %eax
    jmp outerLoop
  endOuterLoop:
    movl (currentDist - wordsize)(, %ebx, wordsize), %eax
  done: movl %eax, %eax
