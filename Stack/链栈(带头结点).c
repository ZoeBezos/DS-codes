#include <stdio.h>
#include <stdlib.h>

#include"LiStack.h" 


int InitLiStack(LiStack *S){
	(*S)=(LiNode*)malloc(sizeof(LiNode));
	if((*S)==NULL){
		printf("�ڴ治�㣬ͷ��㴴��ʧ�ܣ�"); 
		return 0;
	}else{
		(*S)->data=-1;
		(*S)->next=NULL;
		return 1;
	}
}

int LiStackEmtpy(LiStack S){
	return S->next==NULL;
}

int PushLiStack(LiStack *S,int e){
	LiNode* node = (LiNode*)malloc(sizeof(LiNode));
	if(node==NULL){
		printf("�ڴ����ʧ�ܣ�"); 
		return 0;
	}else{
		node->data=e;
		node->next=(*S);
		(*S) = node;
		return 1;
	}
}

int PopLiStack(LiStack *S,int *e){
	if(S==NULL){
		printf("ջ�գ���ջʧ�ܣ�\n");
		return 0; 
	}else{
		LiNode *node;
		node=(*S);
		*e=(*S)->data;
		(*S)=(*S)->next;
		free(node);
		return 1;
	}
}

int GetLiStackTop(LiStack S,int *e){
	if(S==NULL){
		printf("ջ�գ���ȡջ��Ԫ��ʧ�ܣ�\n");
		return 0; 
	}else{
		*e=S->data;
		return 1;
	}
}

//int DestroyStack(LiStack *S){
// S->top=-1;
//}


int main(int argc, char *argv[]) {
 
	LiStack myLiStack;
	
	InitLiStack(&myLiStack);
	
	int element;
	
	scanf("%d",&element);
	
	while(element!=-1){
	
		PushLiStack(&myLiStack,element);
		int myTop;
		GetLiStackTop(myLiStack,&myTop);
		printf("��ʱ��ջ��Ԫ�أ�%d\n",myTop);
		
		scanf("%d",&element);
 	}

	printf("-----------------------------\n");
 
	while(!LiStackEmtpy(myLiStack)){
		int myTop; 
		PopLiStack(&myLiStack,&myTop);
		printf("��ʱ��ջ��Ԫ�أ�%d\n",myTop);
	}
 
	return 0;
}
