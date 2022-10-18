#include <stdio.h>
#include <stdlib.h>

#include"LiStack.h" 


int InitLiStack(LiStack *S){
	(*S)=(LiNode*)malloc(sizeof(LiNode));
	if((*S)==NULL){
		printf("内存不足，头结点创建失败！"); 
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
		printf("内存分配失败！"); 
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
		printf("栈空，出栈失败！\n");
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
		printf("栈空，获取栈顶元素失败！\n");
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
		printf("此时的栈顶元素：%d\n",myTop);
		
		scanf("%d",&element);
 	}

	printf("-----------------------------\n");
 
	while(!LiStackEmtpy(myLiStack)){
		int myTop; 
		PopLiStack(&myLiStack,&myTop);
		printf("此时的栈顶元素：%d\n",myTop);
	}
 
	return 0;
}
