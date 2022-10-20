#include <stdio.h>
#include <stdlib.h>

#include "SqQueue.h"

void InitQueue(SqQueue *Q){
	Q->front=0;
	Q->rear=0;
}

int QueueEmtpy(SqQueue Q){
	return Q.front==Q.rear;
}

void EnQueue(SqQueue *Q,ElementType e){
	if(Q->front==(Q->rear+1)%MaxSize){
		printf("队满，入队失败！\n"); 
	}else{
		Q->data[Q->rear]=e;
		Q->rear=(Q->rear+1)%MaxSize;
	}
}

ElementType DeQueue(SqQueue *Q){
	if(QueueEmtpy(*Q)){
		printf("队空，出队失败！\n"); 
	}else{
		ElementType *ptr;	
		ptr=Q;	
		Q->front=(Q->front+1)%MaxSize;
		return Q->data[Q->front];
	} 
}

void PrintQueue(SqQueue Q){
	int i=0;
	for(;i<MaxSize;i++){
		printf("%c ",Q.data[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	SqQueue mySqQueue;
	
	InitQueue(&mySqQueue);
	
	ElementType element;
	
	scanf("%c",&element);
	getchar();
	
	while(element!='z'){
		
		if(mySqQueue.front==(mySqQueue.rear+1)%MaxSize){
			DeQueue(&mySqQueue);
		}
		
		EnQueue(&mySqQueue,element);
		
		PrintQueue(mySqQueue);
		
		scanf("%c",&element);
		getchar();
	}
	
	return 0;
}
