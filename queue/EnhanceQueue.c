#include"stdio.h"
#define MaxSize = 10

typedef struct{
ElemType data[MaxSize];
int front,rear; //队头和队尾（FIFO）  注:rear指向的是可以push的位置
int size;//维护一个变量,每次出入队都更新
}SqQueue

size == 0
size == MaxSize


typedef struct{
ElemType data[MaxSize];
int front,rear; //队头和队尾（FIFO）  注:rear指向的是可以push的位置
int tag;//初始化为0，每次入队设为1
}SqQueue

Q.rear % MaxSize == Q.front && tag == 1;
