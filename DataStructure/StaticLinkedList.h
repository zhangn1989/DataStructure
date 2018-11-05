#ifndef __STATICLINKEDLIST__H__
#define __STATICLINKEDLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define SLIST_INIT_SIZE	10	// ���Ա�洢�ռ�ĳ�ʼ������
#define SLISTINCREMENT	5	// ���Ա�洢�ռ�ķ�������

typedef struct st_SLinkList
{
	ElemType data;
	int cur;
	int len;
	int size;
} SLinkList;

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
ElemType *SLkGetNode(SLinkList *pList, int i);

/***************************
*��ȡһ��Ԫ����һ��List�е�λ��
*�ɹ�����������pList�Ƿ�����-1��û�ҵ�����-2
***************************/
int SLkLocateNode(SLinkList *pList, ElemType *pNode);

/*��ȡԪ�ص�ǰһ��Ԫ��*/
ElemType *SLkPriorNode(SLinkList *pList, ElemType *pNode);

/*��ȡԪ�صĺ�һ��Ԫ��*/
ElemType *SLkNextNode(SLinkList *pList, ElemType *pNode);

/*��ָ��λ�����һ��Ԫ��*/
void SLkListInsert(SLinkList *pList, int i, ElemType *pNode);

/*��List��ɾ��һ��Ԫ��*/
void SLkListDelete(SLinkList *pList, int i);

/*��ĩβ���һ��Ԫ��*/
void SLkListInsertLast(SLinkList *pList, ElemType *pNode);

/*ɾ�����һ��Ԫ��*/
void SLkListDeleteLast(SLinkList *pList);

void SLkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif


