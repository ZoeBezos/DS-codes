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
		printf("ջ��������ջʧ�ܣ�\n"); 
		return 0;
	}else{
		S->data[++S->top]=e;
		return 1;
	}
}

ElementType Pop(SqStack *S){
	if(StackEmtpy(*S)){
		printf("ջ�գ���ջʧ�ܣ�\n");
		return 0; 
	}else{
		return S->data[S->top--];
	}
}

ElementType GetTop(SqStack S){
	if(StackEmtpy(S)){
		printf("ջ�գ���ȡջ��Ԫ��ʧ�ܣ�\n");
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
	printf("Ŀǰջ��Ԫ���У�");
	while(index<=S.top){
		printf("%c ",S.data[index]);
		index++;
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	
	SqStack mySqStack;
	
	InitStack(&mySqStack);
	
	printf("���루������[��]��{��}��������ƥ��,������0��������\n");
	
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
			printf("ƥ�����\n");
		}else{
			printf("ƥ��ɹ���\n");
		}
	
	return 0;
}
