// Sahana Mundewadi and Noa Shadmon

#include <stdio.h>

#include <stdlib.h>



int main (int argc, char * argv[])

{

  unsigned int dividend, divisor, remainder;

  unsigned int quotient = 0;

  unsigned int curr = 1;

  unsigned int result; 

 

  sscanf(argv[1], "%u", &dividend);

  if (dividend >= 2147483647)

    dividend = 2147483647;



  sscanf(argv[2], "%u", &divisor);

  if (divisor >= 2147483647)

    divisor = 2147483647;



  result = divisor;

  unsigned int save = dividend;



  if (result > dividend)

  {

     quotient = 0;

     remainder = dividend;

  }

 

  if (result == dividend)

  {

     quotient = 1;

     remainder = 0;

  }



  while (result <= dividend)

  {

    result <<= 1;

    curr <<= 1;

  }

  

  result >>= 1;

  curr >>= 1;



  while (curr != 0)

  {

    if (dividend >= result)

    {

      dividend -= result;

      quotient |= curr;

    }

    curr >>= 1;

    result >>= 1;

  }

  remainder = dividend;

     

  printf("%d / %d = %d R %d\n", save, divisor, quotient, remainder);



  return 0;

}
