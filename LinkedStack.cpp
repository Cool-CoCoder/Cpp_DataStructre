#include "iostream"
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef Node *lHead;

void initStack(Node *h){
    h->next = nullptr;
}

bool stackEmpty(Node *head){
    if (head->next){
        return false;
    } else{
        return true;
    }
}

void push(Node *h,Node *node){
    while (h->next){
        h = h->next;
    }
    node->next = nullptr;
    h->next = node; // 放入栈接在后面
}

int pop(Node *head){
    if (!stackEmpty(head)){
        int result = head->next->data;
        head->next = head->next->next; // 指向后方元素，将head后元素弹出
        return result;
    } else{
        cout << "栈为空" << endl;
        return NULL;
    }
}

int main(){
    lHead head;
    initStack(head);
    Node node1 = Node{10, nullptr};
    Node node2 = Node{10, nullptr};
    Node node3 = Node{10, nullptr};
    Node node4 = Node{10, nullptr};
    Node node5 = Node{10, nullptr};
    push(head,&node1);
    push(head,&node2);
    push(head,&node3);
    push(head,&node4);
    push(head,&node5);
    cout << "弹出元素为:" << pop(head) << endl;
    cout << "弹出元素为:" << pop(head) << endl;
    cout << "弹出元素为:" << pop(head) << endl;
    cout << "弹出元素为:" << pop(head) << endl;
    cout << "弹出元素为:" << pop(head) << endl;
}
