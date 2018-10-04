#include <stdio.h>
#include <stdlib.h>

#define SIZE 100	//array size
#define TRUE 1	//0 아니면 다 true
#define FALSE 0

typedef struct intQ
{
	int max;	//array-size
	int front;	//q의 맨앞, 초기값=-1
	int rear;	//q의 맨뒤, 초기값=-1
	int *que;	//실제 배열기반 큐의 주소
} IntQ;

//q 구조체 변수 멤버값 초기화
//return -1 if failed to get memory from heap;
//otherwise return 0;
int initializeQ(IntQ* q, int max)
{
	q->front = -1;
	q->rear = -1;
	q->que = (int*)calloc(max, sizeof(int));
	
	//fail to get memory
	if (q->que == NULL) 
	{
		q->max = 0;
		return -1;
	}
	//success
	q->max = max;
	return 0;
}

//check to q is empty
//return true(1) if q is empty;
//otherwise return false(0);
int isemptyQ(IntQ* q)
{
	return (q->rear == -1 && q->front == -1) ? TRUE : FALSE;
}

//check to q is full
//return true(1) if q is full;
//otherwise return false(0);
int isfullQ(IntQ* q)
{
	return (q->rear == q->max - 1 && q->rear != -1) ? TRUE : FALSE;
}

//insert data x into q
//return -1 if failed(i.e., q is full)
//otherwise return 0
int enqueue(IntQ* q, int x)
{
	//check to q is full
	if (isfullQ(&q)) return -1;

	//check to q is empty(front == rear == -1)
	if (isemptyQ(q))
	{
		q->front += 1;
		q->rear += 1;
	}
	else q->rear += 1;

	q->que[q->rear] = x;
	
	return 0;
}

//print all data of q
void printQ(IntQ* q)
{
	int i;

	if (isemptyQ(&q)) return;
	for (i = q->front; i <= q->rear; i++) printf("%d ", q->que[i]);
	printf("\n");
}

// save the first data in q into *temp
//return -1 if q is empty
//otherwise return 0
int dequeue(IntQ* q, int *temp)
{
	if (isemptyQ(q)) return -1;

	*temp = q->que[q->front];
	if (q->front == q->rear)	//data is one
	{
		q->front = -1;
		q->rear = -1;
	}
	else q->front += 1;

	return 0;
}

//return count
//return 0 if q is empty
int countQ(IntQ* q)
{
	int i, cnt = 0;
	if (isemptyQ(q)) return 0;

	for (i = q->front; i <= q->rear; i++) cnt++;
	return cnt;
}

//memory release
void terminate(IntQ* q)
{
	if (q->que != NULL)
	{
		q->max = 0;
		free(q->que);
	}
	printf("terminated.\n");
	return;
}

int main()
{
	IntQ q;
	int* temp;
	if(initializeQ(&q, SIZE) == -1) printf("Fail to get memory from heap\n");
	else
	{
		printf("Succeeded to initialize q :: size -> %d\n", q.max);
		if (isemptyQ(&q)) printf("q is empty\n");
		else printf("q is not empty.\n");

		if (isfullQ(&q)) printf("q is full\n");
		else printf("q is not full.\n");
	}
		
	enqueue(&q, 3);
	enqueue(&q, 5);
	enqueue(&q, 2);
	enqueue(&q, -3);
	printQ(&q);
	if(countQ(&q) != 0) printf("%d개\n", countQ(&q));

	if (dequeue(&q, &temp) != -1) printf("dequeue success :: %d\n", temp);
	else printf("dequeue failed.\n");
	printQ(&q);
	if (countQ(&q) != 0) printf("%d개\n", countQ(&q));
	terminate(&q);
	return 0;
}