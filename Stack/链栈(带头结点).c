#include <stdio.h>
#include <stdlib.h>

#include"LiStack.h" 


void InitLiStack(LiStack *S){
	(*S)=(LiNode*)malloc(sizeof(LiNode));
	if((*S)==NULL){
		printf("内存不足，头结点创建失败！"); 
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
		printf("内存分配失败！"); 
	}else{
		node->data=e;
		node->next=(*S);
		(*S) = node;
	}
}

void PopLiStack(LiStack *S,ElementType *e){
	if(S==NULL){
		printf("栈空，出栈失败！\n");
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
		printf("栈空，获取栈顶元素失败！\n");
	}else{
		*e=S->data;
	}
}

void PrintLiStack(LiStack S){
	LiNode *ptr=S;
	printf("目前栈的元素有：");
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
		printf("此时的栈顶元素：%d\n",myTop);
		PrintLiStack(myLiStack); 
		
		scanf("%d",&element);
 	}

 
	while(!LiStackEmtpy(myLiStack)){
		int myTop; 
		PopLiStack(&myLiStack,&myTop);
		printf("此时的栈顶元素：%d\n",myTop);
		PrintLiStack(myLiStack); 
	}
 
	return 0;
}
