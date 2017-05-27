#include <stdio.h>
#include <stdlib.h>
#define maxsize 20 

typedef char Item;
typedef struct node * Node;
typedef struct node{
	Item item;
	Node next;
}node;


Node initstack();
void push(Node p,Item i);
int pop(Node p,Item * i);
Item gettop(Node p);
int topmark(Node p);
void destorystack(Node p);



int main()
{
	Node L;
	L=initstack();
	char str[maxsize]={0};
	printf("请使用括号表示法输入一棵二叉树。\n注：所有内容的长度请控制在%d个字符以内\n",maxsize-1);
	scanf("%s",str);
	int i;
	for(i=0;str[i]!=0;i++)
	{
	push(L,str[i]);
	printf("此刻栈顶元素为：%c\n",gettop(L));
	}
	return 0;
};

Item gettop(Node p)
{
	return(p->next->item);
};
Node initstack()
{
	Node s;
	s=(Node)malloc(sizeof(node));
	s->next=NULL;
	return s;
};

void push(Node p,Item i)
{
	Node s;
	s=(Node)malloc(sizeof(node));
	s->item=i;
	s->next=p->next;
	p->next=s;
};

int pop(Node p,Item * i)
{
	Node q;
	*i=p->next->item;
	q=p->next;
	p->next=p->next->next;
	free(q); 
	return 0;
};

void destorystack(Node p)
{
	Node q;
	while(p->next!=NULL)
	{
		q=p;
		p->next=p->next->next;
		free(q); 
	}
	free(p);
};
