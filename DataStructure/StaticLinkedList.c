#include "StaticLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SLinkList *SLkListCreate(void)
{
	SLinkList *p = (SLinkList *)malloc(SLIST_INIT_SIZE * sizeof(SLinkList));
	if (!p) return NULL;

	memset(p, 0, SLIST_INIT_SIZE  * sizeof(SLinkList));
	p->size = SLIST_INIT_SIZE;

	for (int i = 1; i < p->size; ++i)
		p[i].cur = -1;

	return p;
}

void SLkListDistroy(SLinkList *pList)
{
	if (pList)
	{
		free(pList);
		pList = NULL;
	}
}

void SLkListClear(SLinkList *pList)
{
	if (!pList) return;
	memset(&pList[1], 0, (pList->size - 1) * sizeof(SLinkList));

	for (int i = 1; i < pList->size; ++i)
		pList[i].cur = -1;
}

BOOL SLkListIsEmpty(SLinkList *pList)
{
	if (pList && pList[0].cur)
		return FALSE;
	return TRUE;
}

int SLkListLength(SLinkList *pList)
{
	if (!pList) return 0;

	return pList->len;
}

ElemType *SLkGetNode(SLinkList *pList, int i)
{
	if (!pList || i < 0)
		return NULL;
	
	int no = 0;
	SLinkList *node = pList;
	while (node->cur)
	{
		if (no == i)
			return &pList[node->cur].data;

		++no;
		node = &pList[node->cur];
	}

	return NULL;
}

int SLkLocateNode(SLinkList *pList, ElemType *pNode)
{
	if (!pNode || !pList)
		return -1;

	int no = 0;
	int cur = pList[0].cur;
	while (cur)
	{
		if (ElemIsEqual(&pList[cur].data, pNode))
			return no;
		++no;
		cur = pList[cur].cur;
	}

	return -2;
}

ElemType *SLkPriorNode(SLinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return NULL;

	int index = SLkLocateNode(pList, pNode);
	if (index == 0)
		return NULL;
	if (index > 0 && index < pList->len)
	{
		return SLkGetNode(pList, index - 1);
	}
	return NULL;
}

ElemType *SLkNextNode(SLinkList *pList, ElemType *pNode)
{
	if (!pList || !pNode)
		return NULL;

	int index = SLkLocateNode(pList, pNode);
	if (index >= 0 && index < pList->len - 1)
	{
		return SLkGetNode(pList, index + 1);
	}
	return NULL;
}

void SLkListInsert(SLinkList *pList, int i, ElemType *pNode)
{
	if (!pList || !pNode || i < 0 || i > pList->len)
		return;
	
	if (pList->len >= pList->size)
	{
		SLinkList *p = realloc(pList,
			(pList->size + SLISTINCREMENT) * sizeof(SLinkList));

		if (!p)
			return;

		memset(pList + pList->size, 0, SLISTINCREMENT * sizeof(SLinkList));
		pList = p;
		pList->size += SLISTINCREMENT;
	}

	int index = 1;
	for ( ;index < pList->size; ++index)
	{
		if (pList[index].cur < 0)
		{
			memcpy(&pList[index].data, pNode, sizeof(ElemType));
			break;
		}
	}

	int no = 0;
	SLinkList *node = pList;
	while (node->cur && no <= i)
	{
		++no;
		node = &pList[node->cur];
	}

	if (no > i)
		return;

	pList[index].cur = node->cur;
	node->cur = index;
	pList->len++;

}

void SLkListDelete(SLinkList *pList, int i)
{
	if (!pList || i < 0 || i >= pList->len)
		return;

	int no = 0;
	SLinkList *node = pList;
	while (node->cur)
	{
		if (no == i)
		{
			int cur = node->cur;
			node->cur = pList[node->cur].cur;
			pList[cur].cur = -1;
			pList->len--;
			break;
		}

		++no;
		node = &pList[node->cur];
	}
}

void SLkListInsertLast(SLinkList *pList, ElemType *pNode)
{
	SLkListInsert(pList, SLkListLength(pList), pNode);
}

void SLkListDeleteLast(SLinkList *pList)
{
	SLkListDelete(pList, SLkListLength(pList) - 1);
}

void SLkTestFunc(void)
{
	SLinkList *list = SLkListCreate();
	if (!list)
		return;
	BOOL b = SLkListIsEmpty(list);
	int leng = SLkListLength(list);
	for (int i = 0; i < 10; ++i)
	{
		ElemType node;
		node.data = 97 + i;
		SLkListInsert(list, i, &node);
	}

	b = SLkListIsEmpty(list);
	leng = SLkListLength(list);
	ElemType *pNode = SLkGetNode(list, 5);
	ElemType *pPrior = SLkPriorNode(list, pNode);
	ElemType *pNext = SLkNextNode(list, pNode);
	int index = SLkLocateNode(list, pNext);
	SLkListDelete(list, 3);
	ElemType node;
	node.data = 97;
	SLkListDeleteLast(list);
	SLkListInsertLast(list, &node);

	SLkListClear(list);
	SLkListDistroy(list);
}
