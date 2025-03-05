#include<stdio.h>
#include<sys/stat.h>
int main()
{
	char filename[50];
	printf("Enter the file: ");
	scanf("%s", filename);
	struct stat s;
	if(stat(filename, &s) == 0)
	{
		if(S_ISDIR(s.st_mode))
		{
			printf("%s is a directory.", filename);
		}
		else if (S_ISREG(s.st_mode))
		{
			printf("%s is a regular file.", filename);
		}
	}
	else
	{
		perror("File not found.");
	}
	return 0;
}
/*
OUTPUT
Enter the file: pid.c
pid.c is a regular file.
Enter the file: folder
folder is a directory.
*/
