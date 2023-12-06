#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

class Node {
 public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
 public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

  // function to fill the map
  void fillMap(Node *root, int distance, int level, map<int, pair<int, int>> &map) {
    if (root == nullptr) return;

    if (map.count(distance) == 0 || map[distance].second > level) map[distance] = make_pair(root->data, level);

    fillMap(root->left, distance - 1, level + 1, map);
    fillMap(root->right, distance + 1, level + 1, map);
  }

  void topView(Node *root, ofstream &fout) {
    //map to store the pair of node value and its level
    //with respect to the vertical distance from root.
    map<int, pair<int, int>> map;

    //fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, map);

    for (auto it : map) {
      fout << it.second.first << " ";
    }
  }

}; //End of Solution

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  Solution myTree;
  Node *root = nullptr;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.topView(root, fout);

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
