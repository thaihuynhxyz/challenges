#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
  vector<int> result;
  unordered_map<int, int> map;
  unordered_map<int, unordered_set<int>> reverse_map;
  for (const auto &query : queries) {
    auto data = query.back();
    switch (query.front()) {
      case 1:
        reverse_map[map[data]].erase(data);
        map[data]++;
        reverse_map[map[data]].emplace(data);
      break;
      case 2:
        if(map[data]) {
          reverse_map[map[data]].erase(data);
          map[data]--;
          reverse_map[map[data]].emplace(data);
        }
      break;
      case 3:
        result.emplace_back(reverse_map[data].empty() ? 0 : 1);
    }
  }
  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> queries;
  for (int i = 0; i < q; i++) {
    string s;
    getline(cin, s);
    auto queries_str = split_string(s);

    vector<int> query;
    for (const auto &query_str : queries_str) {
      query.emplace_back(stoi(query_str));
    }
    queries.emplace_back(query);
  }

  const auto results = freqQuery(queries);

  for (const auto & result : results) {
    fout << result << endl;
  }

  fout.close();
}

vector<int> read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());

  vector<int> result;
  while (true) {
    string str;
    getline(cin, str);
    if (str.empty()) break;

    result.push_back(stoi(str));
  }
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

TEST_CASE("Test case 2", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

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
