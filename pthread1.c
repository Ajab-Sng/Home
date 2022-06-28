#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *func(void *arg)
{
	pthread_detach(pthread_self());
	
	sleep(2);
	char *ch=(char *)malloc(20);
	strcpy(ch,arg); 

	printf("Inside Thread -%s\n",ch);
	free(ch);
	pthread_exit(NULL);
}

int main()
{
	pthread_t ptid;
	long int p;
	if(!(pthread_create(&ptid,NULL,func,"Thread Agrument")))
		printf("Thread created successfully.\n");
	else
		printf("Error : pthread_create()\n");
	
	printf("Thread ID : %ld\n",ptid);
	
	printf("pthread_self() : %lu\n",pthread_self());

	if(pthread_equal(ptid,pthread_self()))
		printf("Threads are equal.\n");
	else
		printf("Threads are not equal.\n");
	

	pthread_join(ptid,NULL);
	printf("Thread Exited.\n");
	pthread_exit(NULL);
	return 0;

}
