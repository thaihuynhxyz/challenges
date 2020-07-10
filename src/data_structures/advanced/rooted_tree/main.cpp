#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector<string> split_string(string);

const long NUMBER = 1000000007;

class RootedTree {
 private:
  vector<vector<int>> to;
  vector<int> level;
  vector<int> from;
  vector<pair<long, long>> values;

 public:
  int nodes_count;

  RootedTree(const int &n) {
    nodes_count = n;
    to = vector<vector<int>>(n);
    from = vector<int>(n, -1);
    level = vector<int>(n, 0);
    values = vector<pair<long, long>>(n, pair<long, long>(0, 0));
  }

  void add_edge(const int &x, const int &y) {
    to[x - 1].emplace_back(y - 1);
    to[y - 1].emplace_back(x - 1);
  }

  void set_root(const int &r) {
    set<int> visited;
    queue<int> queue;
    queue.push(r - 1);
    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();
      for (auto it : to[front]) {
        if (visited.emplace(it).second) {
          queue.push(it);
          level[it] = level[front] + 1;
          from[it] = front;
          to[it].erase(remove(to[it].begin(), to[it].end(), front));
        }
      }
    }
  }

  void update(const int &t, const long &v, const long &k) {
    auto value = values[t - 1];
    values[t - 1] = pair<long, long>(value.first + v, value.second + k);
  }

  long report(const int &a, const long &b) {
    long result = 0;
    auto aIndex = a - 1;
    auto bIndex = b - 1;
    auto aLevel = level[aIndex];
    auto bLevel = level[bIndex];
    auto aStartLevel = aLevel;
    auto bStartLevel = bLevel;
    while (aLevel > bLevel) {
      auto distance = aStartLevel - aLevel;
      auto value = values[aIndex];
      result += (value.first * (distance + 1) + value.second * distance * (distance + 1) / 2);
      aIndex = from[aIndex];
      aLevel--;
      result = result % NUMBER;
    }
    while (bLevel > aLevel) {
      auto distance = bStartLevel - bLevel;
      auto value = values[bIndex];
      result += (value.first * (distance + 1) + value.second * distance * (distance + 1) / 2);
      bIndex = from[bIndex];
      bLevel--;
      result = result % NUMBER;
    }

    while (aIndex != bIndex) {
      auto aDistance = aStartLevel - aLevel;
      auto aValue = values[aIndex];
      result += (aValue.first * (aDistance + 1) + aValue.second * aDistance * (aDistance + 1) / 2);
      aIndex = from[aIndex];
      aLevel--;

      auto bDistance = bStartLevel - bLevel;
      auto bValue = values[bIndex];
      result += (bValue.first * (bDistance + 1) + bValue.second * bDistance * (bDistance + 1) / 2);
      bIndex = from[bIndex];
      bLevel--;
      result = result % NUMBER;
    }

    auto endLevel = aLevel;

    while (aLevel != -1) {
      auto value = values[aIndex];

      auto distance = endLevel - aLevel;
      result += (value.first + value.second * distance);

      result += (value.first * (aStartLevel - endLevel)
          + value.second * (aStartLevel + endLevel + 1 - 2 * aLevel) * (aStartLevel - endLevel) / 2);
      result += (value.first * (bStartLevel - endLevel)
          + value.second * (bStartLevel + endLevel + 1 - 2 * aLevel) * (bStartLevel - endLevel) / 2);

      aIndex = from[aIndex];
      aLevel--;
      result = result % NUMBER;
    }
    return result;
  }
};

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int n, e, r;
  cin >> n >> e >> r;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  RootedTree tree(n);

  for (int i = 1; i < n; i++) {
    string xy;
    getline(cin, xy);
    auto params = split_string(xy);
    tree.add_edge(stoi(params[0]), stoi(params[1]));
  }

  tree.set_root(r);

  for (int i = 0; i < e; i++) {
    string query;
    getline(cin, query);
    auto params = split_string(query);
    if (params[0] == "U") {
      tree.update(stoi(params[1]), stol(params[2]), stol(params[3]));
    } else {
      fout << tree.report(stoi(params[1]), stoi(params[2])) % NUMBER << endl;
    }
  }
  fout.close();
}

long read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  long result;
  cin >> result;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return result;
}

TEST_CASE("Test case 0", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 1", "[single-file]") {
  test_main("input01.txt", "result01.txt");

  auto output = read("output01.txt");
  auto result = read("result01.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 9", "[single-file]") {
  test_main("input09.txt", "result09.txt");

  auto output = read("output09.txt");
  auto result = read("result09.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 15", "[single-file]") {
  test_main("input15.txt", "result15.txt");

  auto output = read("output15.txt");
  auto result = read("result15.txt");

  REQUIRE(result == output);
}

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
