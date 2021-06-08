#include "iostream"

using namespace std;
#define MaxSize 100

// 静态链表节点
struct Node {
    int data;
    int next;
};

typedef Node StaticLinkedList[MaxSize]; // 第一个元素表示头节点

// 遍历静态链表
void travelSal(StaticLinkedList staticLinkedList) {
    Node node = staticLinkedList[0];
    cout << "节点数据:" << node.data << ",节点下一跳:" << node.next << endl;
    while (node.next != -2 && node.next != -1) { // 下一跳不为空
        node = staticLinkedList[node.next];
        cout << "节点数据:" << node.data << ",节点下一跳:" << node.next << endl;
    }
}

// 初始化静态链表
void initList(int data, StaticLinkedList staticLinkedList) {
    for (int i = 0; i < MaxSize; ++i) {
        staticLinkedList[i].next = -1; // c++由于无法判断是否被赋值，人为初始化一个空值。
    }
    staticLinkedList[0].data = data;
    staticLinkedList[0].next = -2; // -2被视为下一跳为空
}

void insertNode(StaticLinkedList staticLinkedList, int data, int pos) {
    int node = staticLinkedList[0].next; // node为头结点的下一个，因为插入第一个需要特殊处理
    pos--; // pos
    while (pos > 1) {
        if (staticLinkedList[node].next != -2) {
            node = staticLinkedList[node].next; // node数值后移
            --pos;
        } else {
            cout << "插入位置非法" << endl;
            return;
        }
    }
    if (pos == 0) { // 要做头插，特殊处理
        for (int i = 0; i < MaxSize; ++i) {
            if (staticLinkedList[i].next == -1) { // next==-1,视为遇到空位置
                staticLinkedList[i].data = staticLinkedList[0].data;
                staticLinkedList[i].next = staticLinkedList[0].next;
                staticLinkedList[0].data = data;
                staticLinkedList[0].next = i;
                return;
            }
        }
        cout << "链表已满" << endl;
    }

    for (int i = 0; i < MaxSize; ++i) {
        if (staticLinkedList[i].next == -1) { // next==-1,视为遇到空位置
            staticLinkedList[i].data = data; // 插入数据
            staticLinkedList[i].next = staticLinkedList[node].next;
            staticLinkedList[node].next = i; // 修改上一个node的next
            cout << "修改后node的下一跳：" << staticLinkedList[node].next << endl;
            return;
        }
    }
    cout << "链表已满" << endl;
}

// 删除某一结点
void deleteNode(StaticLinkedList staticLinkedList, int pos) {
    if (pos = 1) { // 删除头节点特殊处理
        // 将头节点的下一个节点移动到头部
        if (staticLinkedList[0].next != -2) {
            int next = staticLinkedList[0].next;
            staticLinkedList[0].data = staticLinkedList[next].data;
            staticLinkedList[0].next = staticLinkedList[next].next;
            staticLinkedList[next].next = -1; // 将移动后的节点设置为空
        } else { // 说明只有一个节点
            staticLinkedList[0].data = NULL;
            staticLinkedList[0].next = -1;
        }
    }

    int node = staticLinkedList[0].next; // 删除头节点特殊处理
    while (pos > 1) {
        if (staticLinkedList[node].next != -2) {
            node = staticLinkedList[node].next; // node数值后移
            --pos;
        } else {
            cout << "删除位置非法" << endl;
        }
    }
    int next = staticLinkedList[node].next;
    staticLinkedList[node].next = staticLinkedList[next].next;
    staticLinkedList[next].next = -1; // 设为空
}

int main() {
    StaticLinkedList staticLinkedList;// 初始化静态链表
    initList(10, staticLinkedList);
    insertNode(staticLinkedList, 20, 1);
    insertNode(staticLinkedList, 1999, 2);
    insertNode(staticLinkedList, 1978, 1);
    deleteNode(staticLinkedList,2);
    deleteNode(staticLinkedList,1);
    deleteNode(staticLinkedList,1);
//    insertNode(staticLinkedList,213,4);
//    insertNode(staticLinkedList,213,4);
    travelSal(staticLinkedList);

}
