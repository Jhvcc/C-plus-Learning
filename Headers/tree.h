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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

std::ostream & operator<<(std::ostream &out, std::vector<std::vector<int>>);
std::ostream & operator<<(std::ostream &out, ListNode* node);
std::ostream & operator<<(std::ostream &out, TreeNode* root);
std::string printSpace(int count);
void operatorTree(TreeNode* root, int deep = 0, int flag = 0);

ListNode* swapPairs(ListNode* head);

std::vector<std::vector<int>> generate(int numRows);
void generate(int first, int numRows, std::vector<std::vector<int>> &result);

int getRow(int i, int j);
std::vector<int> getRow(int rowIndex);

ListNode* reverseList(ListNode* head);

int maxDepth(TreeNode* root);

double myPow(double x, int n);

std::vector<int> reversePrint(ListNode *head);

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);

/**
 * 树的遍历
 * 计算树中的最长路径
 * @input: 树的根节点
 * @output: 树的最长路径
*/
int diameterOfBinaryTree(TreeNode* root);

/**
 * 树的遍历
 * 将树的所有节点加一
 * @input: 树的根节点
 * @output: 将树的所有根节点加一
*/
void plusOne(TreeNode* root);

/**
 * 回溯算法
 * 满足金额的最少钱币
 * @param: coins->可用的钱币值, amount->目标值
 * @return: 满足的最小数量
*/
int connectCoins(std::vector<int> coins, int amount);

/**
 * 广度优先: 
 * 二叉树的最小深度
 * @param: root->树的根节点
 * @return: 最小深度
*/
int minDepth(TreeNode *root);

/**
 * 滑动窗口
 * 最小覆盖子串
 * @param: s->待查询字符串, t->必须包含的子串
 * @return: s中包含t所有字母的最小子串
*/
std::string minWindow(std::string s, std::string t);

/**
 * 滑动窗口
 * 完全子串
 * @param: t->只允许存在完全匹配的子串, s->待匹配的字符串
 * @return: s中是否存在完全匹配的子串
*/
bool checkInclusion(std::string t, std::string s);

/**
 * 滑动窗口
 * 最长无重复子串
 * @param: s->需要搜寻的字符串
 * @return: s中最长无重复的子串
*/
int lengthOfLongestSubString(std::string s);

/**
 * 状态机
 * 买卖股票的最佳时期
 * @params: price->它的第i个元素表示给定股票的第i天的价格
 * @return: 返回交易的最大利润
*/
int maxProfit(std::vector<int>& price);

/**
 * 状态机
 * 买卖股票的最佳时期Ⅱ
 * @params: price->它的第i个元素表示给定股票的第i天的价格
 * @return: 返回交易的最大利润，可多次买卖
*/
int maxProfit2(std::vector<int>& price);

/**
 * 状态机
 * 买卖股票的最佳时期Ⅲ
 * @param: price->它的第i个元素表示给定股票的第i天的价格
 * @return: 返回交易的最大利润，只可两次买卖
*/
int maxProfit3(std::vector<int>& price);

/**
 * 滑动窗口
 * 滑动窗口最大值
*/
std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k);

/**
 * 递归
 * 反转链表
*/
ListNode* reverseList1(ListNode* head);

/**
 * 迭代
 * 反转链表
*/
ListNode* reverseList2(ListNode* head);

/**
 * 递归
 * 反转链表前N个节点
*/
ListNode* reverseN(ListNode* head, int n);

/**
 * 递归
 * 反转链表的一部分
*/
ListNode* reverseBetween(ListNode* head, int m, int n);

/**
 * 迭代
 * 反转区间[a, b)之间的节点
*/
ListNode* reverse(ListNode* a, ListNode* b);

/**
 * 递归
 * K个一组反转链表
*/
ListNode* reverseKGroup(ListNode* head, int k);

/**
 * 递归
 * 判断回文链表
*/
bool isPalindrome(ListNode *head);
bool traverse(ListNode *head);

/**
 * 快慢指针加反转
 * 判断回文链表
*/
bool isPalindrome1(ListNode *head);

/**
 * 双指针
 * 合并两个有序数组
*/
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

/**
 * 双指针
 * 验证回文串，只考虑字母和数字，忽略大小写
*/
bool isPalindrome2(std::string s);

/**
 * 递归
 * 翻转二叉树
*/
TreeNode *invertTree(TreeNode *root);

/**
 * 递归
 * 填充每个节点的下一个右侧节点指针
*/
Node *connect(Node *root);

/**
 * 递归
 * 二叉树展开为链表
*/
void flatten(TreeNode *root);
void flatten1(TreeNode *root);

/**
 * 递归
 * 最大二叉树
*/
TreeNode *constructMaximumBinaryTree(std::vector<int> &nums);
TreeNode *constructMaximumBinaryTree1(std::vector<int> &nums);

/**
 * 递归
 * 从前序和中序遍历序列构造二叉树
*/
TreeNode *buildTreePre(std::vector<int> &preorder, std::vector<int> &inorder);

/**
 * 递归
 * 从后序和中序遍历序列构造二叉树
*/
TreeNode *buildTreePost(std::vector<int> &inorder, std::vector<int> &postorder);

/**
 * 递归,先序遍历或后序遍历
 * 寻找重复的子树
*/
std::vector<TreeNode*> findDuplicateSubtrees(TreeNode *root);

/**
 * 递归,中序遍历
 * 二叉搜索树中第K小的元素
*/
int kthSmallest(TreeNode *root, int k);

/**
 * 递归,中序遍历
 * 把二叉搜索树转换为累加树
*/
TreeNode *convertBST(TreeNode *root);

/**
 * 递归
 * 验证二叉搜索树
*/
bool isValidBST(TreeNode *root);
bool isValidBST1(TreeNode *root);

/**
 * 递归
 * 二叉搜索树中的搜索
*/
TreeNode *searchBST(TreeNode *root, int val);

/**
 * 递归
 * 删除二叉搜索树种的节点
*/
TreeNode *deleteNode(TreeNode *root, int key);

/**
 * 递归
 * 二叉树的序列化与反序列化
*/
class Codec {
public:
    std::string serializer(TreeNode *root);
    TreeNode *deserializer(std::string data);
};

#endif  // TREE_H_