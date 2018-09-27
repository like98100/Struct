#include <stdio.h>
#include <stdlib.h>
#define SIZE 100	// Stack array size
#define TRUE 1
#define FALSE 0

typedef struct intStack
{
	int max;	// stack array size
	int top;	// lastly inserted data index in array
	int* stk;	// address of array stack in heap memory
} IntStack;

// Initialize each member in IntStack variable
// Get memory from Heap
// Return 0 if succeeded; -1 if failed
int initialize(IntStack *s, int max)
{
	s->stk = (int*)calloc(max, sizeof(int));
	s->top = -1;
	// Check if memory allocation is succeeded
	if (s->stk == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

// Push int data x into s->stk
// Return 0 if succeeded; -1 if failed(i.e., Stack is full)
int push(IntStack *s, int x)
{

	//Check if stack is full
	if (isfull(s)) return -1;

	s->top += 1;			// Increase the index number to insert
	s->stk[s->top] = x;	

	return 0;
}

// If stack is full, return TRUE(i.e., 1); otherwise return FALSE(-1)
int isfull(IntStack *s)
{
	//if(s->top + 1 == s->max)
	return s->top + 1 == s->max ? TRUE : FALSE;
}

// If stack is empty, return TRUE(i.e., 1); otherwise return FALSE(-1)
int isempty(IntStack *s)
{
	//if(s->top + 1 == s->max)
	return s->top == -1 ? TRUE : FALSE;
}

// Print data in stack
void printStack(IntStack *s)
{
	int i;
	if (isempty(s)) printf("No data\n");
	
	for (i = 0; i <= s->top; i++)
	{
		printf("%d\n", s->stk[i]);
	}

	return;
}

// Pop int data from stack and insert it into &x
// Return 0 if succeeded; -1 if failed(i.e., Stack is empty)
int pop(IntStack *s, int *x)
{

	//Check if stack is empty
	if (isempty(s)) return -1;

	*x = s->stk[s->top];
	s->top -= 1;			// Decrease the index number to delete

	return 0;
}

// Peek int data from stack and insert it into &x
// Return 0 if succeeded; -1 if failed(i.e., Stack is empty)
int peek(IntStack *s, int *x)
{

	//Check if stack is empty
	if (isempty(s)) return -1;

	*x = s->stk[s->top];

	return 0;
}

// Return allocated memory to OS
// Return 0 if succeeded; -1 if failed
int terminate(IntStack* s)
{
	if (s->stk == NULL) return -1;

	free(s->stk);
	s->top = -1;
	s->max = 0;
	return 0;
}

// Count the number of data int stack
int count(IntStack *s)
{
	if (isempty(s)) return 0;

	return s->top + 1;
}

int main()
{
	IntStack mystack;
	int temp;		// To store int value for pop()

	initialize(&mystack, SIZE);
	if(mystack.stk != NULL) printf("Array-based stack is succeeded :: size -> %d\n", mystack.max);
	else printf("Array-based stack is failed :: size -> %d\n", mystack.max);

	if (isempty(&mystack)) printf("Stack is empty.\n");
	else printf("Stack is not empty.\n");

	if (isfull(&mystack)) printf("Stack is full.\n");
	else printf("Stack is not full.\n");

	push(&mystack, 1);
	push(&mystack, 3);
	push(&mystack, 5);
	push(&mystack, 7);

	printStack(&mystack);

	printf("count :: %d\n", count(&mystack));


	if(pop(&mystack, &temp) != -1)	printf("Data %d is popped. \n", temp);

	if (pop(&mystack, &temp) != -1)	printf("Data %d is popped. \n", temp);

	printStack(&mystack);
	printf("count :: %d\n", count(&mystack));

	if (peek(&mystack, &temp) != -1)	printf("Data %d is peeked. \n", temp);

	printStack(&mystack);
	printf("count :: %d\n", count(&mystack));

	if(terminate(&mystack) != -1) printf("Data is terminated.\n");
	printStack(&mystack);
	printf("count :: %d\n", count(&mystack));
	return 0;
}