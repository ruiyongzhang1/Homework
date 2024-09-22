#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};//初始化函数定义
  };//定义二叉树的一个节点
class Solution {
public:
   
    int maxPathSum1(TreeNode* root,int &val) {
        if(root==nullptr)return 0;
        int left=maxPathSum1(root->left,val);//左子树路径最大值；
        int right=maxPathSum1(root->right,val);//右子树路径最大值
        int Situation1=root->val+max(0,left)+max(0,right);
        int Situation2=root->val+max(0,max(left,right));
        val=max(val,max(Situation1,Situation2));
        return Situation2;
    }
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum1(root, val);
        return val;
    }
    void precreateTreeNode(vector<int>& array, int& index, TreeNode*& root) {  
        if (index >= array.size()) return; // 检查索引是否越界  
        root = new TreeNode(array[index++]); // 创建根节点并递增索引                                       
        precreateTreeNode(array, index, root->left);  // 递归构建左子树  
        precreateTreeNode(array, index, root->right);  // 递归构建右子树  
   }
};
int main(){
    vector<int>array(100);
    cout<<"请输入要储存的元素个数"<<endl;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    int index=0;
    Solution myobject;
    TreeNode*root=nullptr;
    myobject.precreateTreeNode(array,index,root);
    int ans=myobject.maxPathSum(root);
    cout<<ans<<endl;
    return 0;
}