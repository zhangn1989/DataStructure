#ifndef __PUBLIC__H__
#define __PUBLIC__H__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BOOL
#define BOOL	int
#endif // !bool

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif // !false

typedef struct st_ElemType
{
		int data;
} ElemType;

/*比较两个elem*/
BOOL ElemIsEqual(ElemType *elem1, ElemType *elem2);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif
