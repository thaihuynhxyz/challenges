#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"
#include <iostream>
#include <map>

using namespace std;

class SinglyLinkedListNode {
 public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
 public:
  SinglyLinkedListNode *head;
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_singly_linked_list(SinglyLinkedListNode *node) {
  while (node) {
    SinglyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2) {
  std::map<SinglyLinkedListNode *, bool> m;
  while (head1 || head2) {
    if (head1) {
      if (m[head1]) return head1->data;
      m[head1] = true;
      head1 = head1->next;
    }

    if (head2) {
      if (m[head2]) return head2->data;
      m[head2] = true;
      head2 = head2->next;
    }
  }
  return 0;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int tests;
  cin >> tests;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
    int index;
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedList *llist1 = new SinglyLinkedList();

    int llist1_count;
    cin >> llist1_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist1_count; i++) {
      int llist1_item;
      cin >> llist1_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist1->insert_node(llist1_item);
    }

    SinglyLinkedList *llist2 = new SinglyLinkedList();

    int llist2_count;
    cin >> llist2_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist2_count; i++) {
      int llist2_item;
      cin >> llist2_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist2->insert_node(llist2_item);
    }

    SinglyLinkedListNode *ptr1 = llist1->head;
    SinglyLinkedListNode *ptr2 = llist2->head;

    for (int i = 0; i < llist1_count; i++) {
      if (i < index) {
        ptr1 = ptr1->next;
      }
    }

    for (int i = 0; i < llist2_count; i++) {
      if (i != llist2_count - 1) {
        ptr2 = ptr2->next;
      }
    }

    ptr2->next = ptr1;

    int result = findMergeNode(llist1->head, llist2->head);

    fout << result << "\n";
  }

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

TEST_CASE("Test case 1", "[single-file]") {
  test_main("input01.txt", "result01.txt");

  auto output = read("output01.txt");
  auto result = read("result01.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

TEST_CASE("Test case 2", "[single-file]") {
  test_main("input02.txt", "result02.txt");

  auto output = read("output02.txt");
  auto result = read("result02.txt");

  REQUIRE(result.size() == output.size());
  for (auto i = 0; i < result.size(); i++) REQUIRE(result[i] == output[i]);
}

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}
