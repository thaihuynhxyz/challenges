#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

int solveMeFirst(int a, int b) {
  return a + b;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int num1, num2;
  int sum;
  cin >> num1 >> num2;
  sum = solveMeFirst(num1, num2);

  fout << sum;

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

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}
