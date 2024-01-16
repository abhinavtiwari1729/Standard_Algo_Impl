#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node * left ; 
    Node * right ;

    Node(int value) {
        val = value ; 
        left = nullptr ;
        right = nullptr ;
    }
};




void PreorderTraversal(Node * root , vector<Node *> &vc) {

    if (!root)
        return ;
    cout << root->val << " " ;
    vc.push_back(root);
    PreorderTraversal(root->left , vc);
    PreorderTraversal(root->right, vc);
}


Node * BuildTree(Node * root) {

    int data ;
    cout << "enter the data ";
    cin >> data;
    if (data == -1)
        return NULL;
    
    root =  new Node(data);
    cout << "enter the value to be inserted on left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "enter the value to be inserted on right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;

}


void LevelOrderTraversal(Node *root){

    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {

        Node *current_node = q.front();
        q.pop();
        if(current_node->left)
            q.push(current_node->left);
        if(current_node->right)
            q.push(current_node->right);
        
        cout << current_node->val << " ";

    }

}




    bool GetPathForNode(Node * node , const Node * root , vector<const Node *> &vec) {

        if(!root)
            return false;
        vec.push_back(root);
        if (node == root)
            return true; 

        if (GetPathForNode(node , root->left , vec) || GetPathForNode(node , root->right , vec))
            return true;
        
        vec.pop_back();
        return false;

    }








    bool IsGoodNode(Node * node , const Node * root) {

        vector<const Node *> vec;
        cout << endl << "checking for node " << node->val << endl;
        GetPathForNode(node , root , vec);
        for (auto check_node : vec) {
            cout << check_node->val << " ";
            if (check_node->val > node->val)
                return false;
        }
        return true;


    }



    int goodNodesUtil(Node * node , const Node * root) {
        
        if (!node)
            return 0;
        
        if (IsGoodNode(node , root))
            return (1+ (goodNodesUtil(node->left , root)) + goodNodesUtil(node->right , root)); 
        else 
            return  goodNodesUtil(node->left , root) + goodNodesUtil(node->right , root); 
    }




int main() {

    Node * root = nullptr ;
    root = BuildTree(root);
    //vector<Node *> vc;
    // PreorderTraversal(root , vc );
    // cout << endl;
    // for (auto node : vc) {
    //     cout << node->val << " ";
    // }
    //cout << endl;
    //LevelOrderTraversal(root);


    cout << endl << "good nodes in tree is "<< goodNodesUtil(root , root);
}
