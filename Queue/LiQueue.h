#define ElementType int

typedef struct LiNode{
	ElementType data;
	struct LiNode *next;
}LiNode; 

typedef struct{
	LiNode *front,*rear;
}LiQueue;

void InitLiQueue(LiQueue *Q);

int LiQueueEmpty(LiQueue Q);

void EnLiQueue(LiQueue *Q,ElementType e);

void DeLiQueue(LiQueue *Q,ElementType *e);

void PrintLiQueue(LiQueue Q);
