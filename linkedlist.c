#include"stdio.h"

typedef struct LNode{
ElemType data;
struct LNode *next; //这种写法是为了区别开来，next为内部的指针，Linklist为头指针，代指整个链表
}LNode,*Linklist;

//没有头节点的初始化方式
Linklist L = NULL;//头指针

bool init(Linklist &L)
{
    L = NULL;
    return true;
}                    //空的链表，没有任何节点

bool init(Linklist &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)   //内存不足
    return false;
    L -> next = NULL;
    return true
}

//按位序插入(不声明都是尾插)
bool insert(Linklist &L,int i,ElemType e)
{
    //1、在合理的插入范围内找到第i个元素
    if(i<1)//不能在0处插入（此句必须保留）
    return false;
    //遍历找到i节点
    LNode *p = L; //遍历指针的起点是头节点
    int j = 0; //头节点视为0号节点
    while( p!=NULL && j<i-1 )
    {
        p = p -> next;
        j++;
    }
    if( p==NULL )
    return false;

    //2、尾插操作
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL) //分配内存失败
    return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//按位序查找(带头结点)
LNode* getElem(Linklist &L,int i)
{
    if(i<0)//查找可以在0处查
    return NULL;
    LNode *p = L;
    int j = 0;
    while( p!=NULL && j<i)
    {
        p = p->next;
        j++
    }
    return p;
}

//按值查找
LNode* locateElem(Linklist &L,ElemType e)
{
    LNode *p = L->next; //注意：此处必须是next，因为头节点没有data！
    while(p!=NULL && p->data!=e)
    {
        p = p->next;
    }
    return p;
}


//后插
bool insertAfter(Linklist &L,LNode *p,ElemType e)
{
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL)
    return false;
    s->data = e;
    if(p->next == NULL) //判断是否是最后一个结点
    {
        s->next = NULL;
    }
    else
    {
        s->next = p->next;
    }
    p->next = s;
    return true;
}

//前插
bool insertBefore(Linklist &L,LNode *p,ElemType e)
{
     LNode *s = (LNode*)malloc(sizeof(LNode));
     if(s == NULL)
     return false;
     s->data = e;
     s->next = p->next;
     ElemType temp = p->data; //只交换数据
     p->data = s->data;
     s->data = temp;
}

//按位序删除
bool deleteElem(Linklist &L,int i)
{
    if(i<1)
    return false;
    LNode *p = L;
    LNode *q = null;
    int j = 0;
    while(p != null && j<i)
    {
        p = p->next;
        j++;
    }
    if(p == null)
    return false;
    q = p->next
    if(q == null) //删除和添加一定要判断p是最后一位
    {
        q = GetElem(L,i-1);
        q ->next = null;
        free(p);
        return true;
    }
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//带头结点的头插法
Linklist List_HeadInsert(Linklist &L)
{
    int x;
    LNode *s = NULL;
    L = (Linklist)malloc(sizeof(LNode));
    L -> next = NULL;    //别忘了初始化next！！！！（必须）
    scanf("%d",&x);
    while(x!=9999)
    {
       s = (LNode *)malloc(sizeof(LNode));
       s->data = x;
       s->next = L->next;
       L->next = s;
    }
    return L;
}

Linklist List_TailInsert(Linklist &L)
{
     int x;
     LNode *s = NULL;  //新建结点
     LNode *t = L;  //尾结点 
     L = (Linklist)malloc(sizeof(LNode));
     L -> next = NULL;    //这里可以省略next！！！！
     scanf("%d",&x);
     while (x!=9999)
     {
       s = (LNode *)malloc(sizeof(LNode));
       s->data = x;
       s->next = NULL;
       t->next = s;
       t = s; 
     }
     return L;
     
}
