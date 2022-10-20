#define ElementType char 

#define MaxSize 50 

typedef struct{
	int data[MaxSize];
	int top;
}SqStack;//À≥–Ú’ª 

void InitStack(SqStack *S);

int StackEmtpy(SqStack S);

void Push(SqStack *S,ElementType  e);

ElementType  Pop(SqStack *S);

ElementType  GetTop(SqStack S);

void DestroyStack(SqStack *S);

void PrintStack(SqStack S);


