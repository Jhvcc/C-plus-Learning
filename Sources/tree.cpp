#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include "../Headers/tree.h"

std::ostream & operator<<(std::ostream &out, ListNode* node) {
    while (node != nullptr || node != NULL) {
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

std::string printSpace(int count) {
    std::string result = "";
    for (int i = 0; i<count; i++) {
        result += "  ";
    }
    return result;
}

void operatorTree(TreeNode* root, int deep, int flag) {
    if (!root) return;
    if (flag == 0) {
        std::cout << printSpace(deep) << "node: " << root->val << std::endl;
    } else if (flag == 1) {
        std::cout << printSpace(deep) << "left: " << root->val << std::endl;
    } else {
        std::cout << printSpace(deep) << "right: " << root->val << std::endl;
    }
    deep++;
    if (root->left) {
        operatorTree(root->left, deep, 1);
    }
    if (root->right) {
        operatorTree(root->right, deep, 2);
    }
}

std::ostream & operator<<(std::ostream &out, TreeNode* root) {
    operatorTree(root);
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

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right))+1;
}

double myPow(double x, int n) {
    if (n < 0) {
        x = 1/x;
        n = -n;
    }
    double sum = 1;
    while (n) {
        sum *= x;
        n--;
    }
    return sum;
}

std::vector<int> reversePrint(ListNode *head) {
    if (!head) {
        return std::vector<int>();
    }
    if (!head->next) {
        std::vector<int> r;
        r.push_back(head->val);
        return r;
    }
    std::vector<int> tmp = reversePrint(head->next);
    tmp.push_back(head->val);
    return tmp;
}

// 滑动窗口
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    int begin = 0, end = 0;
    if (!nums.size() || !k) {
        return std::vector<int>();
    }

    std::vector<int> tmp = {nums[0]};
    std::vector<int> result;
    while (end < nums.size()) {
        while(tmp.back() <= nums[end]) {
            tmp.pop_back();
        }
        tmp.push_back(nums[end]);
        if (end - begin + 1 >= k) {
            result.push_back(tmp.front());
            if (tmp.size() == k) {
                tmp.erase(tmp.begin());
            }
            begin++;
        }
        end++;
    }
    return result;
}

int max = 0;
int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
        return 0; 
    }
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    max = std::max(max, left+right);
    return std::max(left, right) + 1;
}

void plusOne(TreeNode* root) {
    if (!root) return;
    root->val++;

    plusOne(root->left);
    plusOne(root->right);
}

int connectCoins(std::vector<int> coins, int amount) {
    if (!amount) return amount;
    if (amount < 0) return -1;
    int result = amount;
    for (int coin: coins) {
        int flag = connectCoins(coins, amount - coin);
        if (flag < 0) continue;
        result = std::min(result, flag + 1);
    }
    return result;
}

int minDepth(TreeNode *root) {
    std::vector<TreeNode*> deque = {root};
    int depth = 0;
    while (!deque.empty()) {
        int i = deque.size();
        for (int j = 0; j < i; j++) {
            TreeNode * node = deque.front();
            deque.erase(deque.begin());
            if (!node->left && !node->right) {
                return depth;
            }
            if (node->left) {
                deque.push_back(node->left);
            }
            if (node->right) {
                deque.push_back(node->right);
            }
        }
        depth++;
    }
    return depth;
}

std::string minWindow(std::string s, std::string t) {
    int left = 0, right = 0;
    std::unordered_map<char, int> visited, flag;
    // 记录最小子串的索引与长度，不直接记录子串是为了避免进行多次的字符串截取
    int start = 0, len = INT_MAX;
    // 记录是否符合子串每个字母都存在的要求
    int valid = 0;
    for (char i: t) {
        flag[i]++;
        visited[i] = 0;
    }
    while (right < s.size()) {
        // 窗口右移前先获取右边字符
        char c = s[right++];

        // 如果该字符是目标字符，则将visited中的该字符加一
        if (flag.count(c)) {
            // 这里先将字符数加一再进行判断是由于该字符先进滑动窗口所以要先加
            visited[c]++;
            if (flag[c] == visited[c]) {
                // 判断该字符的数量是否符合，符合则valid加一
                valid++;
            }
        }

        // 如果每个字符及数量都符合要求，则缩小左边界
        while (valid == flag.size()) {
            if (right - left < len) {
                start = left;
                len = right - left;
            }

            char d = s[left++];
            if (flag.count(d)) {
                // 这里先判断是否为符合的字符从左出窗口，是由于如果先减一则后续判断会一直不符合
                // 导致valid符合的字符一直无法更新
                if (flag[d] == visited[d]) {
                    valid--;
                }
                visited[d]--;
            }
        }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
}

bool checkInclusion(std::string t, std::string s) {
    int left = 0, right = 0;
    int valid = 0;
    std::unordered_map<char, int> flag, visited;
    for (char i: t) {
        flag[i]++;
    }

    while (right < s.size()) {
        char r = s[right++];

        if (flag.count(r)) {
            visited[r]++;
            if (visited[r] == flag[r]){
                valid++;
            }
        }

        while (right - left >= t.size()) {
            if (valid == flag.size()) {
                return true;
            }
            char r = s[left++];
            if (flag.count(r)) {
                if (visited[r] == flag[r]) {
                    valid--;
                }
                visited[r]--;
            }
        }
    }
    return false;
}

int lengthOfLongestSubString(std::string s) {
    int left = 0, right = 0;
    std::unordered_map<char, int> flag;
    int res = 0;

    while (right < s.size()) {
        char c = s[right++];
        
        flag[c]++;

        while (flag[c] > 1) {
            char c = s[left++];

            flag[c]--;
        }
        res = res > right - left ? right - left : res;
    }
    return res;
}

int maxProfit(std::vector<int>& price) {
    if (price.empty()) return 0;

    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;

    for (int i = 0; i < price.size(); i++) {
        dp_i_0 = std::max(dp_i_0, dp_i_1 + price[i]);
        dp_i_1 = std::max(dp_i_1, - price[i]);
    }
    return dp_i_0;
}

int maxProfit2(std::vector<int>& price) {
    if (price.empty()) return 0;

    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;

    for (int i = 0; i < price.size(); i++) {
        dp_i_0 = std::max(dp_i_0, dp_i_1 + price[i]);
        dp_i_1 = std::max(dp_i_1, dp_i_0 - price[i]);
    }
    return dp_i_0;
}

int maxProfit3(std::vector<int>& price) {
    if (price.empty()) return 0;

    int k = 2;
    int res[price.size()+1][k][2];
    res[0][0][0] = 0;
    res[0][0][1] = INT_MIN;

    for (int i = 1; i <= price.size(); i++) {
        for (int j = 0; j < k; j++) {
            res[i-1][j][0] = std::max(res[i-2][k][0], res[i-1][k][1] + price[i-1]);
            res[i-1][j][1] = std::max(res[i-2][k][1], res[i-1][k][0] - price[i-1]);
        }
    }
    return res[price.size()][k-1][0];
}

std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k) {
    int left = 0, right = 0;
    std::vector<int> queue = {INT_MIN};
    std::vector<int> res;

    while (right < nums.size()) {
        int i = nums[right++];
        while (i > queue.back()) {
            queue.pop_back();
        }
        queue.push_back(i);

        if (right - left >= k) {
            res.push_back(queue[0]);
            int i = nums[left++];
            if (i == queue[0]) {
                queue.erase(queue.begin());
            }
        }
    }
    return res;
}

ListNode* reverseList1(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* last = reverseList1(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

ListNode* reverseList2(ListNode* head) {
    ListNode* pre = NULL, *cur = head, *nxt = head;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* successor;
ListNode* reverseN(ListNode* head, int n) {
    // base case
    if (n == 1) {
        //将后续的不需要反转的链保存起来
        successor = head->next;
        return head;
    }

    // 此刻返回子链的首节点
    ListNode* last = reverseN(head->next, n - 1);
    // 让递归前一层的首节点将连接successor断开
    head->next->next = head;
    // 这里让当前层的首节点连接successor
    head->next = successor;
    // 返回首节点
    return last;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == 1) {
        return reverseN(head, n);
    }
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
}

ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode *pre = NULL, *cur = a, *nxt = a;
    while (cur != b) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return head;
    // 区间[a, b)，包含k个反转节点
    ListNode *a = head, *b = head;
    for (int i = 0; i < k; i++) {
        // base case
        // 当后续数量不足k个时，无需反转直接返回当前递归层的首节点
        if (b == NULL) return head;
        b = b->next;
    }
    // 反转[a, b)区间内节点，并返回反转后的首节点
    ListNode *newHead = reverse(a, b);
    // 将当前递归层的尾节点连接下一递归层的首节点
    a->next = reverseKGroup(b, k);
    // 返回每一层的首节点
    return newHead;
}

ListNode *left;
bool isPalindrome(ListNode *head) {
    left = head;
    return traverse(head);
}

bool traverse(ListNode *head) {
    if (head == NULL) return true;
    bool result = traverse(head->next);
    result = result && (left->val == head->val);
    left = left->next;
    return result;
}


/**
 * 这题的精髓在于先用快慢指针获取到链表的中间节点，然后将中间节点的后续子链进行反转
*/
bool isPalindrome1(ListNode *head) {
    ListNode *slow = head, *fast = head, *start = head;
    // 这里的两个判断分别对应链表为奇数和偶数
    // 如果是偶数则fast最后为NULL
    // 如果是奇数则fast最后为尾节点，也就是fast->next为NULL
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 这里对奇数节点进行单独判断
    // 此时slow指向奇数链中间节点，需要将slow往后移，保证不管奇偶slow都指向后续子链的首节点
    if (fast != NULL) {
        slow = slow->next;
    }

    ListNode *pre = NULL, *cur = slow, *nxt = slow;
    // 迭代反转slow指向的子链
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    // 这里将主链与子链进行逐个判断
    // 判断条件必须是子链是否结束，因为除去子链的主链长度不小于子链的长度
    while (pre != NULL) {
        if (start->val != pre->val) return false;
        start = start->next;
        pre = pre->next;
    }
    return true;
}

/**
 * 这题的精髓在于从后往前填充，题目需要往nums1从小到大合并，换种角度可以从后往前从大到小的合并
 * 这样刚刚好不需要额外的空间，刚好填满
*/
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int p = m-- + n-- - 1;
    while (m >= 0 && n >= 0) {
        nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    // 这里得特别注意，如果nums1里的元素比nums2里的元素要大
    // 则到目前为止也就是把nums1里的参数重复的填到了nums1的后面，nums2里的参数都未参与合并
    // 所以需要对nums2进行单独判断
    while (n >= 0) {
        nums1[p--] = nums2[n--];
    }
}

bool isPalindrome2(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        bool flag = false;
        bool number = false;
        bool letter = false; 
        if ((s[i] >= '0' && s[i] <= '9')) {
            number = true;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z')) {
            letter = true;
        } else {
            i++;
            flag = true;
        }
        if (!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >='A' && s[j] <= 'Z'))) {
            j--;
            flag = true;
        }
        if (flag) {
            continue;   
        } else if ((number && s[i] == s[j]) || (letter && (s[i] == s[j] || int(s[i]) == s[j] - 32 || int(s[i]) == s[j] + 32))) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) return root;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->right);
    invertTree(root->left);

    return root;
}

void connectTwoNode(Node *node1, Node *node2) {
    if (node1 == NULL || node2 == NULL) return;
    node1->next = node2;

    // 同父节点之间的链接
    connectTwoNode(node1->left, node1->right);
    connectTwoNode(node2->left, node2->right);
    // 跨越两个父节点的链接
    connectTwoNode(node1->right, node2->left);

}

Node *connect(Node *root) {
    if (root == NULL) return root;
    connectTwoNode(root->left, root->right);
    return root;
}

void flatten(TreeNode *root) {
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = NULL;
    root->right = left;

    TreeNode *p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    p->right = right;
}

void flatten1(TreeNode *root) {
    if (root == NULL) return;

    TreeNode *right = root->right;

    // 先将左子树移到右边，然后将左子树置空
    root->right = root->left;
    root->left = NULL;

    TreeNode *p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    // 遍历完左子树移到右边之后的节点，就将原先的右子树再链接到后面
    p->right = right;

    flatten(root->right);
}

TreeNode *constructMaximumBinaryTree(std::vector<int> &nums, TreeNode *root) {
    // 当传进来的数组为空则说明无左右节点了
    if (nums.empty()) {
        return root;
    }
    // 找出当前数组中的最大值的索引
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[max] < nums[i]) {
            max = i;
        }
    }

    // 先序遍历先创建根节点
    root = new TreeNode(nums[max]);
    // 获取数组的前半部分和数组的后半部分，特别要排除已经创建的max索引
    std::vector<int> first(nums.begin(), nums.begin() + max);
    std::vector<int> last(nums.end() - nums.size() + max + 1, nums.end());
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    // 根据递归赋值左右子树
    root->left = constructMaximumBinaryTree(first, left);
    root->right = constructMaximumBinaryTree(last, right);
    // 到最外层递归直接释放整棵树的根节点
    return root;
}

TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    TreeNode *root = NULL;
    // 弊端是每次递归都会伴随数组传递，空间浪费大，而且数组的处理也会浪费时间，效率不高
    return constructMaximumBinaryTree(nums, root);
}

TreeNode *constructMaximumBinaryTree1(std::vector<int> &nums, int lo, int hi) {
    // 由于lo和hi都是数组索引，所以当lo大于hi时意味着此时这个区间没有数据，也表示无左右节点
    if (lo > hi) return NULL;

    // 找出当前数组区间中的最大值的索引
    int max = lo;
    for (int i = lo; i <= hi; i++) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }

    // 先序遍历创建节点
    TreeNode *root = new TreeNode(nums[max]);
    root->left = constructMaximumBinaryTree1(nums, lo, max - 1);
    root->right = constructMaximumBinaryTree1(nums, max + 1, hi);
    return root;
}

TreeNode *constructMaximumBinaryTree1(std::vector<int> &nums) {
    // 改用每次递归传递数组索引，减少空间使用以及减少数组的处理
    return constructMaximumBinaryTree1(nums, 0, nums.size() - 1);
}

TreeNode *buildTreePre(std::vector<int> &preorder, int p_lo, int p_hi, std::vector<int> &inorder, int i_lo, int i_hi) {
    if (i_lo > i_hi) return NULL;
    // 获取中序遍历树的根节点
    int mid = i_lo;
    for (int i = i_lo; i <= i_hi; i++) {
        if (inorder[i] == preorder[p_lo]) {
            mid = i;
            break;
        }
    }
    
    // 这里是计算先序遍历排除首节点之后左子树的先序节点个数
    int leftSize = mid - i_lo;
    TreeNode *root = new TreeNode(preorder[p_lo]);
    // 这里p_lo + 1代表当前子树先序遍历首节点的后一个节点
    // p_lo + leftSize代表当前子树先序遍历的最后一个节点，也就是首节点的位置加上左子树的个数
    root->left = buildTreePre(preorder, p_lo + 1, p_lo + leftSize, inorder, i_lo, mid - 1);
    // 这里p_lo + leftSize + 1代表先序遍历数组右子树的首个节点位置
    // p_hi代表先序遍历右子树的最后一个节点
    root->right = buildTreePre(preorder, p_lo + leftSize + 1, p_hi, inorder, mid + 1, i_hi);
    return root;
}

TreeNode *buildTreePre(std::vector<int> &preorder, std::vector<int> &inorder) {
    return buildTreePre(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode *buildTreePost(std::vector<int> &inorder, int i_lo, int i_hi, std::vector<int> &postorder, int p_lo, int p_hi) {
    if (i_lo > i_hi) return NULL;
    // 获取中序遍历的根节点
    int mid = i_lo;
    for (int i = i_lo; i <= i_hi; i++) {
        if (inorder[i] == postorder[p_hi]) {
            mid = i;
            break;
        }
    }
    // 计算排除后序遍历尾节点之后右子树的元素个数
    int rightSize = i_hi - mid;

    TreeNode *root = new TreeNode(postorder[p_hi]);
    root->left = buildTreePost(inorder, i_lo, mid - 1, postorder, p_lo, p_hi - rightSize - 1);
    root->right = buildTreePost(inorder, mid + 1, i_hi, postorder, p_hi - rightSize, p_hi - 1);
    return root;
}

TreeNode *buildTreePost(std::vector<int> &inorder, std::vector<int> &postorder) {
    return buildTreePost(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}


std::unordered_map<std::string, int> visited;
std::vector<TreeNode*> res;
std::string findDuplicate(TreeNode *root) {
    // 每一个空的节点都置为#
    if (root == NULL) return "#";

    std::string left = findDuplicate(root->left);
    std::string right = findDuplicate(root->right);

    // 只能用先序或后序，如果用中序则对于案例：
    //     0       0
    //    /         \|
    //   0           0
    // 通过不了，因为两个的中序都是"#0#0#"
    std::string str = left + "," + right + "," + std::to_string(root->val);
    // 将节点保存在备忘录
    if (visited[str] == 1) {
        res.push_back(root);
    }
    visited[str]++;
    return str;
}

std::vector<TreeNode*> findDuplicateSubtrees(TreeNode *root) {
    findDuplicate(root);
    return res;
}

int flag = 0, _res = INT_MIN;
void reverse(TreeNode *root, int k) {
    if (!root) return;

    reverse(root->left, k);
    flag++;
    if (flag == k) {
        _res = root->val;
        return;
    }
    reverse(root->right, k);
}

int kthSmallest(TreeNode *root, int k) {
    reverse(root, k);
    return _res;
}

int greaterSum = 0;
TreeNode *convertBST(TreeNode *root) {
    // 二叉搜索树的中序遍历实际上就是从大到小或从小到大顺序查找
    if (!root) return root;

    convertBST(root->right);
    greaterSum += root->val;
    root->val = greaterSum;
    convertBST(root->left);

    return root;
}

bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (!root) return true;

    if (min && root->val <= min->val) return false;
    if (max && root->val >= max->val) return false;

    return isValidBST(root->left, min, root)
        && isValidBST(root->right, root, max);
}

bool isValidBST(TreeNode *root) {
    return isValidBST(root, NULL, NULL);
}

int *last = NULL;
bool isValidBST1(TreeNode *root) {
    if (!root) return true;
    bool left = isValidBST1(root->left);
    // 中序遍历，判断是否为单调序列
    if (last && *last >= root->val) return false;
    last = &root->val;
    bool right = isValidBST1(root->right);

    return left && right;
}

TreeNode *searchBST(TreeNode *root, int val) {
    if (!root) return NULL;

    if (root->val == val) return root;
    if (root->val > val) return searchBST(root->left, val);
    if (root->val < val) return searchBST(root->right, val);
}

TreeNode *getMin(TreeNode *node) {
    while (node->left) node = node->left;
    return node;
}

TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) return root;
    if (root->val == key) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        TreeNode *minNode = getMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    } else if (root->val > key) {

        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {

        root->right = deleteNode(root->right, key);
    }
    return root;
}

std::string seri = "";
// 先序遍历序列化
void serializerpre(TreeNode * root) {
    if (!root) {
        seri += "#,";
        return;
    }

    seri += std::to_string(root->val) + ",";

    serializerpre(root->left);
    serializerpre(root->right);
}

// 后序遍历序列化
void serializerpost(TreeNode *root) {
    if (!root) {
        seri += "#,";
        return;
    }

    serializerpost(root->left);
    serializerpost(root->right);

    seri += std::to_string(root->val) + ",";
}

// 层序遍历序列化
void serializerlevel(TreeNode *root) {
    std::queue<TreeNode*> visited;
    visited.push(root);

    while (!visited.empty()) {
        TreeNode *tmp = visited.front();
        visited.pop();

        if (!tmp) {
            seri += "#,";
            continue;
        }
        seri += std::to_string(tmp->val) + ",";

        visited.push(tmp->left);
        visited.push(tmp->right);
    }
}

std::string Codec::serializer(TreeNode *root) {
    // serializerpre(root);
    // serializerpost(root);
    serializerlevel(root);
    return seri;
}

// 先序遍历反序列化
TreeNode *deserializerpre(std::vector<char>& data) {
    if (data.empty()) return NULL;

    char val = data.front();
    data.erase(data.begin());
    if (val == '#') return NULL;
    TreeNode *root = new TreeNode(val - '0');

    root->left = deserializerpre(data);
    root->right = deserializerpre(data);
    return root;
}

// 后序遍历反序列化
TreeNode *deserializerpost(std::vector<char>& data) {
    if (data.empty()) return NULL;
    
    char val = data.back();
    data.pop_back();
    if (val == '#') return NULL;
    TreeNode *root = new TreeNode(val - '0');
    root->right = deserializerpost(data);
    root->left = deserializerpost(data);
    
    return root;
}

// 层序遍历反序列化
TreeNode *deserializerlevel(std::vector<char>& data) {
    if (data.empty()) return NULL;

    TreeNode *root = new TreeNode(data.front() - '0');
    
    std::queue<TreeNode*> visited;
    visited.push(root);

    for (int i = 1; i < data.size(); i += 2) {
        TreeNode *tmp = visited.front();
        visited.pop();
        if (data[i] == '#') {
            tmp->left = NULL;
        } else {
            tmp->left = new TreeNode(data[i] - '0');
            visited.push(tmp->left);
        }

        if (data[i+1] == '#') {
            tmp->right = NULL;
        } else {
            tmp->right = new TreeNode(data[i+1] - '0');
            visited.push(tmp->right);
        }
    }
    return root;
}

TreeNode *Codec::deserializer(std::string data) {
    std::vector<char> res;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] != ',') {
            res.push_back(data[i]);
        }
    }
    // return deserializerpre(res);
    // return deserializerpost(res);
    return deserializerlevel(res);
}