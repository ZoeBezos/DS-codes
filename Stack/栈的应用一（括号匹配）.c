#include <stdio.h>
#include <stdlib.h>

#include"SqStack.h" 


void InitStack(SqStack *S){
	S->top=-1;
}

int StackEmtpy(SqStack S){
	return S.top==-1;
}

void Push(SqStack *S,char e){
	if(S->top==MaxSize-1){
		printf("栈已满，入栈失败！\n"); 
		return 0;
	}else{
		S->data[++S->top]=e;
		return 1;
	}
}

ElementType Pop(SqStack *S){
	if(StackEmtpy(*S)){
		printf("栈空，出栈失败！\n");
		return 0; 
	}else{
		return S->data[S->top--];
	}
}

ElementType GetTop(SqStack S){
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
	int index=0;
	printf("目前栈的元素有：");
	while(index<=S.top){
		printf("%c ",S.data[index]);
		index++;
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	
	SqStack mySqStack;
	
	InitStack(&mySqStack);
	
	printf("输入（、）、[、]、{、}进行括号匹配,（输入0结束程序）\n");
	
	ElementType input;
	
	int WRONG=0;
	

	scanf("%c",&input); 
	getchar();
	Push(&mySqStack,input);
	PrintStack(mySqStack);
	
	scanf("%c",&input); 
	getchar();
	
	
	while(input!='0'||WRONG==0){
		
		
		switch(input){
			case '(':{
				
			}
			case '[':{
				
			}
			case '{':{
				Push(&mySqStack,input);
				break;
			}
			case ')':{
				if(GetTop(mySqStack)=='(') {
					Pop(&mySqStack);
				}else{
					WRONG=1;
				}
				break;				
			}
			case ']':{
				if(GetTop(mySqStack)=='[') {
					Pop(&mySqStack);
				}else{
					WRONG=1;
				}
				break;
			}
			case '}':{
				if(GetTop(mySqStack)=='{') {
					Pop(&mySqStack);
				}else{
					WRONG=1;
				}
				break;
			}
			
			
		}
		
		PrintStack(mySqStack);
		
		scanf("%c",&input); 
		getchar();
	}
	
	if(WRONG==1){
			printf("匹配出错！\n");
		}else{
			printf("匹配成功！\n");
		}
	
	return 0;
}
