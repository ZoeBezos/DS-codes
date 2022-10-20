#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"SqStack.h" 


void InitStack(SqStack *S){
	S->top=-1;
}

int StackEmtpy(SqStack S){
	return S.top==-1;
}

void Push(SqStack *S,ElementType e){
	if(S->top==MaxSize-1){
		printf("栈已满，入栈失败！\n"); 
	}else{
		S->data[++S->top]=e;
	}
}

ElementType Pop(SqStack *S){
	if(StackEmtpy(*S)){
		printf("栈空，出栈失败！\n");
	}else{
		return S->data[S->top--];
	}
}

ElementType GetTop(SqStack S){
	if(StackEmtpy(S)){
		printf("栈空，获取栈顶元素失败！\n");
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
	
	printf("输入一个中缀表达式：\n");
	
	ElementType input[30],output[30]="", tmp_char[2]="";
	tmp_char[1]='\0';
	scanf("%s",input); 
	
	int i=0;
	
	while(input[i]!='\0'){
		
		if(input[i]>='0'&&input[i]<='9'){
			tmp_char[0]=input[i];
			strcat(output,tmp_char);
		}else{
			switch(input[i]){
				case '+':{
					if(StackEmtpy(mySqStack)){
						
					}else{
						while(GetTop(mySqStack)=='*'||GetTop(mySqStack)=='/'||GetTop(mySqStack)=='+'||GetTop(mySqStack)=='-'){
							tmp_char[0]=Pop(&mySqStack);
							strcat(output,tmp_char);
						}
					}
					Push(&mySqStack,input[i]);
					break;
				}
				case '-':{
					if(StackEmtpy(mySqStack)){
						
					}else{
						while(GetTop(mySqStack)=='*'||GetTop(mySqStack)=='/'||GetTop(mySqStack)=='+'||GetTop(mySqStack)=='-'){
							tmp_char[0]=Pop(&mySqStack);
							strcat(output,tmp_char);
						}
					}
					Push(&mySqStack,input[i]);
					break;
				}
				case '*':{
					if(StackEmtpy(mySqStack)){
						
					}else{
						while(GetTop(mySqStack)=='*'||GetTop(mySqStack)=='/'){
							tmp_char[0]=Pop(&mySqStack);
							strcat(output,tmp_char);
						}
					}
					Push(&mySqStack,input[i]);
					break;
				}
				case '/':{
					if(StackEmtpy(mySqStack)){
						
					}else{
						while(GetTop(mySqStack)=='*'||GetTop(mySqStack)=='/'){
							tmp_char[0]=Pop(&mySqStack);
							strcat(output,tmp_char);
						}
					}
					Push(&mySqStack,input[i]);
					break;
				}
				case '(':{//直接入栈 
					Push(&mySqStack,input[i]);
					break;
				}
				case ')':{//排出栈直到遇到'('
					int index=mySqStack.top;
					while(GetTop(mySqStack)!='('){
						tmp_char[0]=Pop(&mySqStack);
						strcat(output,tmp_char);
						index--;
					}
					Pop(&mySqStack);
					break;
				}
			}
			PrintStack(mySqStack);
			
		}
		printf("此时后缀表达式：%s\n",output);

		
		i++;
	}
	
	if(!StackEmtpy(mySqStack)){
		int index=mySqStack.top;
		while(index>=0){
			tmp_char[0]=Pop(&mySqStack);
			strcat(output,tmp_char);
			index--;
			PrintStack(mySqStack);
			printf("此时后缀表达式：%s\n",output);
		}
	}
	
	
	return 0;
}
