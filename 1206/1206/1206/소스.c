////BST FindMin/Max/Height
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef char element;
//typedef struct bstNode
//{
//	element data;
//	struct bstNode *left;
//	struct bstNode *right;
//} BSTNode;
//
//typedef BSTNode Node;
//
//Node *createNode(element x)
//{
//	Node *newNode = NULL;
//
//	newNode = (Node *)calloc(1, sizeof(Node));
//	if (newNode != NULL)
//	{
//		newNode->data = x;
//		newNode->left = NULL;
//		newNode->right = NULL;
//	}
//
//	return newNode;
//}
//
//// Insert x into binary search tree with root address
//Node *Insert(Node *root, element x)
//{
//	if (root == NULL)
//	{
//		root = createNode(x);
//	}
//	else if (x <= root->data)
//	{
//		root->left = Insert(root->left, x);
//	}
//	else if (x > root->data)
//	{
//		root->right = Insert(root->right, x);
//	}
//	else
//	{
//		printf("Something is wrong...\n");
//		exit(1);
//	}
//	return root;
//}
//
//// If x is founde, return 1(True)
//// Otherwise, return 0(False)
//int searchNode(Node *root, element x)
//{
//	//empty tree
//	if (root == NULL) return 0;
//
//	if (root->data == x) return 1;
//	else if (root->data >= x) return searchNode(root->left, x);
//	else if (root->data <= x) return searchNode(root->right, x);
//}
//
//// Print all the nodes in tree in infix order
//// Infix order :: left subtree -> root -> right subtree
//// That is, print in sorted order in BST
//void printInfix(Node *root)
//{
//	if (root == NULL) return;
//	else
//	{
//		printInfix(root->left);
//		printf(" %c ", root->data);
//		printInfix(root->right);
//		return;
//	}
//}
//
//// Prefix order :: root -> left subtree -> right subtree
//// That is, print first the root node in BST
//void printPrefix(Node *root)
//{
//	if (root == NULL) return;
//	else
//	{
//		printf(" %c ", root->data);
//		printPrefix(root->left);
//		printPrefix(root->right);
//		return;
//	}
//}
//
//
//// Postfix order ::  left subtree -> right subtree -> root
//// That is, print last the root node in BST
//void printPostfix(Node *root)
//{
//	if (root == NULL) return;
//	else
//	{
//		printPostfix(root->left);
//		printPostfix(root->right);
//		printf(" %c ", root->data);
//		return;
//	}
//}
//
//int max_int(int a, int b)
//{
//	return (a >= b) ? a : b;
//}
//
//
//
////Find the height of a tree recursively
//int findHeight(Node* root)
//{
//	if (root == NULL) return -1;
//	else return 1 + max_int(findHeight(root->left), findHeight(root->right));
//}
//
////Find the min value of a bs tree recursively
//int findMin(Node* root)
//{
//	if (root == NULL)
//	{
//		printf("tree is empty\n"); exit(1);
//	}
//	if (root->left == NULL) return root->data;
//	else return findMin(root->left);
//}
//
////Find the max value of a bs tree recursively
//int findMax(Node* root)
//{
//	if (root == NULL)
//	{
//		printf("tree is empty\n"); exit(1);
//	}
//	if (root->right == NULL) return root->data;
//	else return findMin(root->right);
//}
//
//void main()
//{
//	Node *myRoot = NULL;
//
//	myRoot = Insert(myRoot, 'F');
//	Insert(myRoot, 'A');
//	Insert(myRoot, 'C');
//	Insert(myRoot, 'A');
//	Insert(myRoot, 'D');
//	Insert(myRoot, 'G');
//	Insert(myRoot, 'Z');
//
//	printf("Infix : ");
//	printInfix(myRoot);	printf("\n");
//
//	printf("Prefix : ");
//	printPrefix(myRoot);	printf("\n");
//
//	printf("Postfix : ");
//	printPostfix(myRoot);	printf("\n");
//
//	printf("%d", searchNode(myRoot, 'Z'));
//
//	printf("\n");
//
//	printf("height : %d\n", findHeight(myRoot));
//
//	printf("min : %c\n", findMin(myRoot));
//	printf("max : %c\n", findMax(myRoot));
//}