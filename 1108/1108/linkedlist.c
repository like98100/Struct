#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;

typedef struct list {
	Node *head;
	Node *crnt;
}List;

// Initialize members of list
void Initialize(List *list) {
	list->head = NULL;
	list->crnt = NULL;

	printf("Initialize: success!\n");
	return;
}

// integer x를 data 멤버로 갖는 새 노드 생성 
// 노드 생성에 필요한 메모리는 동적 할당 받음
// Return the pointer to memory allocated dynamically, if succeeded
// Return NULL, if failed
Node *CreateNode(int x) {
	Node *temp;

	temp = (Node *)calloc(1, sizeof(Node));
	if (temp == NULL) {
		printf("Memory allocation failed!\n");
	}
	else {
		temp->data = x;
		temp->next = NULL;
	}
	if (temp != NULL)
		printf("Node is created. Data: %d\n", temp->data);
	return temp;
}

// Create node with int x
// Insert the created node in the front
void InsertFront(List *list, int x)
{
	Node *temp;
	temp = CreateNode(x);

	if (temp == NULL) {
		exit(1);
	}
	temp->next = list->head;
	list->head = temp;
	list->crnt = temp;

	//printf("First node data: %d\n", list->head->data);
	return;
}


// Create node with int x
// Insert the created node in the rear
void InsertRear(List *list, int x) {
	Node *newNode, *temp;

	newNode = CreateNode(x);

	// 노드 생성 실패
	if (newNode == NULL) {
		exit(1);
	}

	// List is empty
	if (list->head == NULL) {
		list->head = newNode;
		list->crnt = newNode;
		return;
	}
	// List has at least one node
	// Find the last node
	temp = list->head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	list->crnt = newNode;

	return;
}


// Print all the node data in the list
void PrintList(List *list) {

	Node *temp;
	// list is empty
	if (list->head == NULL) {
		printf("List is empty!\n");
		return;
	}
	temp = list->head;
	printf("head -> ");
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	return;
}

//1. 삭제할 노드의 앞 노드를 찾는다(before)
// rNode = before->next;
// before->next = before->next->next;
//2. 메모리 반환
// free(rNode);		//c++에선 delete;
//2-1. special case
// (1) 삭제할 노드가 첫번째인가 (before NULL 체크)
// (2) 삭제할 노드가 마지막인가(before->next->next를 NULL로)
// (3) List에 노드가 단 하나 존재할 경우

void removeFront()
{

}

void removeRear()
{

}

// Remove the node with int x, if found
void removeAt(List* list, int x)
{
	Node * before = NULL;	// front node of remove node
	Node * rNode = NULL;	// save remove node's address

	// list is empty
	if (list->head == NULL)
	{
		printf("empty\n");	exit(1);
	}

	// there is only one node in the list
	if (list->head->next == NULL)
	{
		if (list->head->data == x)
		{
			rNode = list->head;
			list->head = NULL;
			free(rNode);
		}
		return;
	}

	// there are more than one node in the list
	
	// if remove node is first
	if (list->head->data == x)
	{
		rNode = list->head;
		list->head = list->head->next;
		free(rNode);
	}
	else
	{
		// search node in front of remove node
		before = list->head;
		while (before->next->data != x)
		{
			if (before->next->next != NULL) 	before = before->next;
			else { printf("%d is not exsist in list\n", x); return; }

		}
		rNode = before->next;
		before->next = before->next->next;
		free(rNode);
	}
}

int main(void)
{
	List mylist;
	List yourlist;

	Initialize(&mylist);
	InsertFront(&mylist, 5);
	InsertFront(&mylist, 4);
	InsertFront(&mylist, 3);
	PrintList(&mylist);

	Initialize(&yourlist);
	InsertRear(&yourlist, 5);
	InsertRear(&yourlist, 4);
	InsertRear(&yourlist, 3);
	PrintList(&yourlist);

	removeAt(&yourlist, 5);
	PrintList(&yourlist);

	return 0;
}