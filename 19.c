#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int date;
	struct Node *next;	//指向下一个节点的指针
	struct Node *prior;//指向上一个节点的指针
}Node;

int NodeInitiate(Node **head)
/*初始化*/
/*成功返回1，失败返回0*/
{
	if ((*head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("内存不足，无法初始化!\n");
		return 0;
	}
	(*head)->next = *head;
	(*head)->prior = *head;
	return 1;
}


int NodeInsert(Node *head, int n, int d)
/*插入数据元素d到链表的第n(n>=0)个节点*/
{
	int i = 0;
	Node *p1 = head,*p;
	if (n<0)
	{
		printf("插入位置参数错误!\n");
		return 0;
	}



	while (i<n)
	//寻找第n个节点
	{
		p1 = p1->next;
		if (p1 == head)//跳过头节点
			i++;
		i++;
	}
	p = (Node *)malloc(sizeof(Node));
	p->date = d;		//新结点赋值
	//结点连接
	p->next = p1->next;
	p->next->prior = p1;
	p1->next = p;
	p->prior = p1;
	return 0;
}


int NodeDestroy(Node *head)
/*销毁循环链表*/
{
	Node *p = head->next;

	while (p != head)
	{
		head->next = p->next;
		free(p);
		p = head->next;
	}
	head->prior = head;
	return 1;
}


int NodeReplace(Node *head, int n, int d)
/*替换第n个节点的数据元素为d*/
{
	int i = 0;
	Node  *p1;
	if (n<0)
	{
		printf("参数错误<0!\n");
		return 0;
	}
	p1 = head;
	while (i<n)
	{
		if (p1 == head)//跳过头节点
		{
			i++;
		}
		p1 = p1->next;
		i++;
	}
	p1->next->date = d;
	return 1;
}
int NodeGet(Node *head, int n, int *d)
/*取链表的第n个元素放到d中被带回*/
{
	int i = 0;
	Node *p1;
	if (n<0)
	{
		printf("参数错误<0!\n");
		return 0;
	}
	
	p1 = head;

	while (i<n)
	{	//此循环寻找结点
		if (p1 == head)
		{
			i++;
		}
		p1 = p1->next;
		i++;
	}

	//将该结点的元素赋值给d
	*d = p1->next->date;
	return 1;
}

void show(Node *head)
/*打印链表*/
{
	Node *p=head->next;
	while (p!= head)
	{
		printf("%d ", p->date);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	Node *head;
	int n,i,x;
	//初始化
	NodeInitiate(&head);
	printf("请输入要插入数据的个数:\n");
	scanf("%d", &n);
	printf("请输入插入数据:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		NodeInsert(head, i, x);
	}
	show(head);
	printf("请输入要查入的数据以及位置:\n");
	scanf("%d %d", &x, &i);
	NodeInsert(head, i, x);
	show(head);
	NodeDestroy(head);
	return 0;
}