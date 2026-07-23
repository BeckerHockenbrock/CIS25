#include <iostream>

using namespace std;

int main() {

  // added commad in between and ended in a semicolon
  float n1, n2, n3;

  cout << "Enter three numbers:";

  // need double arrows for both
  cin >> n1 >> n2 >> n3;

  // Compare n1 to n2 first (outer if) and replaced the single = with ==
  if (n1 >= n2) {
    // Nested inside: if n1 also beats n3, n1 is the largest
    if (n1 >= n3) {
      cout << "Largest number: " << n1;
    }
    // Otherwise n3 must be bigger than n1, and n1 was already >= n2, so n3 is
    // the largest
    else {
      cout << "Largest number: " << n3;
    }
  }
  // Otherwise n2 was bigger than n1
  else {
    // Nested inside: if n2 also beats n3, n2 is the largest
    if (n2 >= n3) {
      cout << "Largest number: " << n2;
    }
    // Otherwise n3 must be bigger than n2, and n2 was already > n1, so n3 is
    // the largest
    else {
      cout << "Largest number: " << n3;
    }
  }

  return 0;
}