#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main(){
	int *shared_memory, shmid,n,f=1,i;
	shmid = shmget(2345,sizeof(int),0666);
	shared_memory = shmat(shmid,NULL,0);
	printf("Shared Memory ID : %d\n",shmid);
	n=*shared_memory;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	printf("The factorial of the number : %d",f);
}
