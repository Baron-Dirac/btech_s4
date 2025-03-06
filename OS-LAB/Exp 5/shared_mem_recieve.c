/*PROGRAM TO IMPLEMENT SHARED MEMORY:RECEIVER*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
void main()
{
int shmid,p,f=1;
int *shared_memory;
char buffer[100];
shmid=shmget(1234,1024,0666);
printf("THE KEY OBTAINED :%d\n\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("THE PROCESS ATTACHED AT :%p\n",shared_memory);
for(int i=1;i<=*shared_memory;i++)
{
f=f*i;
}
printf("The factorial is:%d\n",f);
}
