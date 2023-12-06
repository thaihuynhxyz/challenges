#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the compareTriplets function below.
vector<int> compareTriplets(vector<int> a, vector<int> b) {
  vector<int> result(2);

  for (auto i = 0; i < 3; i++) {
    if (a[i] > b[i]) {
      result[0]++;
    } else if (b[i] > a[i]) {
      result[1]++;
    }
  }
  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split(rtrim(a_temp_temp));

  vector<int> a(3);

  for (int i = 0; i < 3; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  string b_temp_temp;
  getline(cin, b_temp_temp);

  vector<string> b_temp = split(rtrim(b_temp_temp));

  vector<int> b(3);

  for (int i = 0; i < 3; i++) {
    int b_item = stoi(b_temp[i]);

    b[i] = b_item;
  }

  vector<int> result = compareTriplets(a, b);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

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

TEST_CASE("Test case 0", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 7", "[single-file]") {
  test_main("input07.txt", "result07.txt");

  auto output = read("output07.txt");
  auto result = read("result07.txt");

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
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
