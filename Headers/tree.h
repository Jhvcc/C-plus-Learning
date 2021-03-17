#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream & operator<<(std::ostream &out, std::vector<std::vector<int>>);
std::ostream & operator<<(std::ostream &out, ListNode* node);

ListNode* swapPairs(ListNode* head);

std::vector<std::vector<int>> generate(int numRows);
void generate(int first, int numRows, std::vector<std::vector<int>> &result);

int getRow(int i, int j);
std::vector<int> getRow(int rowIndex);

ListNode* reverseList(ListNode* head);

#endif  // TREE_H_