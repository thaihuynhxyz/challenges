#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

int longestSubarray(vector<int> &nums, const int &limit) {
  multiset<int> s;
  auto l = nums.begin();
  auto r = nums.begin();
  int count = 0;
  int result = 0;
  while (r != nums.end()) {
    if (!s.empty() && (abs(*s.begin() - *r) > limit || abs(*prev(s.end()) - *r) > limit)) {
      result = max(result, count);
      int n = 0;
      if (*r < *s.begin()) {
        auto upper = s.upper_bound(*r + limit);
        while (upper != s.end()) {
          auto tmp = next(upper, s.count(*upper));
          n += s.erase(*upper);
          upper = tmp;
        }
        while (l != r && n > 0) {
          if (*l > *r + limit) n--;
          s.erase(*l);
          l++;
          count--;
        }
      } else {
        auto lower = s.lower_bound(*r - limit);
        auto e = s.begin();
        while (e != lower) {
          auto temp = next(e, s.count(*e));
          n += s.erase(*e);
          e = temp;
        }
        while (l != r && n > 0) {
          if (*l < *r - limit) n--;
          s.erase(*l);
          l++;
          count--;
        }
      }
    } else {
      s.insert(*r);
      r++;
      count++;
    }
  }
  result = max(result, count);
  return result;
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

  int result = longestSubarray(a, limit);

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

TEST_CASE("Test case 02", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 03", "[single-file]") {
  test_main("input03.txt", "result03.txt");

  auto output = read("output03.txt");
  auto result = read("result03.txt");

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