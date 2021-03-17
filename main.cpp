#include <iostream>
#include <vector>
#include <queue>
#include "Headers/sort.h"
#include "Headers/tree.h"

using namespace std;

void test_sort() {
    Sorted sortAlgo;
    // int numbers_i[] = {1, 7, 6, 10, 9};
    // int numbers_i[] = {2, 1, 4, 3};
    int numbers_i[] = {4, 5, 3, 6, 2, 1};
    vector<int> numbers_v(numbers_i, numbers_i + 6);
    cout << "原始数据: " << numbers_v << endl << endl;

    vector<int> select = sortAlgo.selection_sort(numbers_v);
    cout << "选择排序: " << select << endl << endl;;

    vector<int> insert = sortAlgo.insert_sort(numbers_v);
    cout << "插入排序: " << insert << endl << endl;

    vector<int> bubble = sortAlgo.bubble_sort(numbers_v);
    cout << "冒泡排序: " << insert << endl << endl;
    
    vector<int> shell = sortAlgo.shell_sort(numbers_v);
    cout << "希尔排序: " << insert << endl << endl;
    
    vector<int> merge = sortAlgo.merge_sort(numbers_v);
    cout << "归并排序: " << merge << endl << endl;

    vector<int> quick = sortAlgo.quick_sort(numbers_v);
    cout << "快速排序: " << quick << endl << endl;
}

void test_link() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // ListNode *result = swapPairs(node1);
    ListNode *result = reverseList(node1);
    cout << result;
}

int main()
{
    test_link();

    cout << endl;
    system("pause");
    return 0;
}