#include"stdio.h"
#define MaxSize = 10
//1、front为队首元素，rear为队尾元素+1，这是常见情况(因为为了少牺牲一个位置！！！)
//2、判空条件和判满条件要注意（不管是哪种设计，空与满的状况相同，我们实际是牺牲了满的状况）
//3、结构的维护意味着操作完成

typedef struct{
ElemType data[MaxSize];
int front,rear; //队头和队尾（FIFO）  注:rear指向的是可以push的位置
}SqQueue

//初始化 -- 指向当前数据下一位
void initQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

void initQueue(SqQueue &Q)
{
    Q.front = 0;
    Q.rear = MaxSize - 1;
}

//判空
bool isEmpty(SqQueue &Q)
{
    if(Q.front == Q.rear)
    return true;
    else
    return false;
}

bool isEmpty(SqQueue &Q)
{
    if(Q.front == (Q.rear+1)%MaxSize) //这种情况和队列满时一模一样（尾在头后1个位置）
    return true;
    else
    return false;
}

//判满(rear指向队尾元素的下一个元素)  真满：rear = 10 && front = 0 => rear%MaxSize = front
//                                  假满：rear = 9 && front = 0 => (rear+1)%MaxSize = front
bool isFull(SqQueue &Q)
{
    if((Q.rear+1) % MaxSize == Q.front) //注：本来应该是rear%MaxSize，但是和判空条件相同，因此这里放弃了一个位置
    return true;
    else
    return false;
}

bool isFull(SqQueue &Q)
{
    if((Q.rear+2) % MaxSize == Q.front) //注：这而为了区分，牺牲一个单元，尾在头后2个位置
    return true;
    else
    return false;
}


//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if(isFull())
    return false;
    Q.data[Q.rear] = x;
    //不要忘了维护队尾指针
    Q.rear = (Q.rear+1) % MaxSize;
    return true;
}

bool EnQueue(SqQueue &Q,ElemType x)
{
    if(isFull())
    return false;
    //先让指针+1
    Q.rear = (Q.rear+1) % MaxSize;
    Q.data[Q.rear] = x;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(isEmpty())
    return false;
    x = Q.data[Q.front];
    //维护队首
    Q.front = (Q.front+1) % MaxSize;
    return true;
}

bool getHead(SqQueue &Q,ElemType &x)
{
    if(isEmpty())
    return false;
    x = Q.data[Q.front];
    return true;
}

int getTotal(SqQueue &Q)
{
    return (Q.rear+MaxSzie-Q.front)%MaxSize
}
