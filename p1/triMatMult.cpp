// Sahana Mundewadi and Noa Shadmon

#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;


int getIndex(int, int, int);

int main (int argc, char * argv[])

{

  //int dim1 = 4, dim2 = 4;
  //int numZero = ((dim*dim) - dim)/2;
  //int size = ((dim * dim) - numZero);
  int size1, size2, dim1, dim2;

  ifstream inf(argv[1]);
  inf >> dim1; 
  size1 = (dim1 * (dim1 + 1))/2;

  int arr1[size1]; //= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int value;

  for (int a = 0; a < size1; a++)
  {
    inf >> value;
    //inf >> arr1[a];
    arr1[a] = value;
  }
  //inf.close();

  ifstream inf2(argv[2]);

  inf2 >> dim2;
  size2 = (dim2 * (dim2 + 1))/2;

  int arr2 [size2]; // = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //value = 0;

  for (int a = 0; a < size2; a++)
  {
    inf2 >> value;
    arr2[a] = value;
  }

  int num1 = 0, num2 = 0, ans = 0;

  for (int i = 0; i < dim1; i++)
  {
    for (int j = i; j < dim1; j++)
    {     
      ans  = 0;
      for (int k = i; k <= j; k++)
      {  
         num1 = arr1[getIndex(i, k, dim1)]; //row = i, column = j
         num2 = arr2[getIndex(k, j, dim1)];
         ans += num1 * num2;
      }
      //ans = num1 * num2;
      cout << ans << ' ';     
    } 

  }

  cout << endl;

  return 0; 

}   

    

int getIndex (int row, int column, int size)

{  
  //int numzeros = (row * (row + 1))/2;
  //return (row *size + column - numzeros);
  int whereYouAt = 0;
  for (int i = row; i >= 0; i--)
    whereYouAt = whereYouAt + i; 
  return (row * size + column - whereYouAt);

}
