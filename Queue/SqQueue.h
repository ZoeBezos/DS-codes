#define ElementType char

#define MaxSize 10

typedef struct {
	ElementType data[MaxSize];
	int front,rear;
}SqQueue;

void InitQueue(SqQueue *S);

int QueueEmtpy(SqQueue S);

void EnQueue(SqQueue *S,ElementType e);

ElementType DeQueue(SqQueue *S);

void DestroyQueue(SqQueue *S);

void PrintQueue(SqQueue S);
