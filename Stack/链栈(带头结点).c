#include <stdio.h>
#include <stdlib.h>

#include"LiStack.h" 


void InitLiStack(LiStack *S){
	(*S)=(LiNode*)malloc(sizeof(LiNode));
	if((*S)==NULL){
		printf("�ڴ治�㣬ͷ��㴴��ʧ�ܣ�"); 
	}else{
		(*S)->data=-1;
		(*S)->next=NULL;
	}
}

int LiStackEmtpy(LiStack S){
	return S->next==NULL;
}

void PushLiStack(LiStack *S,int e){
	LiNode* node = (LiNode*)malloc(sizeof(LiNode));
	if(node==NULL){
		printf("�ڴ����ʧ�ܣ�"); 
	}else{
		node->data=e;
		node->next=(*S);
		(*S) = node;
	}
}

void PopLiStack(LiStack *S,ElementType *e){
	if(S==NULL){
		printf("ջ�գ���ջʧ�ܣ�\n");
	}else{
		LiNode *node;
		node=(*S);
		*e=(*S)->data;
		(*S)=(*S)->next;
		free(node);
	}
}

void GetLiStackTop(LiStack S,ElementType *e){
	if(S==NULL){
		printf("ջ�գ���ȡջ��Ԫ��ʧ�ܣ�\n");
	}else{
		*e=S->data;
	}
}

void PrintLiStack(LiStack S){
	LiNode *ptr=S;
	printf("Ŀǰջ��Ԫ���У�");
	while(ptr->next!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

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
		PrintLiStack(myLiStack); 
		
		scanf("%d",&element);
 	}

 
	while(!LiStackEmtpy(myLiStack)){
		int myTop; 
		PopLiStack(&myLiStack,&myTop);
		printf("��ʱ��ջ��Ԫ�أ�%d\n",myTop);
		PrintLiStack(myLiStack); 
	}
 
	return 0;
}
