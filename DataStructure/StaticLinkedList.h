#ifndef __STATICLINKEDLIST__H__
#define __STATICLINKEDLIST__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define SLIST_INIT_SIZE	10	// 线性表存储空间的初始分配量
#define SLISTINCREMENT	5	// 线性表存储空间的分配增量

typedef struct st_SLinkList
{
	ElemType data;
	int cur;
	int len;
	int size;
} SLinkList;

/*构造一个空的List*/
SLinkList *SLkListCreate(void);

/*销毁一个List*/
void SLkListDistroy(SLinkList *pList);

/*清空一个List*/
void SLkListClear(SLinkList *pList);

/*判断List是否为空,为空返回true，不为空返回FALSE*/
BOOL SLkListIsEmpty(SLinkList *pList);

/*获取一个List的属于个数*/
int SLkListLength(SLinkList *pList);

/*从一个List中获取一个元素*/
ElemType *SLkGetNode(SLinkList *pList, int i);

/***************************
*获取一个元素在一个List中的位置
*成功返回索引，pList非法返回-1，没找到返回-2
***************************/
int SLkLocateNode(SLinkList *pList, ElemType *pNode);

/*获取元素的前一个元素*/
ElemType *SLkPriorNode(SLinkList *pList, ElemType *pNode);

/*获取元素的后一个元素*/
ElemType *SLkNextNode(SLinkList *pList, ElemType *pNode);

/*向指定位置添加一个元素*/
void SLkListInsert(SLinkList *pList, int i, ElemType *pNode);

/*从List中删除一个元素*/
void SLkListDelete(SLinkList *pList, int i);

/*向末尾添加一个元素*/
void SLkListInsertLast(SLinkList *pList, ElemType *pNode);

/*删除最后一个元素*/
void SLkListDeleteLast(SLinkList *pList);

void SLkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif


