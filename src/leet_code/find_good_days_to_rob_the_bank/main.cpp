#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
  if (time == 0) {
    iota(security.begin(), security.end(), 0);
    return security;
  }
  vector<int> ans;
  auto n = security.size();
  vector<int> l(security.size(), 0);
  for (int i = n - 1; i > 1; --i) {
    if (security[i] >= security[i - 1]) {
      l[i - 1] = l[i] + 1;
    } else {
      l[i - 1] = 0;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (security[i] >= security[i + 1]) {
      if (min(l[i + 1], l[i] + 1) >= time) ans.emplace_back(i + 1);
      l[i + 1] = l[i] + 1;
    } else {
      l[i + 1] = 0;
    }
  }
  return ans;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string a_temp_temp;
  getline(cin, a_temp_temp);
  replace(a_temp_temp.begin(), a_temp_temp.end(), ',', ' ');
  replace(a_temp_temp.begin(), a_temp_temp.end(), '[', ' ');
  replace(a_temp_temp.begin(), a_temp_temp.end(), ']', ' ');
  vector<string> a_temp = split(ltrim(rtrim(a_temp_temp)));

  vector<int> a(a_temp.size());
  transform(a_temp.begin(), a_temp.end(), a.begin(), [](const auto &s) { return stoi(s); });

  string n_temp;
  getline(cin, n_temp);
  int limit = stoi(ltrim(rtrim(n_temp)));

  auto result = goodDaysToRobBank(a, limit);

  fout << "[";
  for (int i = 0; i < result.size(); i++) {
    fout << result[i];
    if (i < result.size() - 1) fout << ",";
  }
  fout << "]";

  fout.close();
}

string read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  string result;
  getline(cin, result);
  return result;
}

TEST_CASE("Test case 00", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 01", "[single-file]") {
  test_main("input01.txt", "result01.txt");

  auto output = read("output01.txt");
  auto result = read("result01.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 02", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 03", "[single-file]") {
  test_main("input03.txt", "result03.txt");

  auto output = read("output03.txt");
  auto result = read("result03.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 04", "[single-file]") {
  test_main("input04.txt", "result04.txt");

  auto output = read("output04.txt");
  auto result = read("result04.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 05", "[single-file]") {
  test_main("input05.txt", "result05.txt");

  auto output = read("output05.txt");
  auto result = read("result05.txt");

  REQUIRE(result == output);
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