#include"stdio.h"
#define MaxSize = 10
typedef struct {
    ElemType data[MaxSize];
    int top;    //数组下标
}SqStack;

SqStack s;

//初始化顺序栈（top指向当前栈顶）
void initStack(SqStack &s)
{
    s->top = -1; //如果指向栈顶下一个元素 (s->top = 0)
}
//判空
bool isEmpty(SqStack &s)
{
    if(s->top == -1) 
       return true;
    else 
       return false;
}

bool isFull(SqStack &s)
{
    if(s->top == MaxSize-1) //如果是指向的下一位则if(s->top == MaxSize)
    return true;
    else
    return false
}

//入栈
bool push(SqStack &s,ElemType x)
{
    if(isFull(s))
    return false;
    else
    s.data[++s.top] = x;    // 如果是下一位 s.data[s.top++] = x
    return true;
}

//出栈
bool pop(SqStack &s,ElemType &x)
{
    if(isEmpty(s))
    return false;
    else
    x = s.data[s.top--];  // x = s.data[--s.top]
    return true;
}

//读取栈顶元素
bool getTop(SqStack &s,ElemType &x)
{
    if(isEmpty(s))
    return false;
    else
    x = s.data[s.top];
    return true;
}

