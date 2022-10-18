#include <stdio.h>
#include <stdlib.h>

#include"SqStack.h" 


void InitStack(SqStack *S){
	S->top=-1;
}

int StackEmtpy(SqStack S){
	return S.top==-1;
}

int Push(SqStack *S,char e){
	if(S->top==MaxSize-1){
		printf("栈已满，入栈失败！\n"); 
		return 0;
	}else{
		S->data[++S->top]=e;
		return 1;
	}
}

char Pop(SqStack *S){
	if(StackEmtpy(*S)){
		printf("栈空，出栈失败！\n");
		return 0; 
	}else{
		return S->data[S->top--];
	}
}

char GetTop(SqStack S){
	if(StackEmtpy(S)){
		printf("栈空，获取栈顶元素失败！\n");
		return 0; 
	}else{
		return S.data[S.top];
	}
}

void DestroyStack(SqStack *S){
	S->top=-1;
}

void PrintStack(SqStack S){
	int index=S.top;
	printf("目前栈的元素有：");
	while(index>=0){
		printf("%c ",S.data[index]);
		index--;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	SqStack mySqStack;
	
	InitStack(&mySqStack);
	
	char element;
	
	scanf("%c",&element);
	getchar();
	
	while(element!='0'){
		
		Push(&mySqStack,element);
//		printf("此时的栈顶元素：%c\n",GetTop(mySqStack));
		PrintStack(mySqStack);
		
		scanf("%c",&element);
		getchar();
	}

	
	printf("-----------------------------\n");
	
	while(!StackEmtpy(mySqStack)){
		Pop(&mySqStack);
//		printf("此时的栈顶元素：%c\n",Pop(&mySqStack));
		PrintStack(mySqStack);
	}
	
	printf("-----------------------------\n");
	
	DestroyStack(&mySqStack);
	printf("栈大小：%10d\n",mySqStack.top+1);
	
	
	return 0;
}
