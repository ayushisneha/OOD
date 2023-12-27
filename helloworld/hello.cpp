#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Tree{
    private:
    TreeNode* root;

    public:
    Tree(){
        root = NULL;
    }

    void insert(TreeNode* node, int x){
        if(node==NULL){
            TreeNode* tmp = new TreeNode(x);
            node = tmp;
            return;
        } else if(node->val>x){
            if(node->left == NULL){
                TreeNode* tmp = new TreeNode(x);
                node->left = tmp;
                return;
            } else {
                insert(node->left, x);
            }
            
        } else{
           if(node->right == NULL){
                TreeNode* tmp = new TreeNode(x);
                node->right = tmp;
                return;
            } else {
                insert(node->right, x);
            }
        }
        return;
    }

    void insert(int x){
        TreeNode* node = new TreeNode(x);
        if(root==NULL){
            TreeNode* node = new TreeNode(x);
            root = node;
        } else{
            insert(root, x);
        }
        return;
    }

    void inOrder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
        return;

    }

    void inOrder(){
        vector<int> v;
        inOrder(root, v);
        cout<<"InOrder Traversal: ";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.clear();
        return;
    }


};


int main(){
    cout<<"Hello Tree"<<endl;
    Tree* tree = new Tree();
    tree->insert(2);
    tree->insert(5);
    tree->insert(7);
    tree->insert(3);
    tree->insert(9);
    tree->inOrder();
    return 0;
}