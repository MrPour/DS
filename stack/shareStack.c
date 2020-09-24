#include"stdio.h"
#define MaxSize = 10
typedef struct {
    ElemType data[MaxSize];
    int top0;    //0号栈
    int top1;    //1号栈
}SqStack;

//指向当前的初始化
void initStack(SqStack &s)
{
    s.top0 = MaxSize; //上头
    s.top1 = -1; //下头
}

//栈满的条件
bool isFull(SqStack &s)
{
    if(s.top0 == s.top1+1)
    return true;
    else
    return false;
}