//Sahana Mundewadi and Noa Shadmon

#include <iostream>
using namespace std;

int main ()

{

  float f;

  cout << "Please enter a float: ";

  cin >> f;

  unsigned int mantissa, sign, power;
  unsigned int float_int = *((unsigned int*)&f); //ensures no 2's compliment
  int index = 22; //mantissa is a 23 bit unsigned int
  int last, bit, array[24] = {0}; //number is mantissa followed by 1 = 24

  mantissa = (float_int << 9) >> 9;
  power = (float_int >> 23) & (0xFF);
  sign = float_int  >> 31;

  while (mantissa > 0)
  {
    bit  = mantissa%2;
    mantissa = mantissa/2;
    array[index] = bit;
    index--;
  }

  for (int i = 22; i > 0; i--)
  {
    if (array[i] == 1)
    {
      last = i;
      break;
    }
  }

  if (f == 0)
    cout << "0E0" << endl;
  else
  {
    if (sign == 0)
      cout << "1.";
    else if (sign == 1)
      cout << "-1.";

    for (int i = 0; i <= last; i++)
      cout << array[i];

    cout << "E" << (power - 127) << endl;

  }

 return 0;

}
