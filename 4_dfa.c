

/* LAB 4: Write a program to implement DFA that accepts strings with even number
of '0' & odd number of '1' over alphabet Σ = {0,1}

Transition Table:

        Input
State |_0_|_1_|
 → p  | q | f |
   q  | p | r |
   r  | f | q |
 * f  | r | p |  

Program */
#include <iostream>
#include <string>

using namespace std;
enum state { p = 0, q, r, f };

int main() {
  // Declaring variables
  state s;
  int i;
  string str;

  // Input
  cout << "Enter the string: " << endl;
  getline(cin >> ws, str);

  //   Checking the accepting condition in each state
  for (i = 0; str[i] != '\0'; i++) {
    switch (s) {
      case p:
        // If the string reaches state p
        if (str[i] == '0') {
          s = q;
        } else {
          s = f;
        }
        break;
      case q:
        // If the string reaches state q
        if (str[i] == '0') {
          s = p;
        } else {
          s = r;
        }
        break;
      case r:
        // If the string reaches state r
        if (str[i] == '0') {
          s = f;
        } else {
          s = q;
        }
        break;
      case f:
        // If the string reaches state f (final state)
        if (str[i] == '0') {
          s = r;
        } else {
          s = p;
        }
        break;
      default:
        cout << "Wrong Input!";
        break;
    }
  }

  //   Checking the accepting state
  if (s == f) {
    cout << "String Accepted!" << endl;
  } else {
    cout << "String not Accepted!" << endl;
  }
  return 0;
}