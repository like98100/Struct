#include <stdio.h>
#include <stdlib.h>
//#define size 10
int BinSearch(int* A, int n, int t);

int main()
{
	int * A = (int*)calloc(10, sizeof(int));
	int num = BinSearch(A, 10, 20);

	if (num != -1) printf("정해진 값은 %d번째에 있습니다.\n", num);

	printf("\n\n");


	A = (int*)calloc(1000, sizeof(int));
	num = BinSearch(A, 1000, 20);

	if (num != -1) printf("정해진 값은 %d번째에 있습니다.\n", num);

	printf("\n\n");


	A = (int*)calloc(1000000, sizeof(int));
	num = BinSearch(A, 1000000, 20);

	if (num != -1) printf("정해진 값은 %d번째에 있습니다.\n", num);

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
			printf("%d번 만에 발견에 성공했습니다.\n", cnt);
			return mid;
		}
		else if (A[mid] < t) first = mid + 1;
		else if (A[mid] > t) last = mid - 1;
	}

	printf("%d번 찾았으나 발견하지 못했습니다.\n", cnt);
	return -1;
}