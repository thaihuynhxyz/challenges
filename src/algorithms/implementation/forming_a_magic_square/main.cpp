#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(const vector<vector<int>> &s) {
    const vector<vector<vector<int>>> magicSquares = {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
                                                      {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
                                                      {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
                                                      {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
                                                      {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
                                                      {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
                                                      {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
                                                      {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};
    auto result = INT_MAX;
    int diff;
    for (const auto &ms : magicSquares) {
        diff = 0;
        for (auto i = 0; i < 3; i++) {
            for (auto j = 0; j < 3; j++) {
                diff += abs(ms[i][j] - s[i][j]);
            }
        }
        result = min(result, diff);
    }

    return result;
}

void test_main(const string &input_file, const string &result_file) {
    std::ifstream input(input_file);
    std::cin.rdbuf(input.rdbuf());
    ofstream fout(result_file);

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

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

TEST_CASE("Test case 22", "[single-file]") {
    test_main("input22.txt", "result22.txt");

    auto output = read("output22.txt");
    auto result = read("result22.txt");

    REQUIRE(result.size() == output.size());
    for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

int main(int argc, char *argv[]) {
    // global setup...

    int result = Catch::Session().run(argc, argv);

    // global clean-up...
    return result;
}