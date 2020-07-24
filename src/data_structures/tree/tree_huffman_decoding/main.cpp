#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"

using namespace std;

typedef struct node {

  int freq;
  char data;
  node *left;
  node *right;

} node;

struct deref : public binary_function<node *, node *, bool> {
  bool operator()(const node *a, const node *b) const {
    return a->freq > b->freq;
  }
};

typedef priority_queue<node *, vector<node *>, deref> spq;

node *huffman_hidden(string s) {

  spq pq;
  vector<int> count(256, 0);

  for (int i = 0; i < s.length(); i++) {
    count[s[i]]++;
  }

  for (int i = 0; i < 256; i++) {

    node *n_node = new node;
    n_node->left = NULL;
    n_node->right = NULL;
    n_node->data = (char) i;
    n_node->freq = count[i];

    if (count[i] != 0)
      pq.push(n_node);

  }

  while (pq.size() != 1) {

    node *left = pq.top();
    pq.pop();
    node *right = pq.top();
    pq.pop();
    node *comb = new node;
    comb->freq = left->freq + right->freq;
    comb->data = '\0';
    comb->left = left;
    comb->right = right;
    pq.push(comb);

  }

  return pq.top();

}

void print_codes_hidden(node *root, string code, map<char, string> &mp) {

  if (root == NULL)
    return;
  if (root->data != '\0') {
    mp[root->data] = code;
  }

  print_codes_hidden(root->left, code + '0', mp);
  print_codes_hidden(root->right, code + '1', mp);

}

/*
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;

}node;

*/


void decode_huff(node *root, string s, ofstream &fout) {
  auto it = root;
  for (char c : s) {
    if (c == '0') {
      if (it->left) {
        it = it->left;
      } else {
        fout << it->data;
        it = root->left;
      }
    } else {
      if (it->right) {
        it = it->right;
      } else {
        fout << it->data;
        it = root->right;
      }
    }
  }
  fout << it->data;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  string s;
  std::cin >> s;

  node *tree = huffman_hidden(s);
  string code = "";

  map<char, string> mp;
  print_codes_hidden(tree, code, mp);

  string coded;

  for (int i = 0; i < s.length(); i++) {
    coded += mp[s[i]];
  }

  decode_huff(tree, coded, fout);

  fout.close();
}

string read(const string &filename) {
  std::ifstream output(filename);
  std::cin.rdbuf(output.rdbuf());
  string result;
  int element;
  while (cin >> element) result.push_back(element);
  return result;
}

TEST_CASE("Test case 02", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 05", "[single-file]") {
  test_main("input05.txt", "result05.txt");

  auto output = read("output05.txt");
  auto result = read("result05.txt");

  REQUIRE(result == output);
}

TEST_CASE("Test case 06", "[single-file]") {
  test_main("input06.txt", "result06.txt");

  auto output = read("output06.txt");
  auto result = read("result06.txt");

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
