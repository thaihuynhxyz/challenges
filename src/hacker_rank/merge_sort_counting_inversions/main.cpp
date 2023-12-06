#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long countInversions(vector<int> arr) {
  long ans = 0;
  vector<int> temp;
  
  auto merge = [&](size_t l, size_t m, size_t r) {
    temp.resize(r - l);
    for (auto il = l, ir = m, i = 0UL; il < m || ir < r;) {
      if (il == m || (ir < r && arr[ir] < arr[il])) {
        if (il != m) {
          ans += m - il;
        }
        temp[i++] = arr[ir++];
      } else {
        temp[i++] = arr[il++];
      }
    }
    copy(temp.begin(), temp.end(), arr.begin() + l);
  };
  auto n = arr.size();
  for (size_t s = 1; s < n; s *=2) {
    for (size_t l = 0; l < n; l += 2 * s) {
      auto m = min(l + s, n - 1);
      auto r = min(m + s, n);
      merge(l, m, r);
    }
  }
  return ans;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < t; i++) {
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

    auto result = countInversions(ar);
    fout << result << endl;
  }

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

TEST_CASE("Test case 13", "[single-file]") {
  test_main("input13.txt", "result13.txt");

  auto output = read("output13.txt");
  auto result = read("result13.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 14", "[single-file]") {
  test_main("input14.txt", "result14.txt");

  auto output = read("output14.txt");
  auto result = read("result14.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 15", "[single-file]") {
  test_main("input15.txt", "result15.txt");

  auto output = read("output15.txt");
  auto result = read("result15.txt");

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
