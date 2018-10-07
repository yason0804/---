#include <stdio.h>
#include <stdlib.h>

#define SUCCESS    1
#define FAIL       0
#define EMPTY     -1
#define StackSize  1000

typedef int Status;
typedef int ElementType;


/* 封装链式栈的节点 */
typedef struct LinkStackNode
{
	ElementType data;
	struct LinkStackNode *next;
}LinkStackNode, *LinkStackNode_Ptr;



/*
*Summary: 顺序栈的进栈算法；
*Parameters: (ElementType s[], int &top, ElementType data)
*Return: SUCCESS:表示成功； FAIL：表示失败；
*/
int SequentPush(ElementType s[], int &top, ElementType data)
{
	if (top == StackSize - 1) return FAIL;
	s[++top] = data;

	printf("顺序栈插入元素：%d\n", s[top]);
	return SUCCESS;
}

/*
*Summary: 顺序栈的退栈算法；
*Parameters: (ElementType s[], int &top, ElementType data)
*Return: SUCCESS:表示成功； FAIL：表示失败；
*/
int SequentPop(ElementType s[], int &top, ElementType &data)
{
	if (top == EMPTY) return FAIL;

	data = s[top--];

	return SUCCESS;
}

/*
*Summary: 链式栈的进栈算法
*Parameters: ( LinkStackNode_Ptr &top, ElementType data)
*Return: SUCCESS:表示成功； FAIL：表示失败；
*/
int LinkStackPush(LinkStackNode_Ptr &top, ElementType data)
{
	LinkStackNode_Ptr NewNode = (LinkStackNode_Ptr)malloc(sizeof(LinkStackNode));

	if (NewNode == NULL) return FAIL;

	NewNode->data = data;
	NewNode->next = top;
	top = NewNode;

	printf("链式栈插入元素：%d\n", top->data);

	return SUCCESS;
}

/*
*Summary: 链式栈的出栈算法
*Parameters: ( LinkStackNode_Ptr &top, ElementType data)
*Return: SUCCESS:表示成功； FAIL：表示失败；
*/
int LinkStackPop(LinkStackNode_Ptr &top, ElementType &data)
{
	if (top == NULL) return FAIL;

	LinkStackNode_Ptr p;
	
	p = top;
	data = top->data;
	top = top->next;
	free(p);

	printf("链式栈出栈元素：%d\n", data);

	return SUCCESS;
}




int main()
{
	/* 1、顺序栈进栈 */
	int SequentStack[StackSize];
	int StackTop=5; //指定栈的栈顶位置；

	for (int i = 0; i < 5; i++)  //循环在顺序栈中插入5个元素（0，1，2，3，4，5）；
	{
		SequentPush(SequentStack, StackTop, i);
	}

	/* 2、顺序栈退栈 */
	int SequentStack_PopData;  //存储顺序栈出栈元素的值；

	for (size_t i = 0; i < 5; i++)
	{
		SequentPop(SequentStack, StackTop, SequentStack_PopData);
		printf("顺序栈出栈元素：%d\n", SequentStack_PopData);
	}
	
	/* 3、链式栈进栈 */
	LinkStackNode_Ptr LinkStack_Top;
	for (int i = 0; i < 10; i++) //循环进栈10个元素；
	{
		LinkStackPush(LinkStack_Top, i);
	}
	
	/* 4、链式出栈 */
	int PopData; //用来存储出栈元素的值；
	
	for (int i = 0; i < 10; i++) //循环出栈10个元素；
	{
		LinkStackPop(LinkStack_Top, PopData);
	}
	
	
	return 0;
}
