#include "SequentialList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SqList * SqListCreate(void)
{
	SqList *pList = (SqList *)malloc(sizeof(SqList));
	if(!pList)
		return NULL;
	memset(pList, 0, sizeof(SqList));

	ElemType *pElem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!pElem)
	{
		free(pList);
		return NULL;
	}
	memset(pElem, 0, LIST_INIT_SIZE * sizeof(ElemType));

	pList->elem = pElem;
	pList->iLength = 0;
	pList->iListSize = LIST_INIT_SIZE;

	return pList;
}

void SqListDistroy(SqList * pList)
{
	if (!pList)
		return;

	if (pList->elem)
		free(pList->elem);

	free(pList);
	pList = NULL;

	return;
}

void SqListClear(SqList * pList)
{
	if (!pList)
		return;

	memset(pList->elem, 0, pList->iLength * sizeof(ElemType));
	pList->iLength = 0;

	return;
}

BOOL SqListIsEmpty(SqList * pList)
{
	if (pList && pList->iLength > 0)
		return FALSE;
	return TRUE;
}

int SqListLength(SqList * pList)
{
	if (pList)
		return pList->iLength;
	return 0;
}

ElemType * SqGetElem(SqList * pList, int i)
{
	if (pList && i >= 0 && i < pList->iLength)
		return &(pList->elem[i]);
	return NULL;
}

int SqLocateElem(SqList * pList, ElemType * pElem)
{
	if (!pList)
		return -1;

	for (int i = 0; i < pList->iLength; ++i)
	{
		if (ElemIsEqual(pElem, &(pList->elem[i])))
			return i;
	}

	return -2;
}

ElemType * SqPriorElem(SqList * pList, ElemType * pElem)
{
	int index = SqLocateElem(pList, pElem);
	if (index > 0 && index < pList->iLength)
	{
		return SqGetElem(pList, index - 1);
	}
	return NULL;
}

ElemType * SqNextElem(SqList * pList, ElemType * pElem)
{
	int index = SqLocateElem(pList, pElem);
	if (index >= 0 && index < pList->iLength - 1)
	{
		return SqGetElem(pList, index + 1);
	}
	return NULL;
}

void SqListInsert(SqList * pList, int i, ElemType * pElem)
{
	if (!pList || !pElem || i < 0 || i > SqListLength(pList))
		return;

	if (pList->iLength >= pList->iListSize)
	{
		ElemType *p = realloc(pList->elem,
			(pList->iListSize + LISTINCREMENT) * sizeof(ElemType));
		
		if (!p)
			return;

		memset((char *)pList->elem + pList->iListSize * sizeof(ElemType), 
			0, LISTINCREMENT * sizeof(ElemType));
		pList->elem = p;
		pList->iListSize += LISTINCREMENT;
	}

	for (int index = pList->iLength - 1; index > i; --index)
	{
		memcpy(&(pList->elem[index + 1]), &(pList->elem[index]), sizeof(ElemType));
	}

	memcpy(&(pList->elem[i]), pElem, sizeof(ElemType));
	pList->iLength += 1;
}

void SqListDelete(SqList * pList, int i)
{
	if (!pList)
		return;

	for (int index = i; index < pList->iLength - 1; ++index)
	{
		memcpy(&(pList->elem[index]), &(pList->elem[index + 1]), sizeof(ElemType));
	}

	memset(&(pList->elem[pList->iLength - 1]), 0, sizeof(ElemType));
	pList->iLength -= 1;
}

void SqListUnion(SqList *pList1, SqList *pList2)
{
	if (!pList1 || !pList2)
		return;

	BOOL isFind = FALSE;
	int i1 = 0, i2 = 0;
	ElemType *elem1 = NULL, *elem2 = NULL;

	for (; i2 < pList2->iLength; ++i2)
	{
		isFind = FALSE;
		for (i1 = 0; i1 < pList1->iLength; ++i1)
		{
			elem1 = SqGetElem(pList1, i1);
			elem2 = SqGetElem(pList2, i2);
			if (ElemIsEqual(elem1, elem2))
			{
				isFind = TRUE;
				break;
			}
		}

		if(isFind)
			continue;

		SqListInsert(pList1, SqListLength(pList1), elem2);
	}
}

void SqTestFunc(void)
{
	SqList *pList = SqListCreate();
	if (!pList)
		return;

	BOOL b = SqListIsEmpty(pList);

	for (int i = 0; i < 10; ++i)
	{
		ElemType elem;
		elem.data = 97 + i;
		SqListInsert(pList, i, &elem);
	}

	b = SqListIsEmpty(pList);
	int iLen = SqListLength(pList);
	ElemType elem;
	memcpy(&elem, SqGetElem(pList, 5), sizeof(ElemType));
	int iLocal = SqLocateElem(pList, &elem);
	ElemType *pElem = SqPriorElem(pList, &elem);
	pElem = SqNextElem(pList, &elem);
	ElemType et;
	et.data = 'z';
	SqListInsert(pList, 5, &et);
	SqListDelete(pList, 7);

	SqList *pList1 = SqListCreate();
	if (!pList1)
		goto END;

	for (int i = 0; i < 10; ++i)
	{
		ElemType elem;
		elem.data = 103 + i;
		SqListInsert(pList1, i, &elem);
	}

	SqListUnion(pList, pList1);

END:
	SqListClear(pList1);
	SqListDistroy(pList1);
	SqListClear(pList);
	SqListDistroy(pList);
}