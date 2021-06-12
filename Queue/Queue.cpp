#include "iostream"

using namespace std;

struct QNode {
    int data;
    QNode *next;
};

struct Queue {
    QNode *front;
    QNode *rear;
};

void initQueue(Queue *queue) {
    QNode *node = new QNode{NULL, nullptr};
    queue->rear = node;
    queue->front = queue->rear;
}

void enQueue(Queue *queue, int data) {
    QNode *qNode = new QNode{data, nullptr};
    queue->rear->next = qNode; // 链表尾部入队
    queue->rear = qNode; // rear后移
}

int deQueue(Queue *queue) {
    if (&queue->front == &queue->rear) {
        cout << "队列为空" << endl;
        return NULL; // 队列为空
    }
    int result;
    QNode *p = queue->front->next;
    result = p->data; // 头节点连接的节点出列
    queue->front->next = p->next;
    delete p; // 回收p的内存
    return result;
}

int main() {
    Queue  queue;
    initQueue(&queue);
    enQueue(&queue,11);
    enQueue(&queue,12131);
    enQueue(&queue,4234211);
    cout << deQueue(&queue) << endl;
    cout << deQueue(&queue) << endl;
    cout << deQueue(&queue) << endl;
}