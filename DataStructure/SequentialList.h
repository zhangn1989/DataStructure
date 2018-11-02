#ifndef __SEQUENTIALLIST__H__
#define __SEQUENTIALLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define LIST_INIT_SIZE	10	// 线性表存储空间的初始分配量
#define LISTINCREMENT	5	// 线性表存储空间的分配增量

typedef struct st_SqList
{
	ElemType *elem;	// 存储空间基地址
	int iLength;	// 当前长度
	int iListSize;	// 当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;

/*构造一个空的List*/
SqList *SqListCreate(void);

/*销毁一个List*/
void SqListDistroy(SqList *pList);

/*清空一个List*/
void SqListClear(SqList *pList);

/*判断List是否为空,为空返回true，不为空返回FALSE*/
BOOL SqListIsEmpty(SqList *pList);

/*获取一个List的属于个数*/
int SqListLength(SqList *pList);

/*从一个List中获取一个元素*/
ElemType *SqGetElem(SqList *pList, int i);

/***************************
 *获取一个元素在一个List中的位置
 *成功返回索引，pList非法返回-1，没找到返回-2
 ***************************/
int SqLocateElem(SqList *pList, ElemType *pElem);

/*获取元素的前一个元素*/
ElemType *SqPriorElem(SqList *pList, ElemType *pElem);

/*获取元素的后一个元素*/
ElemType *SqNextElem(SqList *pList, ElemType *pElem);

/*向指定位置添加一个元素*/
void SqListInsert(SqList *pList, int i, ElemType *pElem);

/*从List中删除一个元素*/
void SqListDelete(SqList *pList, int i);

/*将2合并到1，并去掉重复的元素*/
void SqListUnion(SqList *pList1, SqList *pList2);

void SqTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif


