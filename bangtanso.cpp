
#include <iostream>

using namespace std;


typedef struct Node {
    int data;
    int freq;

    struct Node *left;
    struct Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {
        if (data == val) {
            freq++;
        }
    }
} Node;

Node *insertNode(Node *&root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (root->data > val) {
        root->left = insertNode(root->left, val);
    } else if (root->data < val) {
        root->right = insertNode(root->right, val);
    }

    if (root->data == val) {
        root->freq++;
    }

    return root;
}

Node *searchNode(Node *root, int val) {
    if (root == nullptr || root->data == val) {
        return root;
    }

    if (root->data > val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}

void printInorder(Node *root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->data << " " << root->freq << "\n";
        printInorder(root->right);
    }
}


int main() {
    Node *root = nullptr;

    int input;

    while (1) {
        cin >> input;

        if (input == 0) {
            break;
        }

        root = insertNode(root, input);
    }

    printInorder(root);

    return 0;
}