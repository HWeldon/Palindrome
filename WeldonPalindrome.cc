/* WARNING */
// ENSURE THAT THE FILE CONTAINING
// THE NUMBERS TO BE CHECKED
// IS NAMED "numbers.txt"
/* WARNING */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool checkPalindrome(int x);

int main()
{
   bool isPalindrome;

   string line;
   ifstream file("numbers.txt");
   // open file and check to see if it opened correctly
   if(file.is_open())
   {
      // read file line by line
      while(getline(file, line))
      {
         // convert string to integer with stringstream from sstream
         stringstream ss(line);
         int i;
         ss >> i;

         // test for palindrome
         isPalindrome = checkPalindrome(i);
         if (isPalindrome == true)
         {
            cout << "YES" << endl;
         }
         else
         {
            cout << "NO" << endl;
         }
      }
      // after finishing operation close file
      file.close();
   }
   // if file cannot be opened
   else
   {
      cout << "File not able to be opened." << endl;
   }
   return 0;
}

bool checkPalindrome(int x)
{
    // division by 10 method
    int fileNumber = x, placeHolder = 0;
    do
    {
        placeHolder = placeHolder*10 + fileNumber%10;
    } while(fileNumber /= 10);

    return placeHolder == x;
}
