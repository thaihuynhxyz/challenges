#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

bool replaceString(std::string &, const std::string &, const std::string &);

int minOperations(vector<vector<int>>& grid, int x) {
  std::vector<int> v;

  for (const auto & row : grid) {
    for (const auto & value : row) {
      v.push_back(value);
    }
  }
  sort(v.begin(), v.end());
  
  auto uni = v[v.size() / 2];
  auto result = 0;
  for (const auto & value : v) {
    auto diff = abs(value - uni);
    if (diff % x) return -1;
    result += (diff / x);
  }
  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string a_temp_temp;
  std::getline(cin, a_temp_temp);
  replaceString(a_temp_temp, "[[", " ");
  replaceString(a_temp_temp, "]]", " ");
  replaceString(a_temp_temp, "],[", " ");
  vector<string> a_temp = split(ltrim(rtrim(a_temp_temp)));

  vector<vector<int>> a(a_temp.size());
  transform(a_temp.begin(), a_temp.end(), a.begin(), [](auto &s) { 
    replace(s.begin(), s.end(), ',', ' ');
    vector<string> s_temp = split(ltrim(rtrim(s)));
    vector<int> v(s_temp.size());
    transform(s_temp.begin(), s_temp.end(), v.begin(), [](const auto &i) { return stoi(i); });
    return v; 
  });

  string n_temp;
  getline(cin, n_temp);
  int limit = stoi(ltrim(rtrim(n_temp)));

  int result = minOperations(a, limit);

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