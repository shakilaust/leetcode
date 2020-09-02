/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    vector < string > dataStream;
    int curIdx = 0;
    
    
     string treeToString(TreeNode* root, bool isRoot) { 
        if( root == NULL ) return isRoot ? "#": " #";
        string now = isRoot ? to_string(root->val) : " " + to_string(root->val);
        return now + treeToString(root->left , false ) + treeToString(root->right, false);
    }
    
    string serialize(TreeNode* root) {
         return treeToString(root, true);
    }
    
    
    TreeNode* stringToTree() { 
        string now = dataStream[curIdx++];
        if( now == "#" ) return NULL;
        TreeNode* curNode = new TreeNode(stoi(now));
        curNode->left = stringToTree();
        curNode->right = stringToTree();
        return curNode;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        dataStream.clear();
        stringstream ss(data);
        string now;
        while( ss >> now ) { 
            dataStream.push_back(now);
        }
        curIdx = 0;
        return stringToTree();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
