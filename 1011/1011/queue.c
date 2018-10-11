#include<stdio.h>
#include<stdlib.h>

#define SIZE 4	// Array size
#define TRUE 1
#define FALSE 0

typedef struct intQ {
	int max;	// Array size
	int front;	// Q의 맨 앞. 초기값은 -1
	int rear;	// Q의 맨 뒤. 초기값은 -1
	int *que;	// 실제 배열기반 큐의 주소값
}IntQ;

// Q 구조체 변수 멤버값들의 초기화
// Return -1 if failed to get memory from heap; 
// Otherwise return 0
int initializeQ(IntQ *q, int max)
{
	q->front = -1;
	q->rear = -1;
	q->que = (int *)calloc(max, sizeof(int));
	
	// 메모리 할당 실패
	if (q->que == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;

	return 0;
}

// 할당받은 메모리 해제
void terminateQ(IntQ *q)
{

	if (q->que != NULL) {
		q->max = 0;
		free(q->que);
	}

	return;
}

// Q가 비었는지 검사
// Return TRUE (1) if Q is empty;
// Otherwise return FALSE (0)
int isQEmpty(IntQ *q)
{
	return (q->rear == -1 && q->front == -1) ? TRUE : FALSE;
}

// Q가 가득 찼는지 검사
// Return TRUE (1) if Q is full;
// Otherwise return FALSE (0)
int isQFull(IntQ *q)
{
	//return (q->rear == q->max - 1 && q->rear != -1) ? TRUE : FALSE;
	return (q->rear + 1) % q->max == q->front ? TRUE : FALSE;
}

// Queue에 데이터 x를 insert
// Return -1 if failed (i.e., Q is full)
// Otherwise return 0
int enqueue(IntQ *q, int x)
{
	// Q가 가득 찼는지 검사
	if (isQFull(q)) {
		return -1;
	}

	// Q가 비어있을 경우 (즉, front == rear == -1)
	if (isQEmpty(q)) {
		q->front += 1;
		q->rear += 1;
		q->que[q->rear] = x;
	}
	// Q에 원소가 하나 이상 있을 경우
	else {
		//q->rear += 1;
		//q->que[q->rear] = x;
		q->rear = (q->rear + 1) % q->max;	// if rear == max-1 -> set to 0
		q->que[q->rear] = x;
	}

	return 0;
}

// Q에서 맨 앞 데이터 값을 *temp 에 저장
// 만약 Q가 비어있으면 -1을 리턴;
// 그렇지 않으면 0을 리턴
int dequeue(IntQ *q, int *temp)
{
	// 에러 검사
	if (isQEmpty(q)) {
		printf("Q is empty!\n");
		return -1;
	}
	
	*temp = q->que[q->front];

	// Q가 비어 있지 않고, 데이터 개수가 1개인 경우 초기화 필요
	if (q->front == q->rear) {	// 데이터 개수가 1
		q->front = -1;
		q->rear = -1;
	}
	else
		/*q->front += 1;*/
		q->front = (q->front + 1) % q->max; // if rear == max-1 -> set to 0

	return 0;
}


// Q의 데이터를 모두 출력
void printQ(IntQ *q)
{
	int i, start, end;
	start = q->front;
	end = q->rear;

	if (isQEmpty(q))
		return;
	
	for (i = start; i <= end; i++)
		printf("%d\n", q->que[i]);

	//if(q->rear >= q->front)
	//else

	return;
}

// Q 내의 데이터 개수를 return
// Q가 비었으면 0을 return
int countQ(IntQ *q)
{
	int i, cnt=0;

	if (!isQEmpty(q)) {
		//for (i = q->front; i <= q->rear; i++)
		//	cnt++;
		if(q->rear >= q->front) cnt = q->rear - q->front + 1;
		else cnt = q->max - (q->front - q->rear - 1);
	}
	return cnt;

}



int main(void)
{
	IntQ myq;
	int temp; 

	initializeQ(&myq, SIZE);

	if (myq.que != NULL && myq.max != 0)
	{
		printf("Q 초기화 성공!\n");
		printf("Q size: %d\n", myq.max);
		if (isQEmpty(&myq))
			printf("Q is empty\n");
		else
			printf("Q is not empty\n");

		if (isQFull(&myq))
			printf("Q is full\n");
		else
			printf("Q is not full\n");
	}
	else
	{
		printf("Q 초기화 실패!\n");
		printf("Q size: %d\n", myq.max);
	}

	enqueue(&myq, 3);
	enqueue(&myq, 5);
	enqueue(&myq, 2);
	enqueue(&myq, -3);
	printQ(&myq);
	printf("No of data in Q: %d\n", countQ(&myq));

	printf("front value :: %d, rear value :: %d\n", myq.front, myq.rear);

	if (dequeue(&myq, &temp) != -1)
		printf("dequeue success!: %d\n", temp);
	if (dequeue(&myq, &temp) != -1)
		printf("dequeue success!: %d\n", temp);

	printf("front value :: %d, rear value :: %d\n", myq.front, myq.rear);

	if (dequeue(&myq, &temp) != -1)
		printf("dequeue success!: %d\n", temp);

	printf("front value :: %d, rear value :: %d\n", myq.front, myq.rear);

	if (dequeue(&myq, &temp) != -1)
		printf("dequeue success!: %d\n", temp);
	printf("No of data in Q: %d\n", countQ(&myq));

	if (dequeue(&myq, &temp) != -1)
		printf("dequeue success!: %d\n", temp);

	printf("front value :: %d, rear value :: %d\n", myq.front, myq.rear);
	printf("No of data in Q: %d\n", countQ(&myq));

	terminateQ(&myq);
	printf("front value :: %d, rear value :: %d\n", myq.front, myq.rear);
	return 0;
}