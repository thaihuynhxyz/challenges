#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

bool replaceString(std::string &, const std::string &, const std::string &);

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  auto dx = min(ax2, bx2) - max(ax1, bx1);
  auto dy = min(ay2, by2) - max(ay1, by1);
  auto a = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1);
  if (dx <= 0 || dy <= 0) return a;
  return a - dx * dy;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string str;
  std::getline(cin, str);
  auto ax1 = stoi(str);
  std::getline(cin, str);
  auto ay1 = stoi(str);
  std::getline(cin, str);
  auto ax2 = stoi(str);
  std::getline(cin, str);
  auto ay2 = stoi(str);
  std::getline(cin, str);
  auto bx1 = stoi(str);
  std::getline(cin, str);
  auto by1 = stoi(str);
  std::getline(cin, str);
  auto bx2 = stoi(str);
  std::getline(cin, str);
  auto by2 = stoi(str);

  int result = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

  fout << result << "\n";

  fout.close();
}

vector<int> read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  vector<int> result;
  int element;
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

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
  );

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end()
  );

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end;

  while ((end = str.find(' ', start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

bool replaceString(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}