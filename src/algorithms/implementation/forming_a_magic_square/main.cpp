#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

int diff(int a, int b) { return abs(a - b); }

bool canPlace(const list<int> &m, const int &i) {
    if (i == 5 || m.size() == 9) return false;
    for (const auto &f : m) if (f == i) return false;
    switch (m.size()) {
        case 1:
            return true;
        case 3:
            if ((m.back() + i > 14) || (m.front() - i > 4)) return false;
            break;
        case 5:
            if ((m.front() + i > 14) || (m.back() - i > 4)) return false;
            break;
        case 7:
            const auto m11 = next(m.begin());
            const auto m10 = next(m11);
            const auto m21 = prev(m.end(), 2);
            if ((i + m.front() + *m11 != 15) || (i + *m10 + *m21 != 15)) return false;
    }
    return true;
}

void backtracking(list<int> &magicSquare, vector<list<int>> &availableMagicSquares) {
    for (int i = 1; i < 10; i++) {
        if (canPlace(magicSquare, i)) {
            magicSquare.push_front(i);
            magicSquare.push_back(10 - i);

            if (magicSquare.size() == 9) {
                availableMagicSquares.push_back(magicSquare);
            } else {
                backtracking(magicSquare, availableMagicSquares);
            }

            magicSquare.pop_front();
            magicSquare.pop_back();
        }
    }
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(const vector<vector<int>> &s) {
    const list<int> origin = {s[0][0], s[0][1], s[0][2], s[1][0], s[1][1], s[1][2], s[2][0], s[2][1], s[2][2]};
    auto result = INT_MAX;
    list<int> magicSquare({5});
    vector<list<int>> availableMagicSquares;
    backtracking(magicSquare, availableMagicSquares);

    for (const auto &ams : availableMagicSquares) {
        result = min(result, inner_product(ams.begin(), ams.end(), origin.begin(), 0, plus<>(), diff));
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