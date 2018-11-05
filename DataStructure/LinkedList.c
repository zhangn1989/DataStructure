#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkList *LkListCreate(void)
{
	LinkList *p = (LinkList*)malloc(sizeof(LinkList));
	if (p) memset(p, 0, sizeof(LinkList));
	return p;
}

void LkListDistroy(LinkList *pList)
{
	if (!pList)
		return;

	LkListClear(pList);
	free(pList);
	pList = NULL;
}

void LkListClear(LinkList *pList)
{
	if (!pList)
		return;

	LinkList *p = pList->next;
	while (p)
	{
		LkListDelete(pList, 0);
		p = pList->next;
	}
}

BOOL LkListIsEmpty(LinkList *pList)
{
	if (pList && pList->next)
		return FALSE;
	return TRUE;
}

int LkListLength(LinkList *pList)
{
	if (!pList) return 0;

	int leng = 0;
	LinkList *p = pList->next;
	while (p)
	{
		++leng;
		p = p->next;
	}
	return leng;
}

ElemType *LkGetNode(LinkList *pList, int i)
{
	if (!pList)
		return NULL;

	int index = 0;
	LinkList *p = pList->next;
	while (p)
	{
		if (index == i)
			return &p->data;
		p = p->next;
		++index;
	}

	//遍历结束，但没找到，即i大于总长度
	return NULL;
}

int LkLocateNode(LinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return -1;

	int i = 0;
	LinkList *p = pList->next;
	while (p)
	{
		if (ElemIsEqual(&(p->data), pNode))
			return i;
		p = p->next;
		++i;
	}

	return -2;
}

ElemType *LkPriorNode(LinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return NULL;

	if (LkListIsEmpty(pList))
		return NULL;

	LinkList *p = pList->next;
	while (p)
	{
		if (p->next && ElemIsEqual(&(p->next->data), pNode))
		{
			return &p->data;
		}
		p = p->next;
	}

	return NULL;
}

ElemType *LkNextNode(LinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return NULL;
	
	LinkList *p = pList->next;
	while (p)
	{
		if (ElemIsEqual(&(p->data), pNode))
		{
			p = p->next;
			if (p)
				return &p->data;
			else
				return NULL;
		}
		p = p->next;
	}
	return NULL;
}

void LkListInsert(LinkList *pList, int i, ElemType *pNode)
{
	if (!pList || !pNode || i < 0 || i > LkListLength(pList))
		return;

	int no = 0;
	LinkList *p = pList;
	while (p && no < i)
	{
		++no;
		p = p->next;
	}

	LinkList *node = (LinkList *)malloc(sizeof(LinkList));
	if (!node)
		return;
	memcpy(node, pNode, sizeof(LinkList));
	node->next = p->next;
	p->next = node;
}

void LkListDelete(LinkList *pList, int i)
{
	if (!pList || i < 0)
		return;

	int index = 0;
	LinkList *p = pList;
	LinkList *delNode = pList->next;
	while (delNode)
	{
		if (index == i)
		{
			p->next = delNode->next;
			free(delNode);
			return;
		}

		++index;
		p = delNode;
		delNode = p->next;
	}

	return;
}

void LkListInsertLast(LinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return;

	LinkList *p = pList->next;
	while (p)
	{
		if (p->next == NULL)
		{
			LinkList *node = (LinkList*)malloc(sizeof(LinkList));
			if (!node) return;
			memcpy(node, pNode, sizeof(LinkList));
			p->next = node;
			node->next = NULL;
			return;
		}
		p = p->next;
	}
}

void LkListDeleteLast(LinkList *pList)
{
	if (!pList)
		return;

	LinkList *p = pList;
	LinkList *delNode = pList->next;
	while (delNode)
	{
		if (delNode->next == NULL)
		{
			p->next = NULL;
			free(delNode);
			return;
		}
		p = delNode;
		delNode = p->next;
	}
}

void LkListUnion(LinkList *pList1, LinkList *pList2)
{
	if (!pList1 || !pList2)
		return;

	BOOL isFind = FALSE;
	LinkList *node1 = pList1->next;
	LinkList *node2 = pList2->next;

	for (; node2; node2 = node2->next)
	{
		isFind = FALSE;
		node1 = pList1->next;
		while (node1)
		{
			if (ElemIsEqual(&node1->data, &node2->data))
			{
				isFind = TRUE;
				break;
			}
			node1 = node1->next;
		}

		if (isFind)
			continue;

		LkListInsertLast(pList1, &node2->data);
	}
}

void LkTestFunc(void)
{
	LinkList *list = LkListCreate();
	if (!list)
		return;
	BOOL b = LkListIsEmpty(list);
	int leng = LkListLength(list);
	for (int i = 0; i < 10; ++i)
	{
		ElemType node;
		node.data = 97 + i;
		LkListInsert(list, i, &node);
	}

	b = LkListIsEmpty(list);
	leng = LkListLength(list);
	ElemType *pNode = LkGetNode(list, 5);
	ElemType *pPrior = LkPriorNode(list, pNode);
	ElemType *pNext = LkNextNode(list, pNode);
	int index = LkLocateNode(list, pNext);
	LkListDelete(list, 3);
	ElemType node;
	node.data = 97;
 	LkListDeleteLast(list);
 	LkListInsertLast(list, &node);

	LinkList *list1 = LkListCreate();
	if (!list1)
		goto END;
	for (int i = 0; i < 10; ++i)
	{
		ElemType node;
		node.data = 103 + i;
		LkListInsert(list1, i, &node);
	}

	LkListUnion(list, list1);

END:
	LkListDistroy(list);
	LkListDistroy(list1);
}
