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
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    // ListNode *result = swapPairs(node1);
    // ListNode *result = reverseList(node1);
    // ListNode* result = reverseList1(node1);
    // ListNode* result = reverseN(node1, 2);
    // ListNode* result = reverseBetween(node1, 2, 4);
    // ListNode* result = reverse(node1, node3);
    // ListNode * result = reverseKGroup(node1, 2);
    // bool result = isPalindrome(node1);
    bool result = isPalindrome1(node6);
    cout << result;
}

void test_tree() {
    TreeNode *root = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);
    TreeNode *root6 = new TreeNode(6);
    TreeNode *root7 = new TreeNode(7);
    TreeNode *root8 = new TreeNode(8);
    TreeNode *root9 = new TreeNode(9);
    TreeNode *root10 = new TreeNode(10);
    TreeNode *root11 = new TreeNode(11);
    TreeNode *root12 = new TreeNode(12);
    TreeNode *root13 = new TreeNode(13);
    TreeNode *root14 = new TreeNode(14);
    TreeNode *root15 = new TreeNode(15);
    TreeNode *root16 = new TreeNode(16);
    TreeNode *root17 = new TreeNode(17);
    TreeNode *root18 = new TreeNode(18);
    root->left = root2;
    root->right = root3;
    root3->left = root4;
    root3->right = root5;
    root4->left = root6;
    root4->right = root7;
    root5->left = root8;
    root6->left = root9;
    root7->left = root10;
    root7->right = root11;
    root9->left = root12;
    root9->right = root13;
    root10->left = root14;
    root11->left = root15;
    root12->right = root16;
    root13->left = root17;
    root15->left = root18;

    TreeNode *head1 = new TreeNode(1);
    TreeNode *head2 = new TreeNode(2);
    TreeNode *head3 = new TreeNode(3);
    TreeNode *head4 = new TreeNode(4);
    TreeNode *head5 = new TreeNode(5);
    TreeNode *head6 = new TreeNode(6);
    TreeNode *head7 = new TreeNode(7);
    TreeNode *head8 = new TreeNode(8);
    TreeNode *head9 = new TreeNode(9);
    TreeNode *head10 = new TreeNode(10);
    TreeNode *head11 = new TreeNode(11);
    head1->left = head2;
    head1->right = head3;
    head2->left = head4;
    head2->right = head5;
    head3->left = head6;
    head3->right = head7;
    head4->left = head8;
    head5->left = head9;
    head6->right = head10;
    head7->right = head11;

    TreeNode *tree1 = new TreeNode(1);
    TreeNode *tree2 = new TreeNode(2);
    TreeNode *tree3 = new TreeNode(3);
    TreeNode *tree4 = new TreeNode(4);
    tree1->left = tree2;
    tree1->right = tree3;
    tree2->right = tree4;

    Codec co;
    string res = co.serializer(tree1);
    cout << res << endl;
    cout << co.deserializer(res) << endl;

    
}

void test_node() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    Node *res = connect(node1);
}

int main()
{
    // test_link();
    // cout << myPow(1, 2147483647) << endl;
    // vector<int> tmp = {1, 3, -1, -3, 5, 3, 6, 7};
    // int k = 3;
    test_tree();
    // test_node();
    // string s = "ADOBECODEBANC", t = "ABC";
    // string s = "aa", t = "aa";
    // bool result = checkInclusion(t, s);
    // cout << result << endl;
    // vector<int> tmp = {3, 3, 5, 0, 0, 3, 1, 4};
    // cout << maxProfit(tmp) << endl;
    // cout << maxProfit2(tmp) << endl;
    // cout << maxProfit3(tmp) << endl;
    // vector<int> nums = {};
    // int k = 0;
    // vector<int> r = maxSlidingWindow1(nums, k);
    // cout << "len: " << r.size() << " result:" << r << endl;
    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    // vector<int> nums2 = {2, 5, 6};
    // int m = 3, n = 3;
    // merge(nums1, m, nums2, n);
    // cout << nums1 << endl;
    // string s = "race a car";
    // cout << isPalindrome2(s) << endl;

    // vector<int> nums = {3, 2, 1, 6, 0, 5};
    // TreeNode *root = constructMaximumBinaryTree1(nums);
    // vector<int> preorder = {3, 9, 20, 15, 7};
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    // TreeNode *root = buildTreePre(preorder, inorder);
    // TreeNode *proot = buildTreePost(inorder, postorder);
    // cout << root << endl;
    // cout << proot << endl;


    cout << endl;
    system("pause");
    return 0;
}