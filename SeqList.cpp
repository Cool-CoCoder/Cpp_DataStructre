#include "iostream"

using namespace std;
#define MaxSize 100
typedef int ElementType;

struct SeqList {
    int len;
    ElementType data[MaxSize];
};

void initSeqList(SeqList *L) {
    L->len = 0;
}

// 获取顺序表中某个元素
int getElem(SeqList *seqList, int elem){
    for (int i = 0; i < seqList->len; ++i) {
        if (seqList->data[i] == elem){
            return i + 1;
        }
    }
    // 没有相应的值
    return -1;
}

//删除元素
void SeqDel(SeqList *seqList, int pos) {
    if (pos < 1 or pos > seqList->len - 1) {
        cout << "删除位置不合法!" << endl;
    } else {
        for (int i = pos; i < seqList->len; i++) {
            seqList->data[i - 1] = seqList->data[i];
        }
        seqList->len--;
        cout << "删除成功" << endl;
    }
    }

// 插入元素
void SeqInsert(SeqList *seqList, int pos, ElementType e) {
    if (pos < 1 or pos > seqList->len) {
        cout << "插入位置不合法!" << endl;
    } else {
        // 将插入位置后的元素都向后移
        for (int i = seqList->len; i >= pos; --i) {
            seqList->data[i] = seqList->data[i - 1];
        }
        seqList->data[pos - 1] = e;
//        顺序表长度+1
        seqList->len++;
        cout << "data[" << (pos -1) << "]=" << e << endl;
        cout << "插入成功!" << endl;
    }
}


// 尾部插入元素
void SeqBackInsert(int elem, SeqList *seqList) {
//    判断长度是否大于最大界限
    if (seqList->len < MaxSize) {
        seqList->data[seqList->len] = elem;
        cout << "data[" << seqList->len << "]=" << elem << endl;
        // 顺序表长度增加
        seqList->len++;

    } else {
        cout << "尾部插入失败!" << endl;
    }
}

//遍历顺序表
void printList(SeqList *seqList) {
    cout << "遍历顺序表" << endl;
    for (int i = 0; i < seqList->len; i++) {
        cout << "顺序表的数据为:" << seqList->data[i] << endl;
    }
}

int main() {
    SeqList seqList;
    initSeqList(&seqList);

    for (int i = 0; i < 10; ++i) {
        SeqBackInsert(i, &seqList);
    }

    SeqInsert(&seqList, 5, 99);

    printList(& seqList);

    SeqDel(&seqList, 5);

    printList(& seqList);

    int result = getElem(&seqList,8);

    cout << "查询的结果为" << result << endl;

    return 0;
}