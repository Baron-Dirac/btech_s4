#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		for(int i = 1; i<=10; i++)
		{
			if(i % 2 != 0)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else
	{
		wait(NULL);
		for(int i = 1; i<=10; i++)
		{
			if(i % 2 == 0)
			{
				printf("%d ", i);
			}
		}
	}
	return 0;
}
/*
OUTPUT
1 3 5 7 9 
2 4 6 8 10
*/
