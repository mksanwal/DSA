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

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper functions for recursion
    Node* insert(Node* node, int val);
    void inorderRecursive(Node* node);
    void preorderRecursive(Node* node);
    void postorderRecursive(Node* node);
    int findHeight(Node* node);
    Node* cloneTree(Node* node);
    void deleteTree(Node*& node);
    Node* mirrorTree(Node* node);
    bool areEqual(Node* node1, Node* node2);
    Node* constructTreeHelper(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap);
    Node* deleteNode(Node* node, int key);

public:
    BST() { root = nullptr; }
    void insert(int val) { root = insert(root, val); }
    void inorder() { inorderRecursive(root); cout << endl; }
    void preorder() { preorderRecursive(root); cout << endl; }
    void postorder() { postorderRecursive(root); cout << endl; }
    void inorderIterative();
    void preorderIterative();
    void postorderIterative();
    int height() { return findHeight(root); }
    BST clone();
    void erase() { deleteTree(root); }
    void mirror() { root = mirrorTree(root); }
    static bool isEqual(BST& t1, BST& t2);
    static BST constructFromPreIn(vector<int>& inorder, vector<int>& preorder);
    void deleteNode(int key) { root = deleteNode(root, key); }
};

// Insert function (recursive)
Node* BST::insert(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->data) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}

// Recursive Traversals
void BST::inorderRecursive(Node* node) {
    if (!node) return;
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

void BST::preorderRecursive(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}

void BST::postorderRecursive(Node* node) {
    if (!node) return;
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}

// Iterative Inorder Traversal
void BST::inorderIterative() {
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Iterative Preorder Traversal
void BST::preorderIterative() {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top(); s.pop();
        cout << node->data << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    cout << endl;
}

// Iterative Postorder Traversal
void BST::postorderIterative() {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// Find height of tree
int BST::findHeight(Node* node) {
    if (!node) return 0;
    return 1 + max(findHeight(node->left), findHeight(node->right));
}

// Clone the tree
BST BST::clone() {
    BST newTree;
    newTree.root = cloneTree(root);
    return newTree;
}

Node* BST::cloneTree(Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->data);
    newNode->left = cloneTree(node->left);
    newNode->right = cloneTree(node->right);
    return newNode;
}

// Mirror the tree
Node* BST::mirrorTree(Node* node) {
    if (!node) return nullptr;
    Node* mirrored = new Node(node->data);
    mirrored->left = mirrorTree(node->right);
    mirrored->right = mirrorTree(node->left);
    return mirrored;
}

// Check if two trees are equal
bool BST::areEqual(Node* node1, Node* node2) {
    if (!node1 && !node2) return true;
    if (!node1 || !node2 || node1->data != node2->data) return false;
    return areEqual(node1->left, node2->left) && areEqual(node1->right, node2->right);
}

bool BST::isEqual(BST& t1, BST& t2) {
    return t1.areEqual(t1.root, t2.root);
}

// Construct tree from inorder and preorder
Node* BST::constructTreeHelper(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;
    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int inIndex = inMap[rootVal];
    root->left = constructTreeHelper(inorder, preorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = constructTreeHelper(inorder, preorder, preIndex, inIndex + 1, inEnd, inMap);
    return root;
}

BST BST::constructFromPreIn(vector<int>& inorder, vector<int>& preorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    int preIndex = 0;
    BST tree;
    tree.root = tree.constructTreeHelper(inorder, preorder, preIndex, 0, inorder.size() - 1, inMap);
    return tree;
}

// Delete node from BST
Node* BST::deleteNode(Node* node, int key) {
    if (!node) return nullptr;
    if (key < node->data) node->left = deleteNode(node->left, key);
    else if (key > node->data) node->right = deleteNode(node->right, key);
    else {
        if (!node->left) return node->right;
        if (!node->right) return node->left;
    }
    return node;
}

void displayMenu() {
    cout << "1. Insert a Node" << endl;
    cout << "2. Inorder Traversal" << endl;
    cout << "3. Preorder Traversal" << endl;
    cout << "4. Postorder Traversal" << endl;
    cout << "5. Inorder Iterative Traversal" << endl;
    cout << "6. Preorder Iterative Traversal" << endl;
    cout << "7. Postorder Iterative Traversal" << endl;
    cout << "8. Find Tree Height" << endl;
    cout << "9. Mirror Tree" << endl;
    cout << "10. Clone Tree" << endl;
    cout << "11. Delete a Node" << endl;
    cout << "12. Check if two tree are equal or not" << endl;
    cout << "13. Exit" << endl;
}

int main() {
    BST tree;
    int choice, value;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) { 
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Inorder Iterative Traversal: ";
                tree.inorderIterative();
                break;
            case 6:
                cout << "Preorder Iterative Traversal: ";
                tree.preorderIterative();
                break;
            case 7:
                cout << "Postorder Iterative Traversal: ";
                tree.postorderIterative();
                break;
            case 8:
                cout << "Tree Height: " << tree.height() << endl;
                break;
            case 9:
                tree.mirror();
                cout << "Tree mirrored!" << endl;
                break;
            case 10:
                tree.clone();
                cout << "Tree cloned!" << endl;
                break;
            case 11:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                cout << "Node deleted" << endl;
                break;
            case 12:
                cout<<"Create 2nd Tree"<<endl;
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);

                tree.isEqual() ;
                break;
            case 13:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}