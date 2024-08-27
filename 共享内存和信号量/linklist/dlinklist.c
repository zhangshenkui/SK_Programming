/*
 *  ��������dlinklist.c���˳�����ʾ˫���������ò�����
 *  ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201019
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_girl
{
  int  no;               // ��Ů�ı�š�
  char name[31];         // ��Ů��������
  struct st_girl *prev;  // �����һ���ڵ�ṹ��ĵ�ַ��
  struct st_girl *next;  // �����һ���ڵ�ṹ��ĵ�ַ��
};

int  linksize;  // ����Ĵ�С���ڵ�������
struct st_girl *head,*tail;  // �����ͷ��βָ�롣

void initlinklist();   // �����ʼ����

void addnode1(struct st_girl *pst);          // �ѽڵ���뵽�����ͷ����
void addnode2(struct st_girl *pst);          // �ѽڵ�׷�ӵ������β����
void addnode3(struct st_girl *pst,int iseq); // ������iseqλ�ò���ڵ㣬iseq��0��ʼ�����iseq��ֵ���ڵ���linksize�����������β��׷�ӡ�
void addnode4(struct st_girl *pst);          // �ѽڵ���뵽������м䣬���������ṹ���no�ֶ�����

void delnode1();         // �������ͷ��ɾ��һ���ڵ㡣
void delnode2();         // �������β��ɾ��һ���ڵ㡣
void delnode3(int iseq); // ��������ɾ����iseq���ڵ㣬iseq��ȡֵ����Ϊ��0<=iseq<linksize������ɾ���κνڵ㡣
void delnode4(int ino);  // ��������ɾ���ṹ��no�ֶε���ino�ļ�¼��

void printlinklist();    // ��ʾ����ȫ���ڵ�����ݡ�
void printlinklist1();   // ������ʾ����ȫ���ڵ�����ݡ�

void freelinklist();     // �ͷ�����ռ�õ��ڴ档

int main()
{
  initlinklist();   // �����ʼ����

  struct st_girl *pst=0;     // ��Ů�ṹ��ָ�롣

  // ѭ��5�Σ������������볬Ů��¼��
  int ii=0;
  for (ii=0;ii<5;ii++)
  {
    pst=(struct st_girl*)malloc(sizeof(struct st_girl));   // ����һ�����ڴ档
    memset(pst,0,sizeof(struct st_girl));

    printf("�����볬Ů�ı�ź��������м��ÿո�ָ���");
    scanf("%d %s",&pst->no,pst->name);

    // addnode1(pst); // �ѽڵ���뵽�����ͷ����
    // addnode2(pst); // �ѽڵ�׷�ӵ������β����
    // addnode3(pst,3); // �������3��λ�ò���ڵ㡣
    addnode4(pst); // �ѽڵ���뵽������м䣬���ṹ���no�ֶ�����
  }

  // delnode1();  // �������ͷ��ɾ��һ���ڵ㡣
  // delnode2();  // �������β��ɾ��һ���ڵ㡣
  // delnode3(3);  // ��������ɾ��ָ��λ�õĽڵ㡣
  // delnode4(1); // ��������ɾ���ṹ��no�ֶε���ino�ļ�¼��


  // ��ʾ����ȫ���ڵ�����ݡ�
  printlinklist();
  printlinklist1();

  // �ͷ�����ռ�õ��ڴ档
  freelinklist();

  // system("pause");  // windowsƽ̨�������д��롣
}

// ��ʵ�ʿ����У������ÿ���ڵ㣬ʹ�õ�ʱ��Ͷ�̬���䣬�����˾�ɾ������Ԥ�ȷ���û�����塣
// �����ʼ����
void initlinklist()
{
  linksize=0;
  head=tail=0;
}

// �ѽڵ���뵽�����ͷ����
void addnode1(struct st_girl *pst)
{
  if (head==0) // �������Ϊ�ա�
  { 
    head=tail=pst; pst->prev=pst->next=0;
  }
  else // �������Ϊ�ա�
  {
    head->prev=pst;
    pst->next=head;
    head=pst;
  }

  linksize++;
}

// �ѽڵ�׷�ӵ������β����
void addnode2(struct st_girl *pst)
{
  if (head==0) // �������Ϊ�ա�
  { 
    head=tail=pst;  pst->prev=pst->next=0;
  }
  else // �������Ϊ�ա�
  {
    pst->prev=tail;
    tail->next=pst;
    tail=pst;
    pst->next=0;
  }

  linksize++;
}

// ������iseqλ�ò���ڵ㣬iseq��0��ʼ�����iseq��ֵ���ڵ���linksize�����������β��׷�ӡ�
void addnode3(struct st_girl *pst,int iseq)
{
  // �������Ϊ�ա�
  if (head==0)
  {
    head=tail=pst; pst->prev=pst->next=0; linksize=1; return;
  }

  // ���iseq==0��������ͷ�����롣
  if (iseq==0)
  {
    addnode1(pst); return;
  }

  // ���iseq>=linksize���ѽڵ�׷�ӵ������β����
  if (iseq>=linksize)
  {
    addnode2(pst); return;
  }

  // ���´������ڴ���ǰ��ͷ��β֮�����������
  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��
  int itmp=1;

  while (1)
  {
    if ( iseq== itmp )
    {
      pst->prev=ptmp;
      pst->next=ptmp->next;
      ptmp->next->prev=pst;
      ptmp->next=pst;
      linksize++;
      return;
    }

    itmp++;
    ptmp=ptmp->next;  // �����ƶ�һ���ڵ㡣
  }
}


// �ҵĴ��벻�����ģ����Ǹ�Ч�׶���
// �ѽڵ���뵽������м䣬���ṹ���no�ֶ�����
void addnode4(struct st_girl *pst)
{
  // �������Ϊ�ա�
  if (head==0) 
  { 
    head=tail=pst; pst->prev=pst->next=0; linksize=1; return;
  }

  // �����ǰ�ڵ��noС�ڵ���ͷ�ڵ��no��������ͷ�����롣
  if (pst->no<=head->no) 
  {
    addnode1(pst); return;
  }

  // �����ǰ�ڵ��no���ڵ���β�ڵ��no���ѽڵ�׷�ӵ������β����
  if (pst->no>=tail->no) 
  {
    addnode2(pst); return;
  }

  // ���´������ڴ���ǰ�ڵ��no��ͷ��β֮��������
  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��

  while (ptmp!=0)
  {
    if ( (pst->no>=ptmp->no) && (pst->no<=ptmp->next->no) )
    {
      pst->prev=ptmp;
      pst->next=ptmp->next;
      ptmp->next->prev=pst;
      ptmp->next=pst;
      linksize++;
      return;
    }

    ptmp=ptmp->next;  // �����ƶ�һ���ڵ㡣
  } 
}

// ��ʾ����ȫ���ڵ�����ݡ�
void printlinklist()
{
  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��

  while (ptmp!=0)
  {
    printf("no=%d,name=%s\n",ptmp->no,ptmp->name);
    ptmp=ptmp->next; // ָ���ƶ�����һ�ڵ㡣
  } 

  printf("linksize=%d\n",linksize);
}

// ������ʾ����ȫ���ڵ�����ݡ�
void printlinklist1()
{
  struct st_girl *ptmp=tail; // ��β�ڵ㿪ʼ��

  while (ptmp!=0)
  {
    printf("no=%d,name=%s\n",ptmp->no,ptmp->name);
    ptmp=ptmp->prev; // ָ���ƶ�����һ�ڵ㡣
  } 

  printf("linksize=%d\n",linksize);
}

// �ͷ�����ռ�õ��ڴ档
void freelinklist()
{
  struct st_girl *ptmp; // һ����ʱ��ָ�롣

  while (head!=0)
  {
    ptmp=head;
    head=head->next;  // �ƶ�����һ�ڵ㡣
    free(ptmp);       // �ͷŵ�ǰ�ڵ㡣
  }

  initlinklist();
}


// �������ͷ��ɾ��һ���ڵ㡣
void delnode1()
{
  // �����һ��������ֱ�ӷ��ء�
  if (head==0) return;

  // �������ֻ��һ���ڵ㡣
  if (head==tail)
  {
    free(head); initlinklist(); return;
  }

  // ��������ж���ڵ㡣
  struct st_girl *ptmp=head;
  head=head->next;
  head->prev=0;
  free(ptmp);
  linksize--;
}

// �������β��ɾ��һ���ڵ㡣
void delnode2()
{
  // �����һ��������ֱ�ӷ��ء�
  if (head==0) return;

  // �������ֻ��һ���ڵ㡣
  if (head==tail)
  {
    free(head); initlinklist(); return;
  }

  /*
  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��

  while (ptmp!=0)
  {
    if (ptmp->next==tail)
    {
      free(tail); tail=ptmp; tail->next=0; linksize--; return;
    }

    ptmp=ptmp->next; 
  } 
  */

  struct st_girl *ptmp=tail;
  tail=tail->prev;
  tail->next=0;
  free(ptmp);
  linksize--;

}

// ��������ɾ����iseq���ڵ㣬iseq��ȡֵ����Ϊ��0<=iseq<linksize������ɾ���κνڵ㡣
void delnode3(int iseq)
{
  // �ж�iseq��ȡֵ�Ƿ�Ϸ���������Ϸ���ֱ�ӷ��ء�
  if ( (iseq<0) || (iseq>=linksize) ) return;

  // ���iseq==0��ɾ��ͷ�ڵ㡣
  if (iseq==0)
  {
    delnode1(); return;
  }

  // ���iseq=linksize-1��ɾ��β�ڵ㡣
  if (iseq==linksize-1)
  {
    delnode2(); return;
  }

  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��
  int itmp=0;

  while (ptmp!=0)
  {
    if (itmp==iseq)
    {
      ptmp->prev->next=ptmp->next;
      ptmp->next->prev=ptmp->prev;

      free(ptmp);
      linksize--;
      return;
    }

    itmp++;
    ptmp=ptmp->next;
  }
}


// ��������ɾ���ṹ��no�ֶε���ino�ļ�¼��
void delnode4(int ino) 
{
  // ���ͷ�ڵ��no�ֶε���ino��ɾ��ͷ�ڵ㡣
  if (head->no==ino)
  {
    delnode1(); return;
  }

  // ���β�ڵ��no�ֶε���ino��ɾ��β�ڵ㡣
  if (tail->no==ino)
  {
    delnode2(); return;
  }

  struct st_girl *ptmp=head; // ��ͷ�ڵ㿪ʼ��

  while (ptmp!=0)
  {
    if (ptmp->no==ino)
    {
      ptmp->prev->next=ptmp->next;
      ptmp->next->prev=ptmp->prev;

      free(ptmp);
      linksize--;
      return;
    }

    ptmp=ptmp->next;
  } 
}
