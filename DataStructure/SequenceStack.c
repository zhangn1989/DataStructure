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
	s->top = s->base;
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

BOOL SqPop(SqStack *s, ElemType *elem)
{
	if (!s || !s->base || s->base == s->top)
		return FALSE;

	--s->top;
	if (elem)
		memcpy(elem, s->top, sizeof(ElemType));
	memset(s->top, 0, sizeof(ElemType));
	return TRUE;
}

void SqStackTestFunc(void)
{
	LineEdit("whli##ilr#e(s# * s)");
	LineEdit("outcha@putchar( * s =# ++);");
	conversion(1348);
	BracketTest("456(123(4556(678)(4567)4658)65467)8674");
	BracketTest("()(((())())()()))))()(");
	BracketTest(")(()()))");
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
	SqPop(s, &et);

	SqClearStack(s);
	SqDestroyStack(s);
}

void conversion(int N)
{
	SqStack *s = SqInitStack();
	if (!s)
		return;
	ElemType elem;
	elem.data = N;
	while (elem.data)
	{
		ElemType tmp;
		tmp.data = elem.data % 8;
		SqPush(s, &tmp);
		elem.data = elem.data / 8;
	}

	while (!SqStackIsEmpty(s))
	{
		SqPop(s, &elem);
		printf("%d", elem.data);
	}
	printf("\n");
	SqDestroyStack(s);
}

BOOL BracketTest(const char *str)
{
	SqStack *s = SqInitStack();
	if (!s)
		return FALSE;

	int i;
	ElemType elem;
	for (i = 0; str[i] != 0; ++i)
	{
		if (str[i] == '(')
		{
			elem.data = str[i];
			SqPush(s, &elem);
		}
		else if(str[i] == ')')
		{
			if (!SqPop(s, &elem))
				return FALSE;
		}
		else
		{
			continue;
		}
	}
	
	BOOL ret = SqStackIsEmpty(s);
	SqDestroyStack(s);
	return ret;
}

void LineEdit(const char *str)
{
	SqStack *s = SqInitStack();
	if (!s)
		return ;

	int i;
	ElemType elem;

	for (i = 0; str[i] != 0; ++i)
	{
		switch (str[i])
		{
		case '#':
			SqPop(s, NULL);
			break;
		case '@':
			SqClearStack(s);
			break;
		default:
			elem.data = str[i];
			SqPush(s, &elem);
		}
	}

	ElemType *p = s->base;
	while (p != s->top)
	{
		printf("%c", p->data);
		++p;
	}
	printf("\n");
	SqDestroyStack(s);
}

void MazePath()
{

}

void EvaluateExpression(const char *str)
{

}