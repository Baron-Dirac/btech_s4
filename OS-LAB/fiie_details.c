#include<stdio.h>
#include<dirent.h>
int main()
{
	struct dirent *d;
	DIR *dir = opendir(".");
	while((d = readdir(dir)) != NULL)
	{
		printf("Name: %s, ", d->d_name);
		if(d -> d_type == 8)
		{
			printf("Type: File\n");
		}
		else if(d -> d_type == 4)
		{
			printf("Type: Directory\n");
		}
		else
		{
			printf("Type: Other type\n");
		}
		printf("\n");
	}
	closedir(dir);
	return 0;
}
/*
OUTPUT
Name: .., Type: Directory
Name: folder, Type: Directory
Name: ch, Type: File
Name: filedetails.c, Type: File
Name: fileinfo.c, Type: File
Name: filedetails_a.c, Type: File
Name: checkdir.c, Type: File
Name: oddeven.c, Type: File
Name: all files, Type: Directory
Name: ., Type: Directory
Name: childparent.c, Type: File
Name: a.out, Type: File
Name: pid.c, Type: File
*/
