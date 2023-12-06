#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
  auto start = 0;
  auto end = 0;
  auto summing = 0;
  auto result = 0;

  while (end < m) summing += s[end++];
  if (summing == d) result++;

  auto size = s.size();
  while (end < size) {
    summing += (s[end++] - s[start++]);
    if (summing == d) result++;
  }

  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string s_temp_temp;
  getline(cin, s_temp_temp);

  vector<string> s_temp = split(rtrim(s_temp_temp));

  vector<int> s(n);

  for (int i = 0; i < n; i++) {
    int s_item = stoi(s_temp[i]);

    s[i] = s_item;
  }

  string dm_temp;
  getline(cin, dm_temp);

  vector<string> dm = split(rtrim(dm_temp));

  int d = stoi(dm[0]);

  int m = stoi(dm[1]);

  int result = birthday(s, d, m);

  fout << result << "\n";

  fout.close();
}

int read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  int result;
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
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
