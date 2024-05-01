// Begin of template
#include <iostream>

using namespace std;
// End of template

typedef struct LNode {
    int data;
    struct LNode *next;
    struct LNode *prev;

    LNode(int val) : data(val), next(nullptr), prev(nullptr) {}
} LNode;

typedef struct TNode {
    int data;
    struct TNode *right;
    struct TNode *left;

    TNode(int val) : data(val), right(nullptr), left(nullptr) {}

} TNode;


void addHead(LNode *&head, int val) {
    LNode *node = new LNode(val);

    node->next = head;
    head = node;
}

void addTail(LNode *&head, int val) {
    LNode *node = new LNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }

    LNode *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = node;
}

void insertAfter(LNode *&head, int target, int val) {
    bool inserted = false;
    for (LNode *node = head; node != nullptr; node = node->next) {

        if (inserted) {
            break;
        }

        if (node->data == target) {

            if (node->next == nullptr) {
                addTail(head, val);

                break;
            }

            LNode *temp = new LNode(val);

            temp->next = node->next;
            node->next = temp;

            inserted = true;
        } else {
            if (node->data != target && node->next == nullptr) {
                inserted = true;
                addHead(head, val);
            }
        }
    }
}


bool isExisted(LNode *head, int val) {
    for (LNode *node = head; node != nullptr; node = node->next) {
        if (node->data == val) {
            return 1;
        }
    }

    return 0;
}


void insertTreeNode(TNode *&root, int val) {
    if (root != nullptr) {
        if (root->data > val) {
            insertTreeNode(root->left, val);
        } else if (root->data < val) {
            insertTreeNode(root->right, val);
        }
    }

    if (root == nullptr || root->data == val) {
        root = new TNode(val);
    }
}

void listToTree(LNode *head, TNode *&root) {
    for (LNode *node = head; node != nullptr; node = node->next) {
        insertTreeNode(root, node->data);
    }
}

int getHeight(TNode *tree) {
    if (tree == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(tree->left);

    int rightHeight = getHeight(tree->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

void printList(LNode *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

void printPreorder(TNode *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    int option = 0;

    LNode *head = nullptr;

    while (1) {
        cin >> option;

        if (option == 3) {
            break;
        }

        switch (option) {
            case 0: {
                int val;
                cin >> val;

                if (isExisted(head, val)) {
                    break;
                }

                addHead(head, val);
            }

                break;

            case 1: {
                int val;
                cin >> val;

                if (isExisted(head, val)) {
                    break;
                }

                addTail(head, val);
            }

                break;

            case 2: {
                int target;
                cin >> target;

                int val;
                cin >> val;

                if (isExisted(head, val)) {
                    break;
                }

                if (isExisted(head, target)) {
                    insertAfter(head, target, val);
                } else {
                    addHead(head, val);
                }
            }

                break;

        }
    }

    TNode *root = nullptr;

    listToTree(head, root);

    cout << getHeight(root) - 1;


}