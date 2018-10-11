#include <stdio.h>

void recursive(int num)
{
	//escape condition
	if (num <= 0) return;

	//321
	//printf("Recursive call : %d\n", num);
	//recursive(num-1);

	//123
	recursive(num - 1);
	printf("Recursive call : %d\n", num);

	return;
}

//factorial
int fact(int num)
{
	if (num < 0) return -1;
	else if (num == 0) return 1;
	else return (num*fact(num-1));
}

//return the nth fibonacci sequence value if n >= 1
//otherwise (n < 1) return -1;
int fibonacci(int num)
{
	//error check
	if (num < 1) return -1;
	//escape condition
	else if (num == 1) return 0;
	else if (num == 2) return 1;
	else return fibonacci(num - 1) + fibonacci(num - 2);
}

//hanoi tower
//display how to move n discs in hanoi tower
//num :: number of discs
//a :: start pole, b :: temp pole, c :: goal pole
//(2^(n-1) - 1) + 1 + (2^(n-1) - 1) = 2^n - 1
int cnt = 0;	//movement count
void hanoi_tower(int num, char *pole_a, char *pole_b, char *pole_c)
{
	//escape condition
	if (num == 1)
	{
		printf("Move disc %d from %s to %s.\n", num, pole_a, pole_c);
		cnt++;
	}
	else // n >= 2
	{
		hanoi_tower(num - 1, pole_a, pole_c, pole_b);
		printf("Move disc %d from %s to %s.\n", num, pole_a, pole_c);	cnt++;
		hanoi_tower(num - 1, pole_b, pole_a, pole_c);
	}
	return;
}

//int main()
//{
//	int n = 5;
//	char *a = "start";
//	char *b = "temp";
//	char *c = "goal";
//	//recursive(n);
//
//	//printf("Enter a positive Inteer : "); scanf("%d", &n);
//	//printf("%d! = %d\n", n, fact(n));
//	
//	//for (int i = 1; i <= n; i++) printf("%d ", fibonacci(i));
//	//printf("\n");
//
//	hanoi_tower(n, a, b, c);
//	printf("cnt :: %d\n", cnt);
//	return 0;
//}