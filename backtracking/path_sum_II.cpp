#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        this->helper(root, targetSum, 0, {}, res);
        return res;
    }
    void helper(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &res)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            if ((sum + root->val) == targetSum)
            {
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        sum += root->val;
        helper(root->left, targetSum, sum, temp, res);
        helper(root->right, targetSum, sum, temp, res);
        sum -= root->val;
        temp.pop_back();
    }
};

int main()
{

    return 0;
}