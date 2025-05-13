// LAB 1: Write a program to implement concept of strings
// a) Prefix    b)Suffix    c)Substring   d)Concatenation

#include <iostream>
#include <string>

using namespace std;

int main() {
  int input;
  string str1, str2;

  // Take input strings from the user
  cout << "Enter the first string: ";
  cin >> str1;
  cout << "Enter the second string: ";
  cin >> str2;

  cout << endl
       << "Choose the operation:" << endl
       << "1. Prefix" << endl
       << "2. Suffix" << endl
       << "3. Substring" << endl
       << "4. Concatenation" << endl
       << "5. Exit" << endl;

  while (1) {
    cout << "Enter your choice: ";
    cin >> input;

    switch (input) {
      case 1:
        // Prefix
        cout << endl
             << "Prefix of the first string: " << str1.substr(0, 2) << endl;
        cout << "Prefix of the second string: " << str2.substr(0, 2) << endl;
        break;
      case 2:
        // Suffix
        cout << endl
             << "Suffix of the first string: " << str1.substr(str1.length() - 2)
             << endl;
        cout << "Suffix of the second string: "
             << str2.substr(str2.length() - 2) << endl;
        break;
      case 3:
        // Substring
        cout << endl
             << "Substring of the first string: " << str1.substr(2, 2) << endl;
        cout << "Substring of the second string: " << str2.substr(2, 2) << endl;
        break;
      case 4:
        // Concatenation
        cout << endl
             << "Concatenation of the two strings: " << str1 + str2 << endl;
        break;
      case 5:
        cout << "Exiting Program! " << endl;
        exit(-1);
        break;
      default:
        cout << "Wrong Input!";
        break;
    }
  }
  return 0;
}