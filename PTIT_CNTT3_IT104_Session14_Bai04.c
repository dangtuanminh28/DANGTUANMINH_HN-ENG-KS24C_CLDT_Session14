#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
typedef struct Stack
{
    Node* top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}
Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void push(Stack* stack,int value)
{
    Node* newNode=createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
}
int pop(Stack* stack)
{
    if (stack->top==NULL)
    {
        printf("Ngan xep trong\n");
        return -1;
    }
    Node* temp=stack->top;
    int value=temp->data;
    stack->top=temp->next;
    free(temp);
    return value;
}
void printStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL \n");
}
int main(){
    Stack* myStack=createStack();
    push(myStack,5);
    push(myStack,4);
    push(myStack,3);
    push(myStack,2);
    push(myStack,1);

    pop(myStack);

    printStack(myStack);

    return 0;
}