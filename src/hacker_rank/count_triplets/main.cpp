#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
  long long ans = 0;
  unordered_map<long, long> map;
  unordered_map<long, long> pair_map;
  for (auto it = arr.rbegin(); it != arr.rend(); it++) {
    if (pair_map.count(*it * r)) ans += pair_map[*it * r];
    if (map.count(*it * r)) pair_map[*it] += map[*it * r];
    map[*it]++;
  }
  return ans;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int ar_count;
  cin >> ar_count;
  cin.ignore(numeric_limits<streamsize>::max(), ' ');

  int r;
  cin >> r;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<long> ar(ar_count);

  for (int i = 0; i < ar_count; i++) {
    auto ar_item = stol(ar_temp[i]);

    ar[i] = ar_item;
  }

  long result = countTriplets(ar, r);

  int test = result;

  fout << result << "\n";

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

TEST_CASE("Test case 2", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 3", "[single-file]") {
  test_main("input03.txt", "result03.txt");

  auto output = read("output03.txt");
  auto result = read("result03.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 6", "[single-file]") {
  test_main("input06.txt", "result06.txt");

  auto output = read("output06.txt");
  auto result = read("result06.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 10", "[single-file]") {
  test_main("input10.txt", "result10.txt");

  auto output = read("output10.txt");
  auto result = read("result10.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 12", "[single-file]") {
  test_main("input12.txt", "result12.txt");

  auto output = read("output12.txt");
  auto result = read("result12.txt");

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
