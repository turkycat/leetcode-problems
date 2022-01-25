#include "pch.h"
#include "output-manager.h"

using namespace std;
using namespace util;
/*

---------------------------------------
Problem 979
---------------------------------------
Distribute Coins in Binary Tree

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins.
There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another.
A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.


    The number of nodes in the tree is n.
    1 <= n <= 100
    0 <= Node.val <= n
    The sum of all Node.val is n.


---------------------------------------
Strategy
---------------------------------------
Every node needs 1 coin, and 1 move must be made for every coin moved.
Coins may be moved up or down the tree, but only one at a time.
Therefore, the number of moves for any given node is the number of coins that need to be moved to it or through it.

Since we know that all coins will be evenly distributed by the end of the traversal, we can effectively balance each node
from the bottom up (postorder) allowing balances to go negative. the cost for any given node in number of moves is the 
number of coins which much travel through it or to it in order to settle the balance. number of moves is abs(balance)

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * returns the effective balance of this node, total_moves will be increased by the number of moves
 * needed to evenly distribute the coins
 */
int distributeCoinsRecursive(TreeNode* root, size_t &total_moves)
{
    if (root == nullptr) return 0;

    int left_balance = distributeCoinsRecursive(root->left, total_moves);
    int right_balance = distributeCoinsRecursive(root->right, total_moves);
    total_moves += abs(left_balance) + abs(right_balance);
    return left_balance + right_balance + (root->val - 1);
}

int distributeCoins(TreeNode* root) {
    size_t total_moves = 0;
    distributeCoinsRecursive(root, total_moves);
    return static_cast<int>(total_moves);
}

int main(int argc, char** argv){

    TreeNode* root = new TreeNode(3, new TreeNode(0), new TreeNode(0));
    opm.print_string("[3, 0, 0]");
    opm.print_int(distributeCoins(root));

    return 0;
}
