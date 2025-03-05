#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
	struct stat s;
	struct dirent *d;
	DIR *dir = opendir(".");
	while((d = readdir(dir)) != NULL)
	{
		if(d->d_name[0] == 'a')
		{
			stat(d->d_name, &s);
			printf("Name: %s\n", d->d_name);
			if(d->d_type == 8)
			{
				printf("Type: File");
			}
			else if(d->d_type == 4)
			{
				printf("Type: Directory");
			}
			else
			{
				printf("Type: Other type");
			}
			printf("\nMode %o\n", s.st_mode);
			printf("Size: %ld bytes\n\n", s.st_size);
		}
	}
	closedir(dir);
	return 0;
}
/*
OUTPUT
Name: all files
Type: Directory
Mode 40775
Size: 4096 bytes
Name: a.out
Type: File
Mode 100775
Size: 16152 bytes
*/
