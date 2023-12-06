#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
int solution(vector<int> &A) {
  cout << A.size();
  auto size = A.size();
  auto vec = A;
  auto temp = 0;
  for (size_t i = 1; i < size; i++) {
    temp = (temp + A[i - 1]) / 2;
    vec[i] += temp;
  }

  temp = 0;
  for (size_t i = size - 1; i--;) {
    temp = (temp + A[i + 1]) / 2;
    vec[i] += temp;
  }
  
  auto maxIt = std::max_element(std::begin(vec), std::end(vec));
  return *maxIt;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(arr_temp.size());

  for (int i = 0; i < arr_temp.size(); i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  auto result = solution(arr);
  fout << result;

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

// TEST_CASE("Test case 14", "[single-file]") {
//   test_main("input14.txt", "result14.txt");

//   auto output = read("output14.txt");
//   auto result = read("result14.txt");

//   REQUIRE(result.size() == output.size());
//   for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
// }

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
