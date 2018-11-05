#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct st_LinkList
{
	ElemType data;
	struct st_LinkList *next;
} LinkList;

/*����һ���յ�List*/
LinkList *LkListCreate(void);

/*����һ��List*/
void LkListDistroy(LinkList *pList);

/*���һ��List*/
void LkListClear(LinkList *pList);

/*�ж�List�Ƿ�Ϊ��,Ϊ�շ���true����Ϊ�շ���FALSE*/
BOOL LkListIsEmpty(LinkList *pList);

/*��ȡһ��List�����ڸ���*/
int LkListLength(LinkList *pList);

/*��һ��List�л�ȡһ��Ԫ��*/
ElemType *LkGetNode(LinkList *pList, int i);

/***************************
*��ȡһ��Ԫ����һ��List�е�λ��
*�ɹ�����������pList�Ƿ�����-1��û�ҵ�����-2
***************************/
int LkLocateNode(LinkList *pList, ElemType *pNode);

/*��ȡԪ�ص�ǰһ��Ԫ��*/
ElemType *LkPriorNode(LinkList *pList, ElemType *pNode);

/*��ȡԪ�صĺ�һ��Ԫ��*/
ElemType *LkNextNode(LinkList *pList, ElemType *pNode);

/*��ָ��λ�����һ��Ԫ��*/
void LkListInsert(LinkList *pList, int i, ElemType *pNode);

/*��List��ɾ��һ��Ԫ��*/
void LkListDelete(LinkList *pList, int i);

/*��ĩβ���һ��Ԫ��*/
void LkListInsertLast(LinkList *pList, ElemType *pNode);

/*ɾ�����һ��Ԫ��*/
void LkListDeleteLast(LinkList *pList);

/*��2�ϲ���1����ȥ���ظ���Ԫ��*/
void LkListUnion(LinkList *pList1, LinkList *pList2);

void LkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif

