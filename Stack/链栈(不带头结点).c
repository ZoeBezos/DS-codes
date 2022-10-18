#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"LiStack.h" 


void InitLiStack(LiStack *S){
	(*S)=NULL;
}

int LiStackEmtpy(LiStack S){
	return S==NULL;
}

int PushLiStack(LiStack *S,char e){
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

int PopLiStack(LiStack *S,char *e){
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

//int GetLiStackTop(LiStack S,char *e){
//	if(S==NULL){
//		printf("ջ�գ���ȡջ��Ԫ��ʧ�ܣ�\n");
//		return 0; 
//	}else{
//		*e=S->data;
//		return 1;
//	}
//}


void PrintLiStack(LiStack S){
	LiNode *ptr=S;
	printf("Ŀǰջ��Ԫ���У�");
	while(ptr!=NULL){
		printf("%c ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
 
	LiStack myLiStack1,myLiStack2;
	
	InitLiStack(&myLiStack1);
	InitLiStack(&myLiStack2);
	
	int FLAG=1;
	
	char str[50];
	
	scanf("%s",str);
	
	int len=strlen(str);
	int mid=len/2-1;
	int i=mid; 
	for(;i>=0;i--){
		PushLiStack(&myLiStack1,str[i]);
		PushLiStack(&myLiStack2,str[len-1-i]);
	}
	i=0;
	for(;i<mid;i++){
		char s1_char,s2_char;
		PopLiStack(&myLiStack1,&s1_char);
		PopLiStack(&myLiStack2,&s2_char);
		if(s1_char!=s2_char){
			FLAG=0;
			break;
		}
	}
	
	if(FLAG==1){
		printf("�ǻ���\n");
	}else{
		printf("���ǻ���\n");
	}


	return 0;
}
