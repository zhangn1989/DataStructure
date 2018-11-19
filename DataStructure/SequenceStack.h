#ifndef __SEQUENCESTACK__H__
#define __SEQUENCESTACK__H__

#include "public.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define STACK_INIT_SIZE	10
#define STACKINCREMENT	10

typedef struct  
{
	ElemType *base;	
	ElemType *top;
	int stacksize;
}SqStack;

SqStack *SqInitStack(void);
BOOL SqDestroyStack(SqStack *s);
void SqClearStack(SqStack *s);
BOOL SqStackIsEmpty(SqStack *);
int SqStackLength(SqStack *s);
ElemType *SqGetTop(SqStack *s);
void SqPush(SqStack *s, ElemType *elem);
ElemType SqPop(SqStack *s);
void SqStackTestFunc(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // 


