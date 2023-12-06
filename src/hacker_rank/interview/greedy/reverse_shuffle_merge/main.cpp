#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s, array<int, 26> shuffle = {}, string ans = "") {
  auto index = [](char c) { return c - 'a'; };
  for (const auto &c : s) shuffle[index(c)]++;
  for (auto &i : shuffle) i /= 2;
  array<int, 26> reverse(shuffle);
  for (auto it = s.rbegin(); it != s.rend(); it++) {
    auto i = index(*it);
    if (!reverse[i]) {  // All reverses are appended to ans
      shuffle[i]--;
      continue;
    }
    while(auto last = ans.back()) {
      auto j = index(last);
      if (j > i && shuffle[j]) {
        shuffle[j]--;
        reverse[j]++;
        ans.pop_back();
      } else {
        break;
      }
    }
    ans += *it;
    reverse[i]--;
  }
  return ans;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string s;
  getline(cin, s);

  auto result = reverseShuffleMerge(s);

  fout << result << "\n";

  fout.close();
}

string read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  string result;
  getline(cin, result);
  return result;
}

TEST_CASE("Test case 0", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 2", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 15", "[single-file]") {
  test_main("input15.txt", "result15.txt");

  auto output = read("output15.txt");
  auto result = read("result15.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 16", "[single-file]") {
  test_main("input16.txt", "result16.txt");

  auto output = read("output16.txt");
  auto result = read("result16.txt");

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
