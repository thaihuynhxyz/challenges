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

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

  // Finds the path from root node to given root of the tree, Stores the
  // path in a vector path[], returns true if path exists otherwise false
  bool findPath(Node *root, vector<Node *> &path, int k) {
    // base case
    if (root == nullptr) return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);

    // See if the k is same as root's key
    if (root->data == k) return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k))) {
      return true;
    }

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
  }

  Node *lca(Node *root, int v1, int v2) {
    // to store paths to n1 and n2 from the root
    vector<Node *> path1, path2;

    // Find paths from root to v1 and root to v2. If either v1 or v2
    // is not present, return -1
    if (!findPath(root, path1, v1) || !findPath(root, path2, v2))return nullptr;

    /* Compare the paths to get the first different value */
    int i;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
      i++;
    }

    return path1[i - 1];
  }

}; //End of Solution

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  int v1, v2;
  std::cin >> v1 >> v2;

  Node *ans = myTree.lca(root, v1, v2);

  fout << ans->data;

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

TEST_CASE("Test case 00", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 05", "[single-file]") {
  test_main("input05.txt", "result05.txt");

  auto output = read("output05.txt");
  auto result = read("result05.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 09", "[single-file]") {
  test_main("input09.txt", "result09.txt");

  auto output = read("output09.txt");
  auto result = read("result09.txt");

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
