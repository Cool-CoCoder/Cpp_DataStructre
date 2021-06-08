#include "iostream"

using namespace std;

typedef int ElemType;

struct Node {
    ElemType data;
    Node *pre;
    Node *next;
};

// 初始化链表
void initList(Node *node) {
    node->data = NULL;
    node->pre = nullptr;
    node->next = nullptr;
}

// 插入到指定位置,定义一个返回
void insertPos(Node *head, Node *node, int pos) {
    if (pos < 1) {
        cout << "插入位置非法" << endl;
        return;
    }
    while (pos > 1) {
        if (head->next) {
            head = head->next;
            pos--;
        } else {
            cout << "插入位置非法" << endl;
            return;
        }
    }
    node->next = head->next;
    head->next->pre = node;
    node->pre = head;
    head->next = node;
}

// 插入元素
void insertList(Node *head, Node *node) {
    while (head->next) {
        head = head->next;
    }
    node->pre = head;
    head->next = node;
}

void deleteNode(Node *head, int pos) {
    if (pos < 1) {
        cout << "删除位置非法" << endl;
        return;
    }
    while (pos > 1) {
        if (head->next) {
            head = head->next;
            pos--;
        } else {
            cout << "删除位置非法" << endl;
            return;
        }
    }
    head->next = head->next->next;
    head->next->next->pre = head;

}

// 遍历链表
void print(Node *head) {
    while (head->next) {
        head = head->next;
        cout << head->data << endl;
    }

}

int main() {
    Node head;
    initList(&head);

    Node node = {1, nullptr, nullptr};
    Node node1 = {20, nullptr, nullptr};
    Node node2 = {30, nullptr, nullptr};
    Node node3 = {99, nullptr, nullptr};
    Node node4 = {7, nullptr, nullptr};
    insertList(&head, &node);
    insertList(&head, &node1);
    insertList(&head, &node2);
    insertList(&head, &node3);
    insertList(&head, &node4);

    Node node5 = {18, nullptr, nullptr};
    insertPos(&head, &node5, 4);
    print(&head);
    deleteNode(&head,3);
    cout << "删除后~" <<endl;
    print(&head);
}