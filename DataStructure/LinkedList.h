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

/*构造一个空的List*/
LinkList *LkListCreate(void);

/*销毁一个List*/
void LkListDistroy(LinkList *pList);

/*清空一个List*/
void LkListClear(LinkList *pList);

/*判断List是否为空,为空返回true，不为空返回FALSE*/
BOOL LkListIsEmpty(LinkList *pList);

/*获取一个List的属于个数*/
int LkListLength(LinkList *pList);

/*从一个List中获取一个元素*/
ElemType *LkGetNode(LinkList *pList, int i);

/***************************
*获取一个元素在一个List中的位置
*成功返回索引，pList非法返回-1，没找到返回-2
***************************/
int LkLocateNode(LinkList *pList, ElemType *pNode);

/*获取元素的前一个元素*/
ElemType *LkPriorNode(LinkList *pList, ElemType *pNode);

/*获取元素的后一个元素*/
ElemType *LkNextNode(LinkList *pList, ElemType *pNode);

/*向指定位置添加一个元素*/
void LkListInsert(LinkList *pList, int i, ElemType *pNode);

/*从List中删除一个元素*/
void LkListDelete(LinkList *pList, int i);

/*向末尾添加一个元素*/
void LkListInsertLast(LinkList *pList, ElemType *pNode);

/*删除最后一个元素*/
void LkListDeleteLast(LinkList *pList);

/*将2合并到1，并去掉重复的元素*/
void LkListUnion(LinkList *pList1, LinkList *pList2);

void LkTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif

