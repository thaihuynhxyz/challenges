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
  vector<vector<int>> child;
  vector<int> root;
  vector<int> parent;
  vector<int> level;
  vector<pair<long, long>> values;

 public:
  explicit RootedTree(const int &n) {
    child = vector<vector<int>>(n);
    root = vector<int>(n, -1);
    parent = vector<int>(n, -1);
    level = vector<int>(n, 0);
    values = vector<pair<long, long>>(n, pair<long, long>(0, 0));
  }

  void add_edge(const int &x, const int &y) {
    child[x - 1].emplace_back(y - 1);
    child[y - 1].emplace_back(x - 1);
  }

  void set_root(const int &r) {
    set<int> visited;
    queue<int> queue;
    auto r_index = r - 1;
    queue.push(r_index);
    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();
      for (auto it : child[front]) {
        if (visited.emplace(it).second) {
          queue.push(it);
          root[it] = r_index;
          level[it] = level[front] + 1;
          parent[it] = front;

          auto front_index = remove(child[it].begin(), child[it].end(), front);
          child[it].erase(front_index);
        }
      }
    }
  }

  bool hasValue(const int &it) {
    auto value = values[it];
    return value.first || value.second;
  }

  void update(const int &t, const long &v, const long &k) {
    auto t_index = t - 1;
    auto value = values[t_index];
    auto just_update = value.first || value.second;
    values[t_index] = pair<long, long>(value.first + v, value.second + k);
    if (just_update) return;

    set<int> visited;
    queue<int> queue;
    queue.push(t_index);
    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();
      for (auto it : child[front]) {
        if (visited.emplace(it).second) {
          root[it] = t_index;
          if (!hasValue(it)) queue.push(it);
        }
      }
    }
  }

  long report(const int &a, const int &b) {
    long result = 0;
    auto aIndex = a - 1;
    auto bIndex = b - 1;
    auto aLevel = level[aIndex];
    auto bLevel = level[bIndex];
    auto aStartLevel = aLevel;
    auto bStartLevel = bLevel;

    result += values[a - 1].first;
    if (a != b) result += values[b - 1].first;
    result = result % NUMBER;

    // Find common root
    auto aRootIndex = root[aIndex];
    auto bRootIndex = root[bIndex];
    while (aRootIndex != bRootIndex) {
      auto aRootLevel = aRootIndex > -1 ? level[aRootIndex] : -1;
      auto bRootLevel = bRootIndex > -1 ? level[bRootIndex] : -1;
      if (aRootLevel > bRootLevel) {
        aIndex = aRootIndex;
        aLevel = aRootLevel;
        auto distance = aStartLevel - aLevel;
        auto value = values[aIndex];
        result += (value.first * (distance + (aIndex != bIndex)) + value.second * distance * (distance + 1) / 2);
        result = result % NUMBER;
      } else if (bRootLevel > aRootLevel) {
        bIndex = bRootIndex;
        bLevel = bRootLevel;
        auto distance = bStartLevel - bLevel;
        auto value = values[bIndex];
        result += (value.first * (distance + (aIndex != bIndex)) + value.second * distance * (distance + 1) / 2);
        result = result % NUMBER;
      } else {
        aIndex = aRootIndex;
        aLevel = aRootLevel;
        auto distance = aStartLevel - aLevel;
        auto value = values[aIndex];
        result += (value.first * (distance + (aIndex != bIndex)) + value.second * distance * (distance + 1) / 2);

        bIndex = bRootIndex;
        bLevel = bRootLevel;
        distance = bStartLevel - bLevel;
        value = values[bIndex];
        result += (value.first * (distance + (aIndex != bIndex)) + value.second * distance * (distance + 1) / 2);
        result = result % NUMBER;
      }
      aRootIndex = root[aIndex];
      bRootIndex = root[bIndex];
    }

    auto rootIndex = root[aLevel > bLevel ? aIndex : bIndex];
    if (rootIndex == -1 || !hasValue(rootIndex)) return result;

    while (aLevel > bLevel) {
      aIndex = parent[aIndex];
      aLevel--;
    }
    while (bLevel > aLevel) {
      bIndex = parent[bIndex];
      bLevel--;
    }
    while (aIndex != bIndex) {
      aIndex = parent[aIndex];
      aLevel--;
      bIndex = parent[bIndex];
      bLevel--;
    }
    auto endLevel = max(aLevel, bLevel);

    while (rootIndex != -1) {
      auto value = values[rootIndex];
      auto rootLevel = level[rootIndex];

      auto distance = endLevel - rootLevel;
      result += (value.first + value.second * distance);
      result += (value.first * (aStartLevel - endLevel)
          + value.second * (aStartLevel + endLevel + 1 - 2 * rootLevel) * (aStartLevel - endLevel) / 2);
      result += (value.first * (bStartLevel - endLevel)
          + value.second * (bStartLevel + endLevel + 1 - 2 * rootLevel) * (bStartLevel - endLevel) / 2);

      result = result % NUMBER;
      rootIndex = root[rootIndex];
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

vector<long> read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  vector<long> result;
  long element;
  while (cin >> element) result.push_back(element);
  return result;
}

TEST_CASE("Test case 00", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 01", "[single-file]") {
  test_main("input01.txt", "result01.txt");

  auto output = read("output01.txt");
  auto result = read("result01.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 09", "[single-file]") {
  test_main("input09.txt", "result09.txt");

  auto output = read("output09.txt");
  auto result = read("result09.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 15", "[single-file]") {
  test_main("input15.txt", "result15.txt");

  auto output = read("output15.txt");
  auto result = read("result15.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
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
