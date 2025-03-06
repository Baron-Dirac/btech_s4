#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
void main()
{
int shmid,p,f;
int *shared_memory;
char buffer[100];
shmid=shmget(1234,1024,0666|IPC_CREAT);
printf("THE KEY OBTAINED :%d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("THE PROCESS ATTACHED AT :%p",shared_memory);
printf("ENTER THE NUMBER TO FIND FACTORIAL : ");
scanf("%d",&f);
*shared_memory=f;
//strcpy(shared_memory,buffer);
printf("The number entered is :%d\n"*shared,_memory);
}
