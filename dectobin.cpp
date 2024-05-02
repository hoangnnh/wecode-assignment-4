
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;

    struct LNode *next;

    LNode(int val) : data(val), next(nullptr) {}
} LNode;

void addHead(LNode *&head, int val) {
    LNode *node = new LNode(val);

    node->next = head;
    head = node;
}

void printList(LNode *head) {
    for (LNode *temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->data;
    }
}


int main() {
    LNode *bin = nullptr;

    int dec;
    cin >> dec;

    while (dec != 0) {
        addHead(bin, dec % 2);
        dec /= 2;
    }

    printList(bin);
}