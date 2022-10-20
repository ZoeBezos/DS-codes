#include <stdio.h>
#include <stdlib.h>

#include "LiQueue.h"

void InitLiQueue(LiQueue *Q){
	(*Q).front=(*Q).rear=(LiNode*)malloc(sizeof(LiNode));
	(*Q).front->next=NULL;
}

int LiQueueEmpty(LiQueue Q){
	return Q.front==Q.rear;
}

void EnLiQueue(LiQueue *Q,ElementType e){
	LiNode *p=(LiNode*)malloc(sizeof(LiNode));
	if(!p){
		printf("内存不足，结点分配失败！\n"); 
	}else{
		p->data=e;
		p->next=NULL;
		(*Q).rear->next=p;
		(*Q).rear=p;
	}
}

void DeLiQueue(LiQueue *Q,ElementType *e){
	if(LiQueueEmpty(*Q)){
		printf("队列空，出队失败！\n"); 
	}else{
		LiNode *p=(*Q).front->next;
		*e=p->data;
		(*Q).front->next=p->next;
		free(p);
	}
}

void PrintLiQueue(LiQueue Q){
	LiNode *ptr=Q.front->next;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	LiQueue myLiQueue;
	
	InitLiQueue(&myLiQueue);
	
	ElementType element;
	
	scanf("%d",&element);
	
	while(element!=-1){
		
		EnLiQueue(&myLiQueue,element);
		
		PrintLiQueue(myLiQueue);
		
		scanf("%d",&element);
		
	}
	
	LiNode *ptr=myLiQueue.front;
	
	while(ptr!=myLiQueue.rear){
		
		DeLiQueue(&myLiQueue,&element);
		
		PrintLiQueue(myLiQueue);
		ptr=ptr->next;
	}	


	
	return 0;
}
