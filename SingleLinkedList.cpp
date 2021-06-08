#include "iostream"

using namespace std;

typedef int ElementType;

struct Node {
    ElementType data;
    Node *next;
};

// 初始化节点
void initLinkedList(Node node) {
    // 定义一个头节点
    node.data = NULL;
    node.next = nullptr;
}

// 插入元素
void insert(Node *head, Node *node) {
    while (head->next) {
        head = head->next;
    }
    head->next = node;
}


// 插入到指定位置
void insertNode(Node *head, Node *node, int pos) {
    if (pos < 1) {
        cout << "插入位置非法" << endl;
        return;
    }
    while (pos > 1) {
        if (head->next) {
            head = head->next;
            pos--;
        } else {
            cout << "位置超过链表长度~" << endl;
            return;
        }
    }
    node->next = head->next;
    head->next = node;
}

//删除指定位置元素
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
            cout << "位置超过链表长度" << endl;
            break;
        }
    }
    // pos = 1 定位到要删除节点前一个结点，如果删除后后面还有节点,则head->next = head->next->next;
    // 否则 head->next = nullptr;
    if (head->next) {
        head->next = head->next->next;
    } else {
        head->next = nullptr;
    }
}

// 遍历链表
void travelSal(Node *head) {
    while (head->next) {
        head = head->next;
        cout << "节点值为:" << head->data << endl;
    }
}

int main() {
    Node head;
    initLinkedList(head); // 初始化链表
    Node node = {10, nullptr};
    Node node1 = {11, nullptr};
    Node node2 = {11, nullptr};

    insertNode(&head,&node, 1);
    insertNode(&head, &node1, 1);
    insertNode(&head, &node2, 1);
    deleteNode(&head, 1);
    travelSal(&head);
    return 0;
}