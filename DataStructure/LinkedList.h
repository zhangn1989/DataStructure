#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct st_LNode
{
	ElemType data;
	struct st_LNode *next;
} LNode;

typedef LNode LinkList;

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
LNode *LkGetNode(LinkList *pList, int i);

/***************************
*��ȡһ��Ԫ����һ��List�е�λ��
*�ɹ�����������pList�Ƿ�����-1��û�ҵ�����-2
***************************/
int LkLocateNode(LinkList *pList, LNode *pNode);

/*��ȡԪ�ص�ǰһ��Ԫ��*/
LNode *LkPriorNode(LinkList *pList, LNode *pNode);

/*��ȡԪ�صĺ�һ��Ԫ��*/
LNode *LkNextNode(LinkList *pList, LNode *pNode);

/*��ָ��λ�����һ��Ԫ��*/
void LkListInsert(LinkList *pList, int i, LNode *pNode);

/*��List��ɾ��һ��Ԫ��*/
void LkListDelete(LinkList *pList, int i);

/*��ĩβ���һ��Ԫ��*/
void LkListInsertLast(LinkList *pList, LNode *pNode);

/*ɾ�����һ��Ԫ��*/
void LkListDeleteLast(LinkList *pList);

/*��2�ϲ���1����ȥ���ظ���Ԫ��*/
void LkListUnion(LinkList *pList1, LinkList *pList2);

void LkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif

