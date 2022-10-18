#include<stdio.h>
#include<stdlib.h> 

typedef struct LinkNode{
	char data;
	struct LinkNode *next;
}LiNode,*LiStack;//Á´Õ» 

void InitLiStack(LiStack *top);

int LiStackEmtpy(LiStack top);

int PushLiStack(LiStack *top,char e);

int PopLiStack(LiStack *top,char *e);

int GetLiStackTop(LiStack top,char *e);

int DestroyLiStack(LiNode *top);

void PrintLiStack(LiStack top);
