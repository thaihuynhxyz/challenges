#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"
#include <unordered_set>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) {
    unordered_set<int> socks;
    auto result = 0;
    for (const auto &i : ar) {
        if (!socks.emplace(i).second) {
            result++;
            socks.erase(i);
        }
    }
    return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int ar_count;
  cin >> ar_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<int> ar(ar_count);

  for (int i = 0; i < ar_count; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  int result = sockMerchant(ar_count, ar);

  fout << result << "\n";

  fout.close();
}

long read(const string &filename) {
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
