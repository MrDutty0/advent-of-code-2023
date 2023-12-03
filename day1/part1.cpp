#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("./input.txt");

  int sum = 0;

  string line;

  while(getline(fin, line)) {
    int num1 = -1;
    int num2;

    for(char sym : line) {
      if(isdigit(sym)) {
        if(num1 == -1) num1 = sym - '0';
        num2 = sym - '0';
      }
    }

    int number = num1 * 10 + num2;
    sum += number;
  }

  cout << sum << "\n";

  return 0;
}