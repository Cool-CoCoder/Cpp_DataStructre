#include "iostream"
using namespace std;
#define MaxSize 100

// 顺序栈，比较简单
struct Stack{
    int data[MaxSize];
    int top;
};

void initStack(Stack *stack){
    stack->top = -1; // 初始化栈
}

bool stackEmpty(Stack *s){
    if (s->top == -1){
        return true;
    } else{
        return false;
    }
}

void push(Stack *stack,int data){
    if (stack->top != MaxSize-1){
        stack->top++;
        stack->data[stack->top] = data;
    } else{
        cout << "栈已满" << endl;
        return;
    }
}

int pop(Stack *stack){
    if (stackEmpty(stack)){
        cout << "栈为空" << endl;
        return NULL;
    } else{
        int result =  stack->data[stack->top];
        stack->data[stack->top] = NULL;
        stack->top --;
        return result;
    }
}

int main(){
    Stack stack;
    initStack(&stack);
    push(&stack,1);
    push(&stack,4);
    push(&stack,5);
    cout << "弹出元素为:" << pop(&stack) << endl;
    cout << "弹出元素为:" << pop(&stack) << endl;
    cout << "弹出元素为:" << pop(&stack) << endl;
    cout << "弹出元素为:" << pop(&stack) << endl;
    return 0;
}

