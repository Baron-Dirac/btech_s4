#include <stdio.h>
//#include <stlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t mutex, full, empty;
int gitem, item = 0, buf[5];
int put = 0, get = 0, pro[30], con[30];

void *producer(void *arg){
	do{
		sem_wait(&empty);
		sem_wait(&mutex);
		buf[put%5] = item;
		item++;
		printf("Producer %d produces %d item buffered[%d] : %d\n", (*(int *)arg), buf[put%5], put%5, item);
		put++;
		sem_post(&mutex);
		sem_post(&full);
		sleep(2);
		}while(1);
}

void *consumer(void *arg){
	do{
		sem_wait(&full);
		sem_wait(&mutex);
		gitem = buf[get%5];
		printf("Consumer %d consumes %d item buffered[%d] : %d\n", (*(int *)arg), buf[get%5], get%5, gitem);
		get++;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(2);
		}while(1);
}
                                               
int main(){
	int p, c, i, j;
	pthread_t a[30], b[30];
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, 5);
	sem_init(&full, 0, 0);
	printf("Enter the number of producers: ");
	scanf("%d", &p);
	printf("Enter the number of consumers: ");
	scanf("%d", &c);
	for(i=0;i<p;i++){
		pro[i] = i;
		pthread_create(&a[i],NULL,producer,&pro[i]);
	}
	for(j=0;j<c;j++){
		con[j] = j;
		pthread_create(&a[j],NULL,consumer,&con[j]);
	}
	for(i=0;i<p;i++){
		pthread_join(a[i],NULL);
	}
	for(j=0;j<c;j++){
		pthread_join(b[j],NULL);
	}
	                                                                                                                  
	return 0;                 
}
