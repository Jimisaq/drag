#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
 int *collection;
 int capacity;
 int size;
}Stack;

//method declarations
Stack *createStack(int capacity);
void deleteStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);

//Main method
int main(void){
    Stack *stack = createStack(5);
    if (stack==NULL)
    {
       printf("Error creating stack..");
       return 1;
    }
    else{
     printf("Stack created successfully\n");
    }
   
    push(stack,10);
    push(stack,5);
    push(stack,11);
    printf("Stack size: %d\n",stack->size);

    printf("\n%d\n",pop(stack));
    printf("\n%d\n",pop(stack));
    printf("Stack size: %d\n",stack->size);

    //deleteStack(stack);
    printf("\n%d\n",peek(stack));
    printf("\n%d\n",peek(stack));

    if(isEmpty(stack)) {
        printf("Stack is empty\n");
    }
    return 0;
}

//Creating a stack
Stack *createStack(int capacity){
    if (capacity<=0)
    {
        return NULL;
    }
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack==NULL)
    {
        return NULL;
    }

    stack->capacity=capacity;
    stack->size=0;
    stack->collection=(int *)malloc(sizeof(int)*stack->capacity);
    if (stack->collection==NULL)
    {
        free(stack);
        return NULL;
    }
    
    return stack;
}

//destroying a stack
void deleteStack(Stack *stack){
    free(stack->collection);
    free(stack);
}

//checking if a stack is full
bool isFull(Stack *stack){
    if(stack->size<=stack->capacity){
        return false;
    }
    return true;
}

//checking if a stack is empty
bool isEmpty(Stack *stack){
    if(stack->size>0){
        return false;
    }
    return true;
}

//pushing an item onto a stack
bool push(Stack *stack, int item){
    
    if(!isFull(stack)){
      stack->collection[stack->size]=item;
      stack->size++;
      return true;
    }
    return false;

}

//popping an item from the stack
int pop(Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty,,pop failed");
        return 0;
        }
    int item=stack->collection[stack->size-1];
    stack->collection[stack->size-1]=0;
    stack->size--;

    return item;  
}

int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("You cant peek from an empty stark");
        return false;
    }

    int item=stack->collection[stack->size-1];

    return item;
}



