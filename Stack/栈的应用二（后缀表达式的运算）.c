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
		printf("%d ",S.data[index]);
		index++;
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	
	SqStack mySqStack;
	
	InitStack(&mySqStack);
	
	printf("����һ����׺���ʽ\n");
	
	char input[30];
	
	int tmp_res; 

	scanf("%s",input); 
	int i=0;
	
	while(input[i]!='\0'){
		
		if(input[i]>='0'&&input[i]<='9'){
			tmp_res=input[i]-'0';
		}else{
			int number2=Pop(&mySqStack),number1=Pop(&mySqStack);
			switch(input[i]){
				case '+':{
					tmp_res=number1+number2;
					break;
				}
				case '-':{
					tmp_res=number1-number2;
					break;
				}
				case '*':{
					tmp_res=number1*number2;
					break;
				}
				case '/':{
					tmp_res=number1/number2;
					break;
				}
			}
		}
		
		Push(&mySqStack,tmp_res);
	
		PrintStack(mySqStack);
		
		i++;
	}
	
	
	return 0;
}
