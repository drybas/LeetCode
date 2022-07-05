/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//  617. Merge Two Binary Trees
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
         
        return Traverse(NULL, t1, t2); 
    }
        TreeNode* Traverse(TreeNode* newSubTree, TreeNode* t1, TreeNode* t2)
        {
            int value = 0;
            value += t1 ? t1->val : 0;
            value += t2 ? t2->val : 0; 
            
           TreeNode node = new TreeNode(value);    
           std::queue<std::pair<TreeNode, TreeNode>> nodes;
            
           if (t1)
           {
              auto newLeftPairs = make_pair(t1->left, (t2) ? t2->left : nullptr); 
              nodes.push_back(newLeftPair);
              auto newRightPairs = make_pair(t1->right, (t2) ? t2->right : nullptr);
              nodes.push_back(newRightPair);
           } 
           else 
           {
               if (t2)
               {
                    nodes.push_back(std::make_pair(nullptr, t2->left));
                    nodes.push_back(std::make_pair(nullptr, t2->right));
               }
           } 
                                   
           if (nodes.empty())
           {
               return ;
           }
            
           while (!nodes.empty()) 
           {
               if (nodes.front() )
                    newSubTree->left = ;
              newSubTree->right = ;
           }
        }
};