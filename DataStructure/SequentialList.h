#ifndef __SEQUENTIALLIST__H__
#define __SEQUENTIALLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define LIST_INIT_SIZE	10	// ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT	5	// ���Ա�洢�ռ�ķ�������

typedef struct st_SqList
{
	ElemType *elem;	// �洢�ռ����ַ
	int iLength;	// ��ǰ����
	int iListSize;	// ��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
} SqList;

/*����һ���յ�List*/
SqList *SqListCreate(void);

/*����һ��List*/
void SqListDistroy(SqList *pList);

/*���һ��List*/
void SqListClear(SqList *pList);

/*�ж�List�Ƿ�Ϊ��,Ϊ�շ���true����Ϊ�շ���FALSE*/
BOOL SqListIsEmpty(SqList *pList);

/*��ȡһ��List�����ڸ���*/
int SqListLength(SqList *pList);

/*��һ��List�л�ȡһ��Ԫ��*/
ElemType *SqGetElem(SqList *pList, int i);

/***************************
 *��ȡһ��Ԫ����һ��List�е�λ��
 *�ɹ�����������pList�Ƿ�����-1��û�ҵ�����-2
 ***************************/
int SqLocateElem(SqList *pList, ElemType *pElem);

/*��ȡԪ�ص�ǰһ��Ԫ��*/
ElemType *SqPriorElem(SqList *pList, ElemType *pElem);

/*��ȡԪ�صĺ�һ��Ԫ��*/
ElemType *SqNextElem(SqList *pList, ElemType *pElem);

/*��ָ��λ�����һ��Ԫ��*/
void SqListInsert(SqList *pList, int i, ElemType *pElem);

/*��List��ɾ��һ��Ԫ��*/
void SqListDelete(SqList *pList, int i);

/*��2�ϲ���1����ȥ���ظ���Ԫ��*/
void SqListUnion(SqList *pList1, SqList *pList2);

void SqTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif


