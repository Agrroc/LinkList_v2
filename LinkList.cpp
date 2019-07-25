#include <stdio.h>
#include <stdlib.h>

//单链表结构体
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//头插法建立链表
void HeadInsert(LNode *&L)
{
    LNode *p = NULL; //待插入结点
    int data;        //结点数据
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入待插入数据，以9999结尾：\n");
    scanf("%d", &data);
    while (data != 9999)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = data;
        p->next = L->next;
        L->next = p;
        scanf("%d", &data);
    }
    return;
}
//尾插法建立链表
void TailInsert(LNode *&L)
{
    int data;
    // LNode *p, *r = L; //p为新结点，r指向最后一个结点
    L = (LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *p, *r = L; //p为新结点，r指向最后一个结点,一定要建立结点，再进行赋值
    printf("请输入待插入数据，以9999结尾：\n");
    scanf("%d", &data);
    while (data != 9999)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = data;
        r->next = p; //在最后一个结点后面插入结点
        r = r->next;
        scanf("%d", &data);
    }
    r->next = NULL;
    return;
}

//遍历链表
void TravelList(LNode *L)
{
    printf("链表从前到后为：");
    LNode *n = L->next;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
    return;
}

int main()
{
    LNode *L = NULL;
    // HeadInsert(L);
    TailInsert(L);
    TravelList(L);
    return 0;
}