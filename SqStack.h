#include<stdio.h>
#include<stdlib.h> 

#define MaxSize 50 

typedef struct{
	int data[MaxSize];
	int top;
}SqStack;//À≥–Ú’ª 

void InitStack(SqStack *S);

int StackEmtpy(SqStack S);

int Push(SqStack *S,int e);

int Pop(SqStack *S);

int GetTop(SqStack S);

void DestroyStack(SqStack *S);

void PrintStack(SqStack S);


