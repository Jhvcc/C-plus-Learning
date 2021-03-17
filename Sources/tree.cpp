#include <vector>
#include "../Headers/tree.h"

std::ostream & operator<<(std::ostream &out, ListNode* node) {
    while (node) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
    return std::cout;
}

std::ostream & operator<<(std::ostream &out, std::vector<std::vector<int>> result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return std::cout;
}


ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *tmp = head->next;
    // head->next = tmp->next;
    // tmp->next = head;
    // ListNode *substring = swapPairs(tmp->next->next);
    // tmp->next->next = substring;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;
}

void generate(int first, int numRows, std::vector<std::vector<int>> &result) {
    if (first > numRows) return;
    std::vector<int> tmp(first);
    for (int i = 0; i < first; i++) {
        if (i == 0 || i == first-1) 
            tmp[i] = 1;
        else
            tmp[i] = result[first-2][i-1] + result[first-2][i];
    }

    result[first-1] = tmp;

    generate(first+1, numRows, result);
}

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result(numRows);
    generate(1, numRows, result);
    return result;
}

int getRow(int i, int j) {
    if (j == 0 || j == i) return 1;
    if (i < 0) return 0;
    int x = i - 1;
    int y = j - 1;
    return getRow(x, y) + getRow(x, j);
}

std::vector<int> getRow(int rowIndex) {
    std::vector<int> result(rowIndex+1);
    for (int i = 0; i <= rowIndex; i++) {
        result[i] = getRow(rowIndex, i);
    }
    return result;
}

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode * result = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return result;
}