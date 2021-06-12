#include "iostream"
using namespace std;
#define MaxSize 100

struct Queue{
    int data[MaxSize];
    int front,rear;
};

// 初始化队列，判空条件仍为rear=front
void initQueue(Queue *q){
    q->rear = 0;
    q->front = q->rear;
}

bool isEmpty(Queue *q){
    if (q->rear == q->front){
        return true;
    } else{
        return false;
    }
}

void enQueue(Queue *q,int data){
    if ((q->rear + 1) % MaxSize == q->front) { // 队列判满条件,预留了一个空位置
        cout << "队列已满" << endl;
        return;
    }
    q->data[q->rear] = data;
    q->rear ++;

}

int deQueue(Queue *q){
    if (isEmpty(q)){
        cout << "队列为空" << endl;
        return NULL;
    }
    int result = q->data[q->front];
    q->data[q->front] = NULL;
    q->front ++;
    return result;
}

int main(){
    Queue queue;
    initQueue(&queue);
    deQueue(&queue);
    for (int i = 0; i < 100; ++i) {
        enQueue(&queue,rand());
    }
    for (int i = 0; i < 99; ++i) {
        cout << "出队元素为:" << deQueue(&queue) << endl;
    }
}
