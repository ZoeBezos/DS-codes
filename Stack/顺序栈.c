#include <stdio.h>
#include <stdlib.h>

#include"SqStack.h" 


void InitStack(SqStack *S){
	S->top=-1;
}

int StackEmtpy(SqStack S){
	return S.top==-1;
}

void Push(SqStack *S,ElementType e){
	if(S->top==MaxSize-1){
		printf("Õ»ÒÑÂú£¬ÈëÕ»Ê§°Ü£¡\n"); 
		return 0;
	}else{
		S->data[++S->top]=e;
		return 1;
	}
}

ElementType Pop(SqStack *S){
	if(StackEmtpy(*S)){
		printf("Õ»¿Õ£¬³öÕ»Ê§°Ü£¡\n");
		return 0; 
	}else{
		return S->data[S->top--];
	}
}

ElementType GetTop(SqStack S){
	if(StackEmtpy(S)){
		printf("Õ»¿Õ£¬»ñÈ¡Õ»¶¥ÔªËØÊ§°Ü£¡\n");
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
	printf("Ä¿Ç°Õ»µÄÔªËØÓÐ£º");
	while(index>=0){
		printf("%c ",S.data[index]);
		index--;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	
	SqStack mySqStack;
	
	InitStack(&mySqStack);
	
	ElementType element;
	
	scanf("%c",&element);
	getchar();
	
	while(element!='0'){
		
		Push(&mySqStack,element);
		PrintStack(mySqStack);
		
		scanf("%c",&element);
		getchar();
	}

	
	
	while(!StackEmtpy(mySqStack)){
		Pop(&mySqStack);
		PrintStack(mySqStack);
	}
	
	
	DestroyStack(&mySqStack);
	
	
	return 0;
}
