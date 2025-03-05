#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("Child\nID: %d\n", getpid());
		printf("Parent ID: %d\n", getppid());
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("Parent\nID: %d\n", getpid());
	}
	return 0;
}
/*
OUTPUT
Child
ID: 6173
Parent ID: 6172
Parent
ID: 6172
*/
