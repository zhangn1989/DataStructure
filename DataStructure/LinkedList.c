#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkList *LkListCreate(void)
{
	LinkList *p = (LinkList*)malloc(sizeof(LNode));
	if (p) memset(p, 0, sizeof(LNode));
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

LNode *LkGetNode(LinkList *pList, int i)
{
	if (!pList)
		return NULL;

	int index = 0;
	LinkList *p = pList->next;
	while (p)
	{
		if (index == i)
			return p;
		p = p->next;
		++index;
	}

	//遍历结束，但没找到，即i大于总长度
	return NULL;
}

int LkLocateNode(LinkList *pList, LNode *pNode)
{
	if (!pList || !pNode)
		return -1;

	int i = 0;
	LinkList *p = pList->next;
	while (p)
	{
		if (ElemIsEqual(&(p->data), &(pNode->data)))
			return i;
		p = p->next;
		++i;
	}

	return -2;
}

LNode *LkPriorNode(LinkList *pList, LNode *pNode)
{
	if (!pList || !pNode)
		return NULL;

	if (LkListIsEmpty(pList))
		return pList;

	int index = LkLocateNode(pList, pNode);
	if (index == 0)
		return pList;
	if (index > 0)
		return LkGetNode(pList, index - 1);
	return NULL;
}

LNode *LkNextNode(LinkList *pList, LNode *pNode)
{
	if (!pList || !pNode)
		return NULL;
	return pNode->next;
}

void LkListInsert(LinkList *pList, int i, LNode *pNode)
{
	if (!pList || !pNode || i < 0 || i > LkListLength(pList))
		return;

	LNode *Prior = NULL;
	if (i == 0)
		Prior = pList;
	else
		Prior = LkGetNode(pList, i - 1);
	
	if (!Prior)
		return;

	LNode *node = (LNode *)malloc(sizeof(LNode));
	if (!node)
		return;
	memcpy(node, pNode, sizeof(LNode));
	node->next = Prior->next;
	Prior->next = node;
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

void LkListInsertLast(LinkList *pList, LNode *pNode)
{
	if (!pList || !pNode)
		return;

	LinkList *p = pList->next;
	while (p)
	{
		if (p->next == NULL)
		{
			LNode *node = (LNode*)malloc(sizeof(LNode));
			if (!node) return;
			memcpy(node, pNode, sizeof(LNode));
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
	LNode *node1 = pList1->next;
	LNode *node2 = pList2->next;

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

		LkListInsertLast(pList1, node2);
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
		LNode node;
		node.data.data = 97 + i;
		node.next = NULL;
		LkListInsert(list, i, &node);
	}

	b = LkListIsEmpty(list);
	leng = LkListLength(list);
	LNode *pNode = LkGetNode(list, 5);
	LNode *pPrior = LkPriorNode(list, pNode);
	LNode *pNext = LkNextNode(list, pNode);
	int index = LkLocateNode(list, pNext);
	LkListDelete(list, 3);
	LNode node;
	node.data.data = 97;
	node.next = NULL;
 	LkListDeleteLast(list);
 	LkListInsertLast(list, &node);

	LinkList *list1 = LkListCreate();
	if (!list1)
		goto END;
	for (int i = 0; i < 10; ++i)
	{
		LNode node;
		node.data.data = 103 + i;
		node.next = NULL;
		LkListInsert(list1, i, &node);
	}

	LkListUnion(list, list1);

END:
	LkListDistroy(list);
	LkListDistroy(list1);
}
