// Template
#include <iostream>

using namespace std;
// End of template

typedef struct Node {
    string val;
    struct Node *left;
    struct Node *right;

    Node(string str) : val(str), left(nullptr), right(nullptr) {}
} Node;

Node *insertNode(Node *&root, string str) {
    if (root == nullptr) {
        return new Node(str);
    }

    if (str.compare(root->val) < 0) {
        root->left = insertNode(root->left, str);
    } else if (str.compare(root->val) > 0) {
        root->right = insertNode(root->right, str);
    }

    return root;
}


Node *deleteNodes(Node *&root, string str) {
    if (root == nullptr) {
        return nullptr;
    }

    root->left = deleteNodes(root->left, str);
    root->right = deleteNodes(root->right, str);

    if (root->val == str) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else {
            Node *successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            root->val = successor->val;
            root->right = deleteNodes(root->right, successor->val);
        }
    }

    return root;
}

Node *searchNode(Node *root, string str) {
    if (root == nullptr || root->val == str) {
        return root;
    }

    if (str.compare(root->val) < 0) {
        return searchNode(root->left, str);
    } else {
        return searchNode(root->right, str);
    }
}


int main() {
    Node *root = nullptr;

    int option;

    string keyword;

    while (1) {
        cin >> option;

        if (option == 0) {
            break;
        }

        cin >> keyword;

        switch (option) {
            case 1:
                root = insertNode(root, keyword);
                break;

            case 3:
                root = deleteNodes(root, keyword);
                break;

            case 2: {
                Node *result = searchNode(root, keyword);
                if (result != nullptr) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
                break;


            default:
                break;
        }
    }
    return 0;
}