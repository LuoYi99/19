#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int date;
	struct Node *next;	//ָ����һ���ڵ��ָ��
	struct Node *prior;//ָ����һ���ڵ��ָ��
}Node;

int NodeInitiate(Node **head)
/*��ʼ��*/
/*�ɹ�����1��ʧ�ܷ���0*/
{
	if ((*head = (Node *)malloc(sizeof(Node))) == NULL)
	{
		printf("�ڴ治�㣬�޷���ʼ��!\n");
		return 0;
	}
	(*head)->next = *head;
	(*head)->prior = *head;
	return 1;
}


int NodeInsert(Node *head, int n, int d)
/*��������Ԫ��d������ĵ�n(n>=0)���ڵ�*/
{
	int i = 0;
	Node *p1 = head,*p;
	if (n<0)
	{
		printf("����λ�ò�������!\n");
		return 0;
	}



	while (i<n)
	//Ѱ�ҵ�n���ڵ�
	{
		p1 = p1->next;
		if (p1 == head)//����ͷ�ڵ�
			i++;
		i++;
	}
	p = (Node *)malloc(sizeof(Node));
	p->date = d;		//�½�㸳ֵ
	//�������
	p->next = p1->next;
	p->next->prior = p1;
	p1->next = p;
	p->prior = p1;
	return 0;
}


int NodeDestroy(Node *head)
/*����ѭ������*/
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
/*�滻��n���ڵ������Ԫ��Ϊd*/
{
	int i = 0;
	Node  *p1;
	if (n<0)
	{
		printf("��������<0!\n");
		return 0;
	}
	p1 = head;
	while (i<n)
	{
		if (p1 == head)//����ͷ�ڵ�
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
/*ȡ����ĵ�n��Ԫ�طŵ�d�б�����*/
{
	int i = 0;
	Node *p1;
	if (n<0)
	{
		printf("��������<0!\n");
		return 0;
	}
	
	p1 = head;

	while (i<n)
	{	//��ѭ��Ѱ�ҽ��
		if (p1 == head)
		{
			i++;
		}
		p1 = p1->next;
		i++;
	}

	//���ý���Ԫ�ظ�ֵ��d
	*d = p1->next->date;
	return 1;
}

void show(Node *head)
/*��ӡ����*/
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
	//��ʼ��
	NodeInitiate(&head);
	printf("������Ҫ�������ݵĸ���:\n");
	scanf("%d", &n);
	printf("�������������:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		NodeInsert(head, i, x);
	}
	show(head);
	printf("������Ҫ����������Լ�λ��:\n");
	scanf("%d %d", &x, &i);
	NodeInsert(head, i, x);
	show(head);
	NodeDestroy(head);
	return 0;
}