#define ElementType int

typedef struct LinkNode{
	char data;
	struct LinkNode *next;
}LiNode,*LiStack;//Á´Õ» 

void InitLiStack(LiStack *top);

int LiStackEmtpy(LiStack top);

void PushLiStack(LiStack *top,ElementType e);

void PopLiStack(LiStack *top,ElementType *e);

void GetLiStackTop(LiStack top,ElementType *e);

int DestroyLiStack(LiNode *top);

void PrintLiStack(LiStack top);
