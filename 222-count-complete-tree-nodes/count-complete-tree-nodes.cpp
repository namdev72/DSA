
class Solution {
public:
void inorder(TreeNode* root,int& num)
    {
        if(root==NULL) return;
        inorder(root->left,num);
        num++;
        inorder(root->right,num);
    }
    int countNodes(TreeNode* root) {
         int num=0;
        inorder(root,num);
        return num;
    }
};