#include "iostream"

using namespace std;

struct KString {
    char ch[100];
    int length;
};

void get_next(KString *t, int next[]) {
    int i = 1, j = 0;
    next[1] = 0; // 为了计算方便，next从1开始使用
    while (i < t->length) {
        if (j == 0 || t->ch[i] == t->ch[j]) {
            j++, i++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

// 匹配函数
int index_KMP(KString *s, KString *t, int next[]) {
    int i = 1, j = 1;
    while(i <= s->length && j <= t->length){
        if(j == 0 || s->ch[i-1] == t->ch[j-1]){
            ++i,++j;
        } else{
            j = next[j];
        }
    }
    if (j > t->length){
        return i - t->length; // 匹配成功
    } else{
        return 0;
    }
}

int main() {
    KString kString = {"helloworld", 10};
    KString tString = {"worl", 4};
    int next[5]; // next长度为字符串长度+1
    get_next(&tString, next);
    // 打印next数组
    for (int i = 1; i < 6; ++i) {
        cout << next[i];
    }
    cout << "索引值为：" << index_KMP(&kString,&tString,next) << endl;
}
