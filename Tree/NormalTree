#include "iostream"
#include "vector"
#include "queue"
#define MaxSize 5 // 规定一个节点最多有5个孩子
using namespace std;

typedef struct nTree *Tree;
// 一棵普通树
struct nTree {
    int data;
    vector<Tree> child;
};


// 判空
bool isEmpty(nTree t) {
    if (t.data) {
        return false;
    } else {
        return true;
    }
}

// 层次遍历
void levelOrderTraversal(Tree t) {
    queue<Tree> queue; //queue的参数一定要是Tree，若为nTree则找不到孩子结点的孩子 2021/7/30 40分钟找这个bug
    Tree p;
    queue.push(t); // 根入队列
    while (!queue.empty()) {
        p = queue.front();
        queue.pop();
        cout << p->data << ";";
        for (int i = 0; i < p->child.size(); ++i) { // 有孩子节点
            queue.push(p->child[i]);
        }
    }
}

// 获取树的高度
int getHeight(Tree t) {
    int height = 1;
    if (t->child.size() == 0){ // 没有孩子了
        return height;
    }

    for (int i = 0; i < t->child.size(); ++i) {
        height = max(height,getHeight(t->child[i])+1);
    }
    return height;
}

// e为需要添加的元素
void insertChild(nTree *t, nTree *e) {
    if (t->child.size() < MaxSize) {
        t->child.push_back(e);
        cout << "节点:" << t->data << " 插入数据:" << e->data << " 成功！" << endl;
    } else {
        cout << "当前节点孩子已满!" << endl;
    }
}


int main() {
    Tree head = new nTree{9};
// 测试 =========================================
    Tree node0 = new nTree{10};
    Tree node1 = new nTree{423};
    Tree node2 = new nTree{5343};
    Tree node3 = new nTree{6323};
    Tree node4 = new nTree{723230};
    Tree node5 = new nTree{987};
    Tree node6 = new nTree{4};
    Tree node7 = new nTree{7};
    Tree node8 = new nTree{1};
    Tree node9 = new nTree{43};

    insertChild(head, node0);
    insertChild(head, node1);
    insertChild(head, node2);
    insertChild(head, node3);
    insertChild(node1, node4);
    insertChild(node2, node5);
    insertChild(node3, node6);
    insertChild(node3, node7);
    insertChild(node3, node8);
    insertChild(node7, node9);

    levelOrderTraversal(head);

    cout << "树的高度为:" << getHeight(head) << endl;
//  =========================================

    return 0;
}
