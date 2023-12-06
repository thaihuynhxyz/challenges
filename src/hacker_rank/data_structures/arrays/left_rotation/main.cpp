#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"
#include <iostream>

using namespace std;

vector<string> split_string(string);

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  auto step = d % n;
  for (int i = step; i < n; i++) fout << a[i] << " ";
  for (int i = 0; i < step; i++) fout << a[i] << " ";

  fout.close();
}

vector<int> read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  vector<int> result;
  int element;
  while (cin >> element) {
    result.push_back(element);
  }
  return result;
}

TEST_CASE("Test case 0", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
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
