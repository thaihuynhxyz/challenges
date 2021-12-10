#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"
#include <iostream>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */

int getMinEffort(const vector<vector<int>> &C) {
  auto height = C.size();
  auto width = C.back().size();
  vector<int> efforts(width * height, INT_MAX);
  unordered_set<int> visited;
  vector<int> ordered;
  ordered.emplace_back(0);
  visited.emplace(0);
  efforts[0] = 0;
  while (!ordered.empty()) {
    int top = ordered.back();
    ordered.pop_back();

    auto top_value = C[top / width][top % width];

    if (top == width * height - 1) return efforts[top];

    vector<int> directions;
    if (top % width > 0) directions.emplace_back(top - 1);
    if (top / width > 0) directions.emplace_back(top - width);
    if (top % width < width - 1) directions.emplace_back(top + 1);
    if (top / width < height - 1) directions.emplace_back(top + width);
    for (auto direction : directions) {
      auto effort = max(efforts[top], abs(C[direction / width][direction % width] - top_value));
      auto curr_effort = efforts[direction];
      if (visited.emplace(direction).second || curr_effort > effort) {

        int l = 0;
        int r = (int) ordered.size() - 1;
        while (l <= r) {
          auto m = l + (r - l) / 2;
          if (efforts[ordered[m]] == curr_effort) {
            for (auto i = m, j = m;
                 (i >= l && efforts[ordered[i]] == curr_effort) || (j <= r && efforts[ordered[j]] == curr_effort);
                 i--, j++) {
              if (ordered[i] == direction) {
                ordered.erase(ordered.begin() + i);
                break;
              }
              if (ordered[j] == direction) {
                ordered.erase(ordered.begin() + j);
                break;
              }
            }
            break;
          } else if (efforts[ordered[m]] > curr_effort) {
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        r = (int) ordered.size() - 1;
        while (l <= r) {
          auto m = l + (r - l) / 2;
          if (efforts[ordered[m]] == effort) {
            l = m;
            break;
          } else if (efforts[ordered[m]] > effort) {
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        while (l < ordered.size() && efforts[ordered[l]] == effort) l++;
        ordered.insert(ordered.begin() + l, direction);

        efforts[direction] = effort;
      }
    }
  }

  return efforts[width * height - 1];
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int m = stoi(first_multiple_input[1]);

  vector<vector<int>> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i].resize(m);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < m; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  int answer = getMinEffort(arr);

  fout << answer << "\n";

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

TEST_CASE("Test case 03", "[single-file]") {
  test_main("input03.txt", "result03.txt");

  auto output = read("output03.txt");
  auto result = read("result03.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 06", "[single-file]") {
  test_main("input06.txt", "result06.txt");

  auto output = read("output06.txt");
  auto result = read("result06.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 09", "[single-file]") {
  test_main("input09.txt", "result09.txt");

  auto output = read("output09.txt");
  auto result = read("result09.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 11", "[single-file]") {
  test_main("input11.txt", "result11.txt");

  auto output = read("output11.txt");
  auto result = read("result11.txt");

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