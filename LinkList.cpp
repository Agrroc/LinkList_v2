#include <stdio.h>
#include <stdlib.h>

//单链表结构体
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
//双链表结构体
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

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
    L->next = NULL;
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
//按序号查找结点
LNode *GetNode(LNode *L, int i)
{
    int count = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (p && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) //当输入i值超出结点总数
        printf("没有第%d个结点\n", i);
    else
        printf("第%d个结点为：%d\n", i, p->data);
    return p;
}
//按值查找结点
LNode *LocateElem(LNode *L, int elem)
{
    LNode *p = L->next;
    int i = 1;                           //结点序号
    while (p != NULL && p->data != elem) //从第一个结点开始按值查找，p!=NULL要么空链表，要么找不到该值
    {
        p = p->next;
        i++;
    }
    if (p != NULL && p->data == elem)
        printf("值为%d的结点序号为：%d\n", elem, i);
    else
        printf("没有值为%d的结点\n", elem);
    // printf("%d",p->data);
    return p;
}
//在第i个位置上插入新结点
void InsertNode(LNode *&L, int i, int data)
{
    LNode *p, *new_Node; //p为插入位置前一个结点
    p = GetNode(L, i - 1);
    new_Node = (LNode *)malloc(sizeof(LNode));
    new_Node->next = p->next;
    new_Node->data = data;
    p->next = new_Node;
    return;
}
//删除第i个结点
void DeletNode(LNode *&L, int i)
{
    LNode *p, *del_Node;
    p = GetNode(L, i - 1);
    del_Node = p->next;
    p->next = del_Node->next;
    free(del_Node);
    return;
}
//遍历单链表
void TravelList(LNode *L)
{
    printf("链表从前到后为：");
    int number = 0;
    LNode *n = L->next;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
        number++;
    }
    printf("一共%d个元素\n", number);
    return;
}
//头插法建立双链表
void HInsertDList(DNode *&D)
{
    D = (DNode *)malloc(sizeof(DNode));
    D->prior = D->next=NULL;
    int data;
    DNode *p = NULL; //p为待插入结点
    printf("请输入待插入的数据，以9999结尾：\n");
    scanf("%d", &data);
    while (data != 9999)
    {
        p = (DNode *)malloc(sizeof(DNode));
        p->data = data;
        p->next = D->next;
        if(D->next!=NULL)//当前没有一个结点时，没有后继结点，就没办法找前驱
            D->next->prior = p;
        p->prior = D;
        D->next = p;
        scanf("%d", &data);
    }
    return;
}
//遍历双链表
void TravelDList(DNode *D)
{
    printf("双链表从前到后为：");
    int number = 0;
    DNode *p = D->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
        number++;
    }
    printf("一共%d个元素\n", number);
}

int main()
{
    LNode *L = NULL;
    DNode *D = NULL;
    // HeadInsert(L);//头插法
    // TailInsert(L); //尾插法
    // TravelList(L); //遍历链表
    // // GetNode(L,3);//按序号查找
    // // LocateElem(L,7);//按值查找
    // InsertNode(L, 3, 88); //插入新的结点
    // TravelList(L);
    // DeletNode(L, 2); //删除结点
    // TravelList(L);
    HInsertDList(D); //头插法建立双链表
    TravelDList(D);
    return 0;
}