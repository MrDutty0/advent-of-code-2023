#include <bits/stdc++.h>
#include "../helper/helper.h"

using namespace std;

unordered_map<string, int> gameRestrain = {
  {"red", 12},
  {"green", 13},
  {"blue", 14}
};

bool isCorrectGameSet(string gameSet) {
  for(auto part : split(gameSet, ',')) {
    part = part.substr(1);

    auto a = split(part, ' ');
    int numberOfCubes = stoi(a[0]);
    string color = a[1];

    if(numberOfCubes > gameRestrain[color]) return false;
  }
  return true;
}

bool areValidGameSets(vector<string> gameSets) {
  for(auto gameSet : gameSets) {
    if(!isCorrectGameSet(gameSet)) return false;
  }
  return true;
}

void solve(string fileLocation) {
  ifstream fin(fileLocation);

  int result = 0;
  string line;

  while(getline(fin, line)) {
    auto splitLine = split(line, ':');

    int gameId = stoi(split(splitLine[0], ' ')[1]);
    auto gameSets = split(splitLine[1], ';');

    if(areValidGameSets(gameSets)) result += gameId;
  }

  cout << result << "\n";
}

int main() {  
  solve("./input.txt");
}
