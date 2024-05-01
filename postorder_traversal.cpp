#include <iostream>

using std::cout, std::cin;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
} Node;

void insertNode(Node *&root, int val) {

    if (root != nullptr) {
        if (root->data > val) {
            insertNode(root->left, val);
        } else if (root->data < val) {
            insertNode(root->right, val);
        }
    }

    if (root == nullptr || root->data == val) {
        root = new Node(val);
    }
}

void printPostorder(Node *root) {
    if (root != nullptr) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    cin >> n;

    Node *root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, data);
    }

    printPostorder(root);

    return 0;
}

