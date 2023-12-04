#include <bits/stdc++.h>
#include "../helper/helper.h"

using namespace std;

int gameSetsPower(vector<string> gameSets) {
  unordered_map<string, int> minimumSetOfCubes;

  for(auto gameSet : gameSets) {
    for(auto part : split(gameSet, ',')) {
      part = part.substr(1);

      auto a = split(part, ' ');
      int numberOfCubes = stoi(a[0]);
      string color = a[1];

      if(minimumSetOfCubes.find(color) == minimumSetOfCubes.end()) {
        minimumSetOfCubes[color] = numberOfCubes;
      } else {
        minimumSetOfCubes[color] = max(numberOfCubes, minimumSetOfCubes[color]);
      }
    }
  }

  int powerSum = 1;

  for(auto p : minimumSetOfCubes) {
    int cubes = p.second;
    powerSum *= cubes;
  }

  return powerSum;
}

void solve(string fileLocation) {
  ifstream fin(fileLocation);

  int result = 0;
  string line;

  while(getline(fin, line)) {
    auto splitLine = split(line, ':');

    int gameId = stoi(split(splitLine[0], ' ')[1]);
    auto gameSets = split(splitLine[1], ';');

    result += gameSetsPower(gameSets);
  }

  cout << result << "\n";
}

int main() {  
  solve("./input.txt");
}
