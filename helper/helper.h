#include <bits/stdc++.h>

using namespace std;

vector<string> split(string line, char del) {
  stringstream ss(line);
  
  vector<string> splittedSets;

  string subSet;

  while(!ss.eof()) {
    getline(ss, subSet, del);
    splittedSets.push_back(subSet);
  }
  return splittedSets;
}