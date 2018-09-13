#include <stdio.h>
#include <stdlib.h>
//#define size 10
int BinSearch(int* A, int n, int t);

int main()
{
	int * A = (int*)calloc(10, sizeof(int));
	int num = BinSearch(A, 10, 20);

	if (num != -1) printf("������ ���� %d��°�� �ֽ��ϴ�.\n", num);

	printf("\n\n");


	A = (int*)calloc(1000, sizeof(int));
	num = BinSearch(A, 1000, 20);

	if (num != -1) printf("������ ���� %d��°�� �ֽ��ϴ�.\n", num);

	printf("\n\n");


	A = (int*)calloc(1000000, sizeof(int));
	num = BinSearch(A, 1000000, 20);

	if (num != -1) printf("������ ���� %d��°�� �ֽ��ϴ�.\n", num);

	free(A);
	return 0;
}

int BinSearch(int* A, int n, int t)
{

	for (int i = 0; i < n; i++) *(A + i) = i * 2;

	int first = 0; int last = n - 1;
	int cnt = 0;
	while (first <= last)
	{
		cnt++;
		int mid = (first + last) / 2;

		if (A[mid] == t)
		{
			printf("%d�� ���� �߰߿� �����߽��ϴ�.\n", cnt);
			return mid;
		}
		else if (A[mid] < t) first = mid + 1;
		else if (A[mid] > t) last = mid - 1;
	}

	printf("%d�� ã������ �߰����� ���߽��ϴ�.\n", cnt);
	return -1;
}