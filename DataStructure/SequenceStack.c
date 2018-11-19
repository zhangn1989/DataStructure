#include "SequenceStack.h"

SqStack *SqInitStack(void)
{
	SqStack *s = (SqStack *)malloc(sizeof(SqStack));
	if (!s)
		return NULL;
	memset(s, 0, sizeof(SqStack));

	s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!s->base)
	{
		free(s);
		return NULL;
	}
	memset(s->base, 0, sizeof(ElemType) * STACK_INIT_SIZE);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return s;
}

BOOL SqDestroyStack(SqStack *s)
{
	if (!s)
		return FALSE;

	if (s->base)
		free(s->base);

	free(s);
	return TRUE;
}

void SqClearStack(SqStack *s)
{
	if (!s || !s->base)
		return;

	memset(s->base, 0, s->stacksize * sizeof(ElemType));
}

BOOL SqStackIsEmpty(SqStack *s)
{
	if(s && s->base && s->base != s->top)
		return FALSE;
	return TRUE;
}

int SqStackLength(SqStack *s)
{
	if (!s)
		return -1;

	return s->top - s->base;
}

ElemType *SqGetTop(SqStack *s)
{
	if (!s || !s->base || s->base == s->top)
		return NULL;

	return s->top - 1;
}

void SqPush(SqStack *s, ElemType *elem)
{
	if (!s || !s->base)
		return;

	if (s->top - s->base >= s->stacksize)
	{
		ElemType *p = realloc(s->base,
			(s->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!p)
			return;

		memset(p + s->stacksize,
			0, STACKINCREMENT * sizeof(ElemType));

		s->base = p;
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}

	memcpy(s->top, elem, sizeof(ElemType));
	++s->top;
}

ElemType SqPop(SqStack *s)
{
	ElemType elem;
	memset(&elem, 0, sizeof(elem));

	if (!s || !s->base)
		return elem;

	--s->top;
	elem = *(s->top);
	memset(s->top, 0, sizeof(ElemType));
	return elem;
}

void SqStackTestFunc(void)
{
	SqStack *s = SqInitStack();
	if (!s)
		return;

	BOOL b = SqStackIsEmpty(s);

	for (int i = 0; i < 10; ++i)
	{
		ElemType elem;
		elem.data = 97 + i;
		SqPush(s, &elem);
	}

	b = SqStackIsEmpty(s);
	int iLen = SqStackLength(s);
	ElemType *pElem = SqGetTop(s);
	ElemType et;
	et.data = 'z';
	SqPush(s, &et);
	et = SqPop(s);

	SqClearStack(s);
	SqDestroyStack(s);
}