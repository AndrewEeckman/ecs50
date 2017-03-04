#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

string baseChange(unsigned int num, unsigned int newBase) 
{
  string result = " ";
  string newResult = " ";
  for (unsigned int i = num % newBase; num != 0; i = num % newBase)
  {
    num = num / newBase;
    if (i < 10)
      result += (char)('0' + i);
    else
      result += (char)('A' - 10 + i);
  }
  for (string::reverse_iterator itr = result.rbegin(); itr != result.rend(); ++itr)
    newResult += *itr;
		
  return newResult;

}

int main()
{
  char num[256] = "dummy";
  unsigned int currBase, newBase, newNum;
  int counter = 0; //converting num
  string num1;

  cout << "Please enter the number's base: ";
  cin >> currBase;

  cout << "Please enter the number: ";
  cin >> num;

  cout << "Please enter the new base: ";
  cin >> newBase;
	
  newNum = 0;
  while (num[counter] != '\0')
  {
    newNum = newNum * currBase;
    if (isdigit(num[counter]))
      newNum = newNum + num[counter] - '0';
    else if (isalpha(num[counter]))
      newNum = newNum + toupper(num[counter]) - 'A' + 10;
    else
      cout << "Non numeric or alphabetical character detected. Skipping " << num[counter] << endl;
    counter++;
  }

  cout << num << " base " << currBase << " is" << baseChange(newNum, newBase) << " base " << newBase << endl;
}
