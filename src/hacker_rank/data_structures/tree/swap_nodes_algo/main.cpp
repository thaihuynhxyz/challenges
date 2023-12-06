#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"
#include <queue>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
  vector<vector<int>> result(queries.size());
  vector<int> level(indexes.size(), 1);
  queue<int> queue;
  queue.push(1);
  auto max_level = 1;
  while (!queue.empty()) {
    auto front_index = queue.front() - 1;
    queue.pop();
    auto next_level = level[front_index] + 1;

    auto left = indexes[front_index].front();
    auto right = indexes[front_index].back();
    if (left != -1) {
      queue.push(left);
      level[left - 1] = next_level;
      max_level = max(max_level, next_level);
    }
    if (right != -1) {
      queue.push(right);
      level[right - 1] = next_level;
      max_level = max(max_level, next_level);
    }
  }
  vector<set<int>> level_indexes(max_level);
  for (auto i = 0; i < level.size(); i++) {
    level_indexes[level[i] - 1].emplace(i);
  }

  auto result_index = 0;
  stack<int> stack;
  vector<int> inorder;
  for (auto query: queries) {
    for (auto i = 1; query * i <= max_level; i++) {
      for (auto it : level_indexes[query * i - 1]) {
        swap(indexes[it].front(), indexes[it].back());
      }
    }

    inorder.clear();
    auto curr = 1;
    while (curr != -1 || !stack.empty()) {
      while (curr != -1) {
        stack.push(curr);
        curr = indexes[stack.top() - 1].front();
      }

      curr = stack.top();
      stack.pop();
      inorder.push_back(curr);

      curr = indexes[curr - 1].back();
    }

    result[result_index++] = inorder;
  }
  return result;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> indexes(n);
  for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
    indexes[indexes_row_itr].resize(2);

    for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
      cin >> indexes[indexes_row_itr][indexes_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[queries_itr] = queries_item;
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
    for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
      fout << result[result_row_itr][result_column_itr];

      if (result_column_itr != result[result_row_itr].size() - 1) {
        fout << " ";
      }
    }

    if (result_row_itr != result.size() - 1) {
      fout << "\n";
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

TEST_CASE("Test case 00", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 02", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 03", "[single-file]") {
  test_main("input03.txt", "result03.txt");

  auto output = read("output03.txt");
  auto result = read("result03.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 07", "[single-file]") {
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
