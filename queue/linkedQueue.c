#include"stdio.h"

//注意：链栈来说，它本身就和链表是一样的，因为top就是链表的头指针。
//     链队列来说，它和链表完全不同，因为它需要额外维护2个参数，front就是链表的头指针

typedef struct {
ElemType data;
LNode *next;
}LNode

typedef struct{
LNode *front,*rear;
}LinkedQueue

//带头结点的初始化
bool initQueue(LinkedQueue &L)
{
    L.front = L.rear = (LNode*)malloc(sizeof(LNode));  //头尾指针都指向头结点
    if(L.front == NULL)
    return false;
    L.front.next = NULL;
    return true;
}

bool initQueue(LinkedQueue &L)
{
    L.front = L.rear = NULL;
}

//判空
bool isEmpty(LinkedQueue &L)
{
    if(L.front == L.rear)
    return true;
    else
    return false;
}

bool isEmpty(LinkedQueue &L)
{
    if(L.front == NULL)
    return true;
    else
    return false;
}

//入队
bool EnQueue(LinkedQueue &L,ElemType x)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    if(p == NULL)
    return false;
    p.data = x;
    p.next = NULL;
    L.rear.next = p;
    L.rear = p;
    return true;
} 

bool EnQueue(LinkedQueue &L,ElemType x)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    if(p == NULL)
    return false;
    p->data = x;
    p->next = NULL;
    //入队判断是否影响头
    if(L.front == NULL)
    {
        L.front = p;
        L.rear = p;
    }
    else
    {
        L.rear->next = p;
        L.rear = p;
    }
    return true;
}

//出队
bool DeQueue(LinkedQueue &L,ElemType &x)
{
    if(L.front == L.rear)
    return false;
    LNode *p = L.front->next;
    x = p->data;
    //维护队首
    L.front->next = p->next; 
    //出队判断是否影响尾
    if(L.rear == p)
    {
        L.rear = L.front;
    }
    //这一步很重要！
    free(p);
    return true;
}

//出队
bool DeQueue(LinkedQueue &L,ElemType &x)
{
    if(L.front == NULL)
    return false;
    LNode *p = L.front;
    x = p->data;
    //维护队首
    L.front = p->next; 
    //出队判断是否影响尾
    if(L.rear == p)
    {
        L.front = NULL;
        L.rear = NULL;
    }
    //这一步很重要！
    free(p);
    return true;
}
