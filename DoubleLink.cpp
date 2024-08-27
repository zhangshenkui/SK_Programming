
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct{

    char key[10];  //关键字
    char name[20];
    int age;
}Data;             //数据域


//链表的声明
typedef struct Node{         //别名：  struct Node == CLType
    Data nodeData;
    struct Node *nextNode;   //指向下一个结点---指针域
}CLType，*SLink;

//如果想要增加一个新的结点： 
//      struct Node * p = (struct Node*) malloc(sizeof(struct Node));

//追加结点
    CLType *CLAddEnd(CLTYpe* head,Data nodeData){

        CLTyPE *node,*htemp;
        if(!(node=(CLType* )malloc(sizeof(CLType))) //增加新结点的指针是否为空
        {
            printf("malloc memory failed!\n");
            return NULL;               //分配内存失败
        }
        else{
            node->nodeData=nodeData;      //保存数据
            node->nextNode=NULL;          //设置结点指针为空，即为表尾
            if(head==NULL){
                head=node;
                return head;
            }
            htemp=head;                //头指针不为空的情况下
            while(htemp->nextNode != NULL){                       //相当于查找链表的末尾
                htemp=htemp->nextNode;
            }                         //且后续结点依次往后
            htemp->nextNode=node;     //直至最后到了htemp->nextNode=NULL情况,赋值尾结点
            return head;
        }
}

//初始化链表
//两种形式：  1、typedef struct Node CLType   //强调这是一个结点
//            2、typedef struct Node *SLink   //强调这是一个链表

bool InitList(SLink &L){
 return(L=NULL);              //本例中是一个不带头结点的单链表，否则上述应为 L->nextNode=NLL
}



//插入头结点
CLType *CLAddFirst(CLType *head,Data nodeData){
    CLType *node;
    if(!(node=(CLType *)malloc(sizeof(CLType)){   //新分配内存空间，保存结点
        printf("malloc memory failed!\n");
        return NULL;
    }
    else{
        node->nodeData=nodeData;       //保存数据
        node->nextNode=head;           //非空时head原先指向node,现在相当于把新增结点node指向头指针head所指向的结点
        head=node;  //head 指向新增的结点
        return head;
        }
}
        
//查找结点





    Init_DoubleLink(CLType 
    
