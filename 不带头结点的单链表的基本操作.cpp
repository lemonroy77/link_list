#include <stdio.h>
#include<malloc.h>
typedef struct LNode{
    int data;
    struct LNode*next;
}LNode,*LinkList;
bool InitList(LinkList &L); //初始化
LNode* GetElem(LinkList L, int i); //按位查找
LNode* LocateElem(LinkList L, int e); //按值查找
int Length(LinkList L); //求单链表的?度
bool ListInsert(LinkList &L, int e); //后插
LinkList List_TailInsert(LinkList &L, int a[], int n);//尾插法
LinkList List_HeadInsert(LinkList &L, int a[], int n);//头插法
bool InitList(LinkList &L)//初始化
{
   L=NULL;
   return true;
}
int Length(LinkList L)//求单链表的长度
{   int len=1;
    while(L){
        L=L->next;
        len++;
    }
    return len;
}
LNode*GetElem(LinkList L,int i)//按位查找
{
    if(i<1||i>(Length(L))) return NULL;
    int j=1;
    while(L&&j<i){
        L=L->next;
    }
    return L;
}
LNode*LocateElem(LinkList L,int e)//按值查找
{
    if(!L) return NULL;
    while(L&&L->data!=e){
        L=L->next;
    }
    return L;
}
bool ListInsert(LinkList& L, int e) { // 后插
    if (L == NULL) return false;
    LNode* s, * p = L;
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    while (p->next != NULL)
        p = p->next;
    p->next = s;
    return true; // 需要添加返回值，表示插入操作是否成功
}
LinkList List_TailInsert(LinkList&L,int a[],int n)//尾插法,不带头结点
{
    int i=0;
    LNode*s,*r=L;
    while(i<n){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i++];
        if(L==NULL){
            L=s;
            r=s;
        }
        else{
            r->next=s;
            r=s;
        }
        r->next=NULL;
    }
    return L;
}
LinkList List_HeadInsert(LinkList&L,int a[],int n)//头插法，不带头结点
{
  L=NULL;
  LNode*s;
  int i=0;
  while(i<n){
      s=(LNode*)malloc(sizeof(LNode));
      s->data=a[i++];
      s->next=L;
      L=s;
  }
}
void print(LinkList L){
    while(L){
        printf("%d ",L->data);
        L=L->next;
    }
    printf("\n");
}
int main(){
    LinkList L;
    int a[]={1,2,3,4,5,6,7};
    List_TailInsert(L,a,4);
    ListInsert(L,5);
    print(L);
    return 0;
}