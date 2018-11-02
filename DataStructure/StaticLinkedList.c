#include "StaticLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SLinkList *SLkListCreate(void)
{
	SLinkList *p = (SLinkList *)malloc(SLIST_INIT_SIZE * sizeof(SLinkList));
	if (!p) return NULL;
	memset(p, 0, SLIST_INIT_SIZE * sizeof(SLNode));
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
	int len = SLkListLength(pList);
	memset(pList, 0, (len + 1) * sizeof(SLNode));
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
	int len = 0;
	for (int i = 0; pList[i].cur != 0; i = pList[i].cur)
		++len;
	return len;
}

SLNode *SLkGetNode(SLinkList *pList, int i)
{
	if (!pList || i < 0)
		return NULL;
	
	// 如果当前索引的cur不是0，说明当前索引cur的位置上有数据
	// 而查找的次数正好是数据的编号
	// 因此要返回当前索引的cur所在位置的数据，而不是当前索引所在位置的数据
	int no = 0;
	int cur = pList[0].cur;
	while (cur)
	{
		if (no == i)
			return &pList[cur];
		++no;
		cur = pList[cur].cur;
	}

	return NULL;
}

int SLkLocateNode(SLinkList *pList, SLNode *pNode)
{
	if (!pNode || !pList)
		return -1;

	int no = 0;
	int cur = pList[0].cur;
	while (cur)
	{
		if (ElemIsEqual(&pList[cur].data, &pNode->data))
			return no;
		++no;
		cur = pList[cur].cur;
	}

	return -2;
}

SLNode *SLkPriorNode(SLinkList *pList, SLNode *pNode)
{
	if (!pList || pNode)
		return NULL;

	if (SLkListIsEmpty(pList))
		return pList;

	int index = SLkLocateNode(pList, pNode);
	if (index == 0)
		return pList;
	if (index > 0)
		return SLkGetNode(pList, index - 1);
	return NULL;
}

SLNode *SLkNextNode(SLinkList *pList, SLNode *pNode)
{
	if (!pList || pNode)
		return NULL;
	if (pNode->cur)
		return &pList[pNode->cur];
	return NULL;
}

void SLkListInsert(SLinkList *pList, int i, SLNode *pNode)
{

}

void SLkListDelete(SLinkList *pList, int i)
{

}

void SLkListInsertLast(SLinkList *pList, SLNode *pNode)
{

}

void SLkListDeleteLast(SLinkList *pList)
{

}

void SLkListUnion(SLinkList *pList1, SLinkList *pList2)
{

}

void SLkTestFunc(void)
{

}
