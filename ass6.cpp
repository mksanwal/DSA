#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node* insert(node* root, int val) {
    node* p = new node(val);
    if (root == nullptr) {
        root = p;
        return p;
    }
    else {
        node *t = root;
        while (true) {
            int choice;
            cout << "Enter 0 or 1 (left/right): ";
            cin >> choice;
            if (choice == 0) {
                if (t->left == nullptr) {
                    t->left = p;
                    return root;
                }
                else {
                    t = t->left;
                }
            }
            else {
                if (t->right == nullptr) {
                    t->right = p;
                    return root;
                }
                else {
                    t = t->right;
                }
            }
        }
    }
}

void inorder(node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> inOrder(node* root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

void preorder(node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

vector<int> preOrder(node* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

void postorder(node* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> postOrder(node* root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
}

int main() {
    node* root = nullptr;
    while (true) {
        int choice;
        cout <<"1 => to enter node,   2=> to print tree,   3=> Exit \n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value of the node: ";
            int val;
            cin >> val;
            root = insert(root, val);
        }
        else if (choice == 2) {
            vector<int> ans = preOrder(root);
            cout << "Preorder: ";
            for (auto& i : ans) {
                cout << i << " ";
            }
            cout << endl;

            ans = inOrder(root);
            cout << "Inorder: ";
            for (auto& i : ans) {
                cout << i << " ";
            }
            cout << endl;

            ans = postOrder(root);
            cout << "PostOrder: ";
            for (auto& i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            break;
        }
    }
}
