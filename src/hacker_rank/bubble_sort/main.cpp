#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */

void countSwaps(vector<int> a, ofstream &fout) {
    auto ans = 0;
    for (auto i = a.rbegin(); i != a.rend(); i++) {
        auto sorted = true;
        for (auto j = a.begin(); j != i.base() - 1; j++) {
            if (*j > *(j + 1)) {
                iter_swap(j, j + 1);
                ans++;
                sorted = false;
            }
        }
        if (sorted) break;
    }
    fout << "Array is sorted in " << ans << " swaps." << endl;
    fout << "First Element: " << a.front() << endl;
    fout << "Last Element: " << a.back() << endl;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  countSwaps(ar, fout);

  fout.close();
}

vector<string> read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());

  vector<string> result;
  while (true) {
    string str;
    getline(cin, str);
    if (str.empty()) break;

    result.push_back(str);
  }
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