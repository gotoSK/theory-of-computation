/* LAB 2: Write a program to implement DFA that accepts strings ending with 01
over alphabet Σ = {0,1}

Transition Table:

        Input
State |_0_|_1_|
  p   | q | p |
  q   | q | r |
  r   | q | p |

Program */
#include <iostream>
// #include <string>

using namespace std;
enum state { p = 0, q, r };

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
        // If the string reaches p
        if (str[i] == '0') {
          s = q;
        } else {
          s = p;
        }
        break;
      case q:
        // If the string reaches q
        if (str[i] == '0') {
          s = q;
        } else {
          s = r;
        }
        break;
      case r:
        // If the string reaches r
        if (str[i] == '0') {
          s = q;
        } else {
          s = p;
        }
        break;
      default:
        break;
    }
  }

  //   Checking the accepting state
  if (s == r) {
    cout << "String Accepted!" << endl;
  } else {
    cout << "String not Accepted!" << endl;
  }
  return 0;
}