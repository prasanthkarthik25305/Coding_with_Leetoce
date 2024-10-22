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
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        long long sum=0;
        priority_queue<long long>pq;
        while(!q.empty()){
            long long n=q.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            pq.push(sum);
        }
        if(pq.size()<k) return -1;
    k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};