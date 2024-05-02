
#include <iostream>

using namespace std;


typedef struct Node {
    int data;

    struct Node *left;
    struct Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
} Node;

typedef struct LNode {
    int data;

    struct LNode *next;

    LNode(int val) : data(val), next(nullptr) {}
} LNode;


Node *insertNode(Node *&root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (root->data > val) {
        root->left = insertNode(root->left, val);
    } else if (root->data < val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}


void appendList(LNode *&head, int val) {
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


void castListInorder(Node *root, LNode *&list) {
    if (root != nullptr) {
        castListInorder(root->left, list);
        appendList(list, root->data);
        castListInorder(root->right, list);
    }
}

int sumOfGreaterThanOrEqual(LNode *head, int start) {
    LNode *temp = head;
    int sum = 0;

    while (temp != nullptr) {
        if (start <= temp->data) {
            sum += temp->data;
        }

        temp = temp->next;
    }

    return sum;
}

int main() {
    int size{0};
    cin >> size;

    Node *root = nullptr;

    for (int i = 0; i < size; i++) {
        int val{0};
        cin >> val;

        root = insertNode(root, val);
    }

    LNode *head = nullptr;

    castListInorder(root, head);
    LNode *temp = head;

    while (temp != nullptr) {
        cout << sumOfGreaterThanOrEqual(temp, temp->data) << " ";
        temp = temp->next;
    }
}