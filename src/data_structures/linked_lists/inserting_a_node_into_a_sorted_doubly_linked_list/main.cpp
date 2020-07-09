#define CATCH_CONFIG_RUNNER

#include <bits/stdc++.h>
#include "catch2/catch.hpp"
#include <iostream>
#include <map>

using namespace std;

class DoublyLinkedListNode {
 public:
  int data;
  DoublyLinkedListNode *next;
  DoublyLinkedListNode *prev;

  DoublyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
      node->prev = this->tail;
    }

    this->tail = node;
  }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
  while (node) {
    DoublyLinkedListNode* temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
  if (head->data > data) {
    auto insert = new DoublyLinkedListNode(data);
    insert->next = head;
    return insert;
  }
  auto insert = head;
  while (insert) {
    auto next = insert->next;
    if (next && next->data > data){
      auto new_node = new DoublyLinkedListNode(data);
      insert->next = new_node;
      new_node->next = next;
      return head;
    } else if (!next) {
      auto new_node = new DoublyLinkedListNode(data);
      insert->next = new_node;
      return head;
    }
    insert = insert->next;
  }

  return head;
}

void test_main(const string &input_file, const string &result_file) {
  std::ifstream input(input_file);
  std::cin.rdbuf(input.rdbuf());
  ofstream fout(result_file);

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    DoublyLinkedList* llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);
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

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}
