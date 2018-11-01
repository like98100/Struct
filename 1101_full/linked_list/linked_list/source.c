//0. List
//1. Node(newNode)
//2. head = &newNode
//3. ++ Node
//3-1. InsertFront : newHead = &1stNode
//3-2. InsertRear : 1stHead = &newNode

// InsertRear -> lastNode.next = &newNode
// InsertFront -> newNode.next = head, head = newNode

//4.PrintList

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* nextField;

};
typedef struct node Node;

typedef struct list
{
    Node *head;
    Node *crnt;
} List;

// Initialize members of list
void initialize(List *list)
{
    list->head = NULL;
    list->crnt = NULL;
    return;
}

// integer x를 data member로 갖는 새 노드 생성
// 노드 생성에 필요한 메모리는 동적 할당 받음
// Return the pointer to memory allocated dynamically(동적할당), if succeeded
// Return NULL, if failed
Node *createNode(int x)
{
    Node *temp;

    temp = (Node*)calloc(1, sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n"); //return NULL;
    }
    else
    {
        temp->data = x;
        temp->nextField = NULL;
        printf("Memory allocation succeeded.\n");
    }

    if(temp != NULL) printf("Node is created. Data : %d\n", temp->data);
    return temp;
}

// Create node with int x
// Insert the created node in the front
void insertFront(List *list, int x)
{
    Node *temp;
    temp = createNode(x);
    if(temp == NULL) exit(1);

    temp->nextField = list->head;
    list->head = temp;
    list->crnt = temp;

    printf("(First Node Data)Head pointer is now pointed to : %d\n", list->head->data);

    return;
}

// Print all the node data in the list
void printList(List *list)
{
    Node *temp;
    // list is empty
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = list->head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->nextField;
    }
    printf("NULL\n");    return;
}

// Create node with int x
// Insert the created node in the rear
void insertRear(List *list, int x)
{
    Node *newNode, *temp;
    newNode = createNode(x);
    
    // fail to create node
    if(newNode == NULL) exit(1);

    // list is empty
    if (list->head == NULL)
    {
        list->head = newNode;
        list->crnt = newNode;
        return;
    }

    // list has at least one node
    // find the last node
    temp = list->head;
    while (temp->nextField != NULL)
    {
        temp = temp->nextField;
    }
    temp->nextField = newNode;
    list->crnt = newNode;

    return;
}

int main()
{
    List myList;
    List yourList;
    initialize(&myList);
    initialize(&yourList);

    createNode(5);
    insertFront(&myList, 3);
    insertFront(&myList, 4);
    insertFront(&myList, 5);

    printList(&myList);

    insertRear(&yourList, 6);
    insertRear(&yourList, 7);
    insertRear(&yourList, 8);

    printList(&yourList);

    return 0;
}