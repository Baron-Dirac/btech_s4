#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("File Name: %s\n", argv[1]);
		printf("Child Process\n");
		execlp("cat", "cat", argv[1], NULL);
		perror("error");
	}
	else
	{
		wait(NULL);
		printf("Parent Process");
	}
	return 0;
}
/*
OUTPUT
File Name: test.txt
Child Process
This is a test file.
Parent Process
*/
