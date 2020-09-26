#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
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
 private:
  /* Function to find index of the maximum value in arr[start...end] */
  int max(vector<int> arr, int strt, int end) {
    int i, max = arr[strt], maxind = strt;
    for (i = strt + 1; i <= end; i++) {
      if (arr[i] > max) {
        max = arr[i];
        maxind = i;
      }
    }
    return maxind;
  }
 public:
  /* Recursive function to construct binary of size len from
   Inorder traversal inorder[]. Initial values of start and end
   should be 0 and len -1.  */
  Node *buildTree(vector<int> inorder, int start, int end) {
    if (start > end) return nullptr;

    /* Find index of the maximum element from Binary Tree */
    int i = max(inorder, start, end);

    /* Pick the maximum value and make it root */
    Node *root = new Node(inorder[i]);

    /* If this is the only element in inorder[start..end],
       then return it */
    if (start == end) return root;

    /* Using index in Inorder traversal, construct left and
       right subtress */
    root->left = buildTree(inorder, start, i - 1);
    root->right = buildTree(inorder, i + 1, end);

    return root;
  }

  /* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
  bool checkMinMax(Node *root, int min, int max) {
    bool result = root->data > min && root->data < max;
    if (result && root->left) {
      result = checkMinMax(root->left, min, root->data);
    }

    if (result && root->right) {
      result = checkMinMax(root->right, root->data, max);
    }

    return result;
  }

  bool checkBST(Node *root) {
    return checkMinMax(root, INT_MIN, INT_MAX);
  }
}; //End of Solution

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  Solution myTree;
  Node *root = nullptr;

  int k;
  int data;
  vector<int> inorder;

  std::cin >> k;

  while (std::cin >> data) {
    inorder.push_back(data);
  }

  root = myTree.buildTree(inorder, 0, inorder.size() - 1);

  if (myTree.checkBST(root)) {
    fout << "Yes";
  } else {
    fout << "No";
  }

  fout.close();
}

string read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  string result;
  cin >> result;
  return result;
}

TEST_CASE("Test case 00", "[single-file]") {
  test_main("input00.txt", "result00.txt");

  auto output = read("output00.txt");
  auto result = read("result00.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 01", "[single-file]") {
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
