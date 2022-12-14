#include "4_SqQueue.h"
#include <stdlib.h>
#include <stdio.h>


Status printQueue(SqQueue Q)
{
    if (!&Q || !Q.base)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    if (Q.front == Q.rear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }

    QElemType move = Q.front;
    while (move != Q.rear)
    {
        printf("%d ", Q.base[move]);
        move++;
    }
    printf("\n");
    return OK;
}


// (1) 初始化
Status initQueue(SqQueue *pQ)
{
    if (!pQ)
        return ERROR;
    pQ->base = (QElemType*)malloc(sizeof(QElemType)*MAXQSIZE);
    if (!pQ->base)
        exit(OVERFLOW);
    
    pQ->front = pQ->rear = 0;
    return OK;
}

// (2) 求队列长度
int queueLength(SqQueue Q)
{
    if (!Q.base)
        return 0;
    
    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

// (3) 入队
Status enQueue(SqQueue *pQ, QElemType e)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    // 队列满的标志（浪费一个空间来区分队空和队满）
    if ((pQ->rear+1)%MAXQSIZE == pQ->front)
    {
        printf("[WARNIING]: FULL QUEUE!\n");
        return ERROR;
    }

    // 入队
    pQ->base[pQ->rear] = e;

    // 尾指针 + 1
    pQ->rear = (pQ->rear + 1) % MAXQSIZE;

    return OK;
}

// (4) 出队
Status deQueue(SqQueue *pQ, QElemType *pE)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST! \n");
        return ERROR;
    }
    // 队空的标志
    if (pQ->rear == pQ->front)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    // 出队
    *pE = pQ->base[pQ->front];

    // 头指针+1
    pQ->front = (pQ->front + 1) % MAXQSIZE;

    return OK;
}

// (5) 取队头元素
Status getHead(SqQueue Q, QElemType *pE)
{
    // 队空标志
    if (Q.front == Q.rear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    *pE = Q.base[Q.front];
    return OK;
}

// (6) 判空
Status queueEmpty(SqQueue Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

// (7) 清空队列
Status clearQueue(SqQueue *pQ)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    pQ->front = pQ->rear = 0;
    return OK;
}

// (8) 销毁队列
Status destroyQueue(SqQueue *pQ)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: NOTHING TO BE DESTROYED!\n");
        return ERROR;
    }
    free(pQ->base);
    pQ->base = NULL;
    pQ->front = pQ->rear = 0;

    return ERROR;
}