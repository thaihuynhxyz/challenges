#define CATCH_CONFIG_RUNNER

#include <algorithm>
#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
long solve(vector<int> arr) {
  long result = 0L;
  auto size = arr.size();
  stack<int> s;
  vector<long> r(size, -1);
  for (auto i = 0; i < size; i++) {
    if (s.empty()) {
      s.push(i);
      continue;
    }
    while (!s.empty() && arr[s.top()] < arr[i]) {
      r[s.top()] = i + 1;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  vector<long> l(size, -1);
  for (int i = size - 1; i >= 0; i--) {
    if (s.empty()) {
      s.push(i);
      continue;
    }
    while (!s.empty() && arr[s.top()] < arr[i]) {
      l[s.top()] = i + 1;
      s.pop();
    }
    s.push(i);
  }

  for (auto i = 0; i < size; i++) {
    if (l[i] != -1 && r[i] != -1) {
      result = max(result, l[i] * r[i]);
    }
  }
  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int arr_count;
  cin >> arr_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(arr_count);

  for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
    int arr_item = stoi(arr_temp[arr_itr]);

    arr[arr_itr] = arr_item;
  }

  auto result = solve(arr);

  fout << result << "\n";

  fout.close();
}

long read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  long result;
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

//TEST_CASE("Test case 2", "[single-file]") {
//  test_main("input02.txt", "result02.txt");
//
//  auto output = read("output02.txt");
//  auto result = read("result02.txt");
//
//  REQUIRE(result == output);
//}

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
