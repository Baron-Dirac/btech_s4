#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main()
{
	char filename[50];
	printf("Enter the file: ");
	scanf("%s", filename);
	struct stat s;
	stat(filename, &s);
	printf("MODE: %o\n", s.st_mode);
	printf("SIZE: %ld bytes\n", s.st_size);
	printf("LAST ACCESS TIME: %s", ctime(&s.st_atime));
	printf("LAST MODIFICATION TIME: %s", ctime(&s.st_mtime));
	return 0;
}
/*
OUTPUT
Enter the file: pid.c
MODE: 100664
SIZE: 348 bytes
LAST ACCESS TIME: Thu Jan 30 09:28:31 2025
LAST MODIFICATION TIME: Thu Jan 30 09:26:51 2025
*/
