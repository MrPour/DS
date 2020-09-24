#include"stdio.h"

typedef struct LNode{
  ElemType data;
  struct LNode *next;  //这里要注意，顺序分配时，指针用数组下标，而链式分配时用的是地址
} *LiStack

//不带头的初始化
bool initStack(LiStack &L)
{
    L = NULL;
    return true;
}

//带头指针的初始化
bool initStack(LiStack &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
    return false;
    L->next = NULL;
    return true;
}

//判空
bool isEmpty(LiStack &L)
{
    if(L == NULL)
    return true;
    else
    return false;
}

bool isEmpty(LiStack &L)
{
    if(L->next == NULL)
    return true;
    else
    return false;
}

//入栈(相当于做前插)  -- 无头结点
bool push(LiStack &L,ElemType x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
    {
      return false;
    }
    s->data = x;
    if(isEmpty())
    {
        s->next = NULL;
        L = s;
    }
    else
    {
        LNode *p = L;
        s->next = p;
        L = s;
    }
    return true;    
}

//出栈 -- 无头结点
bool pop(LiStack &L,ElemType &x)
{
    if(isEmpty())
    {
    return false;
    }
    else
    {
      LNode *p = L;
      x = p->data;

      if(p->next == NULL)
      {
         L = NULL
      }
      else
      {
        L = p->next;
      }
    }
    return true;
}

//出栈 -- 带头结点
bool pop(LiStack &L,ElemType &x)
{
    if(isEmpty())
    {
        return false;
    }
    LNode *p = L->next;
    x = p->data;
    if(p->next == NULL)
    {
        L->next = NULL;
    }
    else
    {
       L->next = p->next;
    }
    return true;
}