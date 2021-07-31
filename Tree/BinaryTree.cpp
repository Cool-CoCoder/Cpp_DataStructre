#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

typedef struct TreeNode *BinTree;
struct TreeNode {
    int Data;  // 存值
    BinTree Left;    // 左儿子结点
    BinTree Right;   // 右儿子结点
};

BinTree CreatBinTree();   // 创建一个二叉树
bool IsEmpty(BinTree BT);  // 判断树 BT 是否为空
void PreOrderTraversal(BinTree BT);   // 先序遍历，根左右
void InOrderTraversal(BinTree BT);    // 中序遍历，左根右
void PostOrderTraversal(BinTree BT);  // 后序遍历，左右根
typedef struct SNode *Stack;

struct SNode {
    BinTree Data;
    Stack Next;
};

BinTree Insert(int Data) {
    BinTree BT;
    BT = (BinTree) malloc(sizeof(struct TreeNode));
    BT->Data = Data;
    BT->Left = NULL;
    BT->Right = NULL;
    return BT;
}

// 初始化二叉树
BinTree CreatBinTree() {
    BinTree BT;
    BT = (BinTree) malloc(sizeof(struct TreeNode));
    BT->Data = 1;
    BT->Left = Insert(2);
    BT->Right = Insert(3);
    BT->Left->Left = Insert(4);
    BT->Left->Right = Insert(6);
    BT->Left->Right->Left = Insert(5);
    BT->Right->Left = Insert(7);
    BT->Right->Right = Insert(9);
    BT->Right->Left->Right = Insert(8);
    return BT;
}
//        1
//     /     \
//     2       3
//    / \     /  \
//   4   6   7   9
//     /      \
//    5         8


// 判断树是否为空
/*bool  IsEmpty(BinTree BT){
}*/

// 先序
/*void  PreOrderTraversal(BinTree BT){
	if(BT){
		printf("%d",BT->Data);  // 打印根
		PreOrderTraversal(BT->Left);  // 进入左子树
		PreOrderTraversal(BT->Right);  // 进入右子树
	}
} */

// 先序非递归
void PreOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> SB;  // 创建并初始化栈 SB
    while (T || !SB.empty()) {  // 当树不为空或堆栈不空
        while (T) {
            SB.push(T);    // 压栈
            printf("%d", T->Data);  // 访问结点
            T = T->Left;   // 遍历左子树
        }
        if (!SB.empty()) {  // 当堆栈不空
            T = SB.top();    // 出栈，第二次遇到该结点
            SB.pop();
            T = T->Right;  // 访问右结点
        }
    }
}

// 中序递归
/*void InOrderTraversal(BinTree BT){
	if(BT){
		InOrderTraversal(BT->Left);  // 进入左子树
		printf("%d",BT->Data);  // 打印根
		InOrderTraversal(BT->Right);  // 进入右子树
	}
} */

// 中序非递归
void InOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> SB;  // 创建并初始化栈 SB
    while (T || !SB.empty()) {  // 当树不为空或堆栈不空
        while (T) {
            SB.push(T);    // 压栈
            T = T->Left;   // 遍历左子树
        }
        if (!SB.empty()) {  // 当堆栈不空
            T = SB.top();    // 出栈
            SB.pop();
            printf("%d", T->Data);  // 访问结点
            T = T->Right;  // 访问右结点
        }
    }
}

// 后序
/*void PostOrderTraversal(BinTree BT){
	if(BT){
		PostOrderTraversal(BT->Left);  // 进入左子树
		PostOrderTraversal(BT->Right);  // 进入右子树
		printf("%d",BT->Data);  // 打印根
	}
} */

// 后序遍历
void PostOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> SB;  // 创建并初始化栈 SB
    vector<BinTree> v;
    SB.push(T);
    while (!SB.empty()) {  // 当树不为空或堆栈不空
        T = SB.top();
        SB.pop();
        v.push_back(T);
        if (T->Left)
            SB.push(T->Left);
        if (T->Right)
            SB.push(T->Right);
    }
    // 经过上面的步骤，vector数组中的元素是NRL，逆转后即为LRN
    reverse(v.begin(), v.end());  // 逆转
    for (int i = 0; i < v.size(); i++)
        printf("%d", v[i]->Data);
}

// 层次遍历
void LevelOrderTraversal(BinTree BT) {
    queue<BinTree> q;
    BinTree T;
    if (!BT)
        return;
    q.push(BT);  // BT 入队
    while (!q.empty()) {
        T = q.front();  // 访问队首元素
        q.pop();  // 出队
        printf("%d", T->Data);
        if (T->Left)
            q.push(T->Left);
        if (T->Right)
            q.push(T->Right);
    }
}

// 输出叶子结点
void FindLeaves(BinTree BT) {
    if (BT) {
        if (!BT->Left && !BT->Right)
            printf("%d", BT->Data);  // 打印叶子结点
        FindLeaves(BT->Left);  // 进入左子树
        FindLeaves(BT->Right);  // 进入右子树
    }
}

// 求树高度
int GetHeight(BinTree BT) {
    int hl, hr, maxh;
    if (BT) {
        hl = GetHeight(BT->Left);  // 求左子树高度
        hr = GetHeight(BT->Right);  // 求右子树高度
        maxh = (hl > hr) ? hl : hr;
        return maxh + 1;  // 当前结点高度为左右子树最大的高度+1
    } else
        return 0;
}

int main() {
    BinTree BT, ST;
    BT = CreatBinTree();
    printf("先序遍历：");
    PreOrderTraversal(BT);
    printf("\n中序遍历：");
    InOrderTraversal(BT);
    printf("\n后序遍历：");
    PostOrderTraversal(BT);
    printf("\n层次遍历：");
    LevelOrderTraversal(BT);
    printf("\n输出叶子结点:");
    FindLeaves(BT);
    printf("\n输出树的高度：%d", GetHeight(BT));
    return 0;
}
