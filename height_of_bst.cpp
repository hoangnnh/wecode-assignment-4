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

int getHeight(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);

    int rightHeight = getHeight(root->right);

    if (leftHeight >= rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

int main() {
    int n;
    cin >> n;

    Node *root = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(root, val);
    }

    cout << getHeight(root) - 1;

    return 0;
}
