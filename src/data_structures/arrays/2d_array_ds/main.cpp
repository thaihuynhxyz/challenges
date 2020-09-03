#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"
#include <iostream>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(const vector<vector<int>> &arr) {
  int ans = INT_MIN;
  vector<pair<int, int>> mask{make_pair(0, 0), make_pair(0, 1), make_pair(0, 2),
                                                     make_pair(1, 1),
                              make_pair(2, 0), make_pair(2, 1), make_pair(2, 2)};
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 4; j++) {
      auto value = accumulate(mask.begin(), mask.end(), 0, [arr, i, j](int sum, pair<int, int> mask) {
        return sum + arr[i + mask.first][j + mask.second];
      });
      ans = max(ans, value);
    }
  }
  return ans;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);

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

TEST_CASE("Test case 4", "[single-file]") {
  test_main("input04.txt", "result04.txt");

  auto output = read("output04.txt");
  auto result = read("result04.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 5", "[single-file]") {
  test_main("input05.txt", "result05.txt");

  auto output = read("output05.txt");
  auto result = read("result05.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 6", "[single-file]") {
  test_main("input06.txt", "result06.txt");

  auto output = read("output06.txt");
  auto result = read("result06.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 7", "[single-file]") {
  test_main("input07.txt", "result07.txt");

  auto output = read("output07.txt");
  auto result = read("result07.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 8", "[single-file]") {
  test_main("input08.txt", "result08.txt");

  auto output = read("output08.txt");
  auto result = read("result08.txt");

  REQUIRE(result == output);
}

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}
