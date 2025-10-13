#include<stdio.h>
#include<ctype.h> //for isalnum
#include<string.h> //for str(len)

#define MAX 100

char stack[MAX];
int top=-1;

//function to push into stack
void push(char c){
    if (top==MAX-1)
        printf("Stack Overflow\n");
    else{
        top++;
        stack[top]=c;
    }
}

//function to pop from stack
char pop(){
    char val;
    if (top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;
    }
}

//function to peek stack top
char peek(){
    if (top==-1)
        return -1;
    return stack[top];
}

//function to check precedence of operators
char precedence(char c){
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    if (c=='^') return 3;
    return 0;
}

// function to convert infix expression to postfix
int infixToPostfix(char infix[], char postfix[]){
    int i,k=0;
    char c;
    for (i=0;infix[i]!='\0';i++){
        c=infix[i];
        //if operand, add to postfix
        if(isalnum(c)){
            postfix[k]=c;
            k++;
        }

        //if '(' push to stack
        else if (c=='('){
            push(c);
        }

        // if ')' pop until '('
        else if(c==')'){
            while (top!=-1 && peek()!='('){
                postfix[k]=pop();
                k++;
            }
            pop();//remove '('
        }

        //if operator
        else {
            while (top!=-1 && precedence(peek())>=precedence(c)){
                postfix[k]=pop();
                k++;
            }
            push(c);
        }
    }

    //pop all remaining operator
    while(top!=-1){
        postfix[k]=pop();
        k++;
    }
    postfix[k]='\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter a valid paranthesized infix expression:");
    scanf("%s",&infix);
    infixToPostfix(infix,postfix);
    printf("Postfix expression: %s\n",postfix);

    return 0;
}
