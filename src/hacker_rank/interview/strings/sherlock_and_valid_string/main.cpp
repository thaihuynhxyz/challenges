#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s, unordered_map<char, int> ch_map = {}, unordered_map<int, int> c_map = {}) {
  for (const auto & c : s) ch_map[c]++;
  for (const auto & entry : ch_map) c_map[entry.second]++;
  if (c_map.size() == 1) return "YES";
  if (c_map.size() == 2) {
    auto first = (*c_map.begin()).first;
    auto second = (*next(c_map.begin(), 1)).first;
    auto c_min = min(first, second);
    auto c_max = max(first, second);
    if ((c_map[c_max] == 1 && c_max - c_min == 1) || (c_min == 1 && c_map[c_min] == 1))  return "YES";
  }
  return "NO";
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string s;
  getline(cin, s);

  auto result = isValid(s);

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

TEST_CASE("Test case 4", "[single-file]") {
  test_main("input04.txt", "result04.txt");

  auto output = read("output04.txt");
  auto result = read("result04.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 7", "[single-file]") {
  test_main("input07.txt", "result07.txt");

  auto output = read("output07.txt");
  auto result = read("result07.txt");

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
