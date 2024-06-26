#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

vector<string> split_string(string);

struct Player {
    int score;
    string name;
};

// complete this method
static int comparator(Player a, Player b)  {
    if (a.score < b.score) {
        return -1;
    } else if (a.score > b.score) {
        return 1;
    } else {
        if (a.name > b.name) {
            return -1;
        } else if (a.name < b.name) {
            return 1;
        } else {
            return 0;
        }
    }
}

bool compare(Player a, Player b) {
    if(comparator(a,b) == -1)
        return false;
    return true;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector< Player > players;
  string name;
  int score;
  for(int i = 0; i < n; i++){
      cin >> name;
      cin.ignore(numeric_limits<streamsize>::max(), ' ');
      cin >> score;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      Player player;
      player.name = name, player.score = score;
      players.push_back(player);
  }
  sort(players.begin(), players.end(), compare);
  for(int i = 0; i < players.size(); i++) {
      fout << players[i].name << " " << players[i].score << endl;
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
