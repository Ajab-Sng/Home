#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);

	printf("Shmid : %d\n",shmid);

	char *str = (char *)shmat(shmid,(void*)0,0);
	printf("Data Read From Memory : %s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
