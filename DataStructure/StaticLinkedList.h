#ifndef __STATICLINKEDLIST__H__
#define __STATICLINKEDLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define SLIST_INIT_SIZE	10	// ���Ա�洢�ռ�ĳ�ʼ������
#define SLISTINCREMENT	5	// ���Ա�洢�ռ�ķ�������

typedef struct st_SLNode
{
	ElemType data;
	int cur;
} SLNode;

typedef SLNode SLinkList;

/*����һ���յ�List*/
SLinkList *SLkListCreate(void);

/*����һ��List*/
void SLkListDistroy(SLinkList *pList);

/*���һ��List*/
void SLkListClear(SLinkList *pList);

/*�ж�List�Ƿ�Ϊ��,Ϊ�շ���true����Ϊ�շ���FALSE*/
BOOL SLkListIsEmpty(SLinkList *pList);

/*��ȡһ��List�����ڸ���*/
int SLkListLength(SLinkList *pList);

/*��һ��List�л�ȡһ��Ԫ��*/
SLNode *SLkGetNode(SLinkList *pList, int i);

/***************************
*��ȡһ��Ԫ����һ��List�е�λ��
*�ɹ�����������pList�Ƿ�����-1��û�ҵ�����-2
***************************/
int SLkLocateNode(SLinkList *pList, SLNode *pNode);

/*��ȡԪ�ص�ǰһ��Ԫ��*/
SLNode *SLkPriorNode(SLinkList *pList, SLNode *pNode);

/*��ȡԪ�صĺ�һ��Ԫ��*/
SLNode *SLkNextNode(SLinkList *pList, SLNode *pNode);

/*��ָ��λ�����һ��Ԫ��*/
void SLkListInsert(SLinkList *pList, int i, SLNode *pNode);

/*��List��ɾ��һ��Ԫ��*/
void SLkListDelete(SLinkList *pList, int i);

/*��ĩβ���һ��Ԫ��*/
void SLkListInsertLast(SLinkList *pList, SLNode *pNode);

/*ɾ�����һ��Ԫ��*/
void SLkListDeleteLast(SLinkList *pList);

/*��2�ϲ���1����ȥ���ظ���Ԫ��*/
void SLkListUnion(SLinkList *pList1, SLinkList *pList2);

void SLkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif


