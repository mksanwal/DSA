#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BT{
private:
    Node* root;
    Node* insertBTnode(Node* node, int val);
    void inorderRecursive(Node* node);
    void preorderRecursive(Node* node);
    void postorderRecursive(Node* node);
    int findHeight(Node* node);
    void levelOrderTraversal(Node* node);
    Node* cloneTree(Node* node);
    Node* mirrorTree(Node* node);
    bool areEqual(Node* node1, Node* node2);

public:
    BT(){
        root = nullptr;
    }
    void insertBT(int val){ root = insertBTnode(root,val); }
    void inorder() { inorderRecursive(root); cout << endl; }
    void preorder() { preorderRecursive(root); cout << endl; }
    void postorder() { postorderRecursive(root); cout << endl; }
    void inorderIterative();
    void preorderIterative();
    void postorderIterative();
    int height() { return findHeight(root); }
    void levelorder() { levelOrderTraversal(root); cout<<endl; }
    BT clone();
    void mirror() { root = mirrorTree(root); }
    static bool isEqual(BST& t1, BST& t2);
};

Node* BT:: insertBTnode(int val){
    node* p = new node(val);
    if(root==nullptr){
        root = p;
        return;
    }
    else{
        node *t = root;
        while(true){
            int choice;
            cout<<"Enter 0 for left and 1 for right: "<<endl;
            cin>>choice;
            if(t->(choice == 0? left : right)==nullptr){
                t->(choice == 0? left : right) = p;
                return root;
            }
            else{
                t = t->(choice == 0? left : right);
            }
        }
    }
}

// Recursive Traversals
void BT::inorderRecursive(Node* node) {
    if (!node) return;
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

void BT::preorderRecursive(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}

void BT::postorderRecursive(Node* node) {
    if (!node) return;
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}

void BT::inorderIterative(){
    stack<Node*> st;
    Node* curr = root;
    while(curr != nullptr || !st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top(); st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
    cout<<endl;
}

void BT::preorderIterative(){
    if(!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top(); st.pop();
        cout<< node->data <<" ";
        if(node->right) st.push(node->right); 
        if(node->left) st.push(node->left); 
    }
    cout<<endl;    
}

void BT::postorderIterative(){
    if(!root) return;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!s1.empty()){
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s2.push(node->right);
    }
    while(!s2.empty()){
        cout<<st2.top()->data<<" ";
        s2.pop();
    }
    cout<<endl;
}

void BT::findHeight(Node* node){
    if(!node) return 0;
    return 1 + max(findHeight(node->left),findHeight(node->right));
}

void BT:: levelOrderTraversal(Node* node){
    if(!node) return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* top = q.front();
            q.pop();
            cout<<top->data<<" ";
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        cout<<endl;
    }
    cout<<endl;
}

BT BT::clone() {
    BST newTree;
    newTree.root = cloneTree(root);
    return newTree;
}

Node* BT::cloneTree(Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->data);
    newNode->left = cloneTree(node->left);
    newNode->right = cloneTree(node->right);
    return newNode;
}

Node* BT::mirrorTree(Node* node) {
    if (!node) return nullptr;
    Node* mirrored = new Node(node->data);
    mirrored->left = mirrorTree(node->right);
    mirrored->right = mirrorTree(node->left);
    return mirrored;
}

Node* BT:: areEqual(Node* node1,Node* node2){
    if(!node1 && !node2) return true;
    if(!node1 || !node2 || node1->data != node2->data) return false;
    return areEqual(node1->left,node2->left) && areEqual(node2->left,node2->right);
}

bool BT::isEqual(BST& t1, BST& t2) {
    return t1.areEqual(t1.root, t2.root);
}

void showMenu() {
    cout << "Binary Tree Menu" << endl;
    cout << "1. Insert node into Binary Tree" << endl;
    cout << "2. Inorder Traversal (Recursive)" << endl;
    cout << "3. Preorder Traversal (Recursive)" << endl;
    cout << "4. Postorder Traversal (Recursive)" << endl;
    cout << "5. Inorder Traversal (Iterative)" << endl;
    cout << "6. Preorder Traversal (Iterative)" << endl;
    cout << "7. Postorder Traversal (Iterative)" << endl;
    cout << "8. Find Height of Binary Tree" << endl;
    cout << "9. Level Order Traversal" << endl;
    cout << "10. Mirror the Tree" << endl;
    cout << "11. Clone the Tree" << endl;
    cout << "12. Check if Two Trees are Equal" << endl;
    cout << "13. Exit" << endl;
}

int main() {
    BT tree1;
    BT tree2;
    int choice, val;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                cout << "Enter value to insert: ";
                cin >> val;
                tree1.insertBT(val);
                break;
            case 2: 
                cout << "Inorder Traversal (Recursive): ";
                tree1.inorder();
                break;
            case 3:
                cout << "Preorder Traversal (Recursive): ";
                tree1.preorder();
                break;
            case 4:
                cout << "Postorder Traversal (Recursive): ";
                tree1.postorder();
                break;
            case 5:
                cout << "Inorder Traversal (Iterative): ";
                tree1.inorderIterative();
                break;
            case 6:
                cout << "Preorder Traversal (Iterative): ";
                tree1.preorderIterative();
                break;
            case 7:
                cout << "Postorder Traversal (Iterative): ";
                tree1.postorderIterative();
                break;
            case 8:
                cout << "Height of Tree: " << tree1.height() << endl;
                break;
            case 9:
                cout << "Level Order Traversal: ";
                tree1.levelorder();
                break;
            case 10:
                tree1.mirror();
                cout << "Tree has been mirrored." << endl;
                break;
            case 11:
                tree2 = tree1.clone();
                cout << "Tree has been cloned." << endl;
                break;
            case 12:
                if (BT::isEqual(tree1, tree2)) 
                    cout << "The trees are equal." << endl;
                else 
                    cout << "The trees are not equal." << endl;
                break;
            case 13:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 13);

    return 0;
}
