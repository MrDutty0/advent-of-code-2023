#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> getPossibleNumbers() {
  unordered_map<string, int> possibleNumbers = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
  };
  for(int i = 1; i <= 9; i++) {
    possibleNumbers[to_string(i)] = i;
  }

  return possibleNumbers;
}

int findFirstNumber(string line, unordered_map<string, int> possibleNumbers) {
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > foundStrings;

  for(const auto& pair : possibleNumbers) {
    string text = pair.first;
    size_t found = line.find(text);
    
    if(found != string::npos) foundStrings.push({found, possibleNumbers[text]});
  }

  return foundStrings.top().second;
}



int findLastNumber(string line, unordered_map<string, int> possibleNumbers) {
  priority_queue<pair<int, int>> foundStrings;

  for(const auto& pair : possibleNumbers) {
    string text = pair.first;
    size_t found = line.find(text);
    int lastInd = -1;

    while(found != string::npos) {
      lastInd = found;
      found = line.find(text, found + 1);
    }

    if(lastInd != -1) foundStrings.push({lastInd, possibleNumbers[text]});
  }

  return foundStrings.top().second;
}

int getNumber(string line, unordered_map<string, int> possibleNumbers) {
  int num1 = findFirstNumber(line, possibleNumbers);
  int num2 = findLastNumber(line, possibleNumbers);

  int number = num1 * 10 + num2;
  return number;
}

int main() {
  ifstream fin("./input.txt");

  int sum = 0;

  string line;

  const auto possibleNumbers = getPossibleNumbers();

  while(getline(fin, line)) {
    sum += getNumber(line, possibleNumbers);
  }

  cout << sum << "\n";

  return 0;
}