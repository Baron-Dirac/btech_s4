#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main(){
	int *shared_memory, shmid;
	shmid = shmget(2345,sizeof(int),0666 | IPC_CREAT);
	shared_memory = shmat(shmid,NULL,0);
	printf("Shared Memory ID : %d\n",shmid);
	printf("Enter the value to find the factorial : ");
	scanf("%d",shared_memory);
	printf("The value Entered to the shared memory is %d\n",*shared_memory);
	return 0;
}
