#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct message{
        long type;
        char str[20];
}msg;
int main()
{
	key_t key;
	int msgid;
	key = ftok("queuefile",66);

	msgid = msgget(key, 0666 | IPC_CREAT);

	msgrcv(msgid,&msg, sizeof(msg), 1, 0);
	printf("Received message : \n");
	puts(msg.str);
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
