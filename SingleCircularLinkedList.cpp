#include "iostream"
using namespace std;

typedef int ElementType;
// 循环单链表，感觉和循环双链表差不多
struct Node{
    ElementType data;
    Node *next;
};

// 初始化节点,初始时循环链表next指向自己
void initLinkedList(Node *node){
    node->data = NULL;
    node->next = node;
}

void travelSal(Node *head){
    while(head->next->data){
        head = head->next;
        cout << "当前节点的数据为" <<head->data << endl;
    }
}

// 插入到指定位置
void insertNode(Node *head,Node *node,int pos){
    Node *true_head = head;
    if (pos < 1){
        cout << "插入位置非法" << endl;
        return;
    }

    while(pos > 1){
        if (head->next->data != NULL){
            head = head->next;
            pos--;
        } else{
            cout << "位置超过链表长度" << endl;
            return;
        }
    }
    node->next = head->next;
    head->next = node;
    head->next->next = true_head;
}

void deleteNode(Node *head,int pos){
    if (pos < 1 ){
        cout << "删除位置非法" << endl;
        return;
    }
    while(pos > 1){
        if (head->next->data != NULL){
            head = head->next;
            pos--;
        } else{
            cout << "删除位置超过链表长度" << endl;
            return;
        }
    }
    head->next = head->next->next;
}

int main(){
    Node head;
    initLinkedList(&head);
    Node node = {10, nullptr};
    Node node1 = {13, nullptr};
    Node node2 = {11, nullptr};
    Node node3 = {19, nullptr};
    insertNode(&head,&node,1);
    insertNode(&head,&node1,2);
    insertNode(&head,&node2,3);
    insertNode(&head,&node3,4);
    travelSal(&head);
    cout << "删除元素~" << endl;
    deleteNode(&head,4);
    travelSal(&head);
}