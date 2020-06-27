#include <iostream>
#include <stdlib.h>

using namespace std;

/**************************************************************************************************
    Project 1

    定义一个单向链表node, 每个节点值为int.
    定义函数void create_linklist(…, int n)来生成链表，链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，链表节点值为1,2,3...n；
    定义函数reverse_linklist(...),　对参数传入的链表进行逆转；
    定义函数insert_node(node *pHead, int Index, int Value ), 在指定链表位置Index插入指定Value；
    定义函数delete_node(node *pHead,  int Index),删除链表位置Index所在的节点；
    定义函数delete_linklist(),　删除整个链表；
    定义函数print_linklist(), 打印整个链表。
*/

struct node
{
    int v;
    node* n;
};

/* 链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，
   链表节点值为1,2,3...n
*/
void create_linklist(node **pHead, int n)
{
    //!step0; init a empty link table
    *pHead = (node*) malloc(sizeof (node));
    (*pHead)->n = nullptr;

    //!step1: temp pointer 
    node* lastNode = (*pHead);
    node* newNode;
    
    //!step2: create 
    int data = 1;
    while(data<=n)
    {
        // create 
        newNode=(node*)malloc(sizeof(node));
        newNode->v = data;
        newNode->n = nullptr;

        // update head
        if((*pHead)->n == nullptr)
        {
            (*pHead)->n = newNode;
        }
        else
        {
            lastNode->n = newNode;
        }
            
        
        // save lastNode;
        lastNode = newNode;
        data++;
    }
}


//对参数传入的链表进行逆转
void reverse_linklist(node **pHead)
{
    node* last;
    node* cur;

    // first node 
    last= (*pHead)->n;
    cur = last->n;
    last->n = nullptr;


    while(cur!=nullptr)
    {
        node* tmp  = cur->n;
        cur->n = last;
        last = cur;
        cur = tmp;
    }

    // update pHead 
    (*pHead)->n = last;
}

//在指定链表位置Index插入指定Value
// Index 为 1 ~ n 代表 1 ~ n 个节点
// Index = 0 即为头添加
void insert_node(node **pHead,  int Index, int Value)
{	
    node* p;
    node* t;

    //case 1: Index==0
    if(Index==0)
    {
        (*pHead)->v = Value;
        return;
    }

    // case 2:
    p = (*pHead)->n;
    int data = 1;
    while( p!=nullptr && data <(Index-1))
    {
        p=p->n;
        data++;
    }
    // add 
    if(data==(Index-1))
    {
        t=(node*)malloc(sizeof(node));
        t->v = Value;
        t->n = p->n;
        p->n = t;
    }
}

//删除链表位置Index所在的节点
void delete_node(node **pHead,  int Index)
{	
    node* p;
    node* t;

    //case 1: Index==0
    if(Index==0)
    {
        t=(*pHead);
        *pHead = t->n;
        free(t);
        return;
    }

    // case 2:
    p = (*pHead)->n;
    int data = 1;
    while( p!=nullptr && data <(Index-1) )
    {
        p=p->n;
        data++;
    }
    //delete
    if(data==(Index-1))
    {
       t = p->n;
       p->n = t->n;
       free(t);
    }
}

//删除整个链表
void delete_linklist(node **pHead)
{
    node* t;
    while( (*pHead)->n!=nullptr)
    {   
        t=(*pHead);
        *pHead = t->n;
        free(t);
    }

    free(*pHead);
}

//打印整个列表
void print_linklist(node **pHead)
{
    node* p;
    node* t;

    p=(*pHead)->n;
    while( p!=nullptr)
    {   
        std::cout << p->v <<"->";
        p = p->n;
    }
    std::cout<<"\n";
}

int main()
{
 // Project 1
    // 可将头尾指针及节点个数封装结构体，更方便操作
    cout << "==========Project1=================" << endl;
    node *pHead = nullptr;
    // １．调用create_linklist()生成链表
    create_linklist(&pHead,9);
    print_linklist(&pHead);

    
    // ２．调用insert_node()插入节点
    insert_node(&pHead,9,10);
    print_linklist(&pHead);

    
    // ３．调用delete_node()删除节点
    delete_node(&pHead,10);
    print_linklist(&pHead);

    
    // ４．调用reverse_linklist()逆转
    reverse_linklist(&pHead);
    print_linklist(&pHead);
    
    cout << endl;
    cout << "==========Project1=================" << endl;
    cout << endl;
}