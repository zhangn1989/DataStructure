#include "public.h"

BOOL ElemIsEqual(ElemType *elem1, ElemType *elem2)
{
	if (elem1 && elem2)
	{
		if (elem1->data == elem2->data)
			return TRUE;
	}
	return FALSE;
}