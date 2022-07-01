#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
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

	msg.type=1;
	printf("Enter message : ");
	gets(msg.str);
	msgsnd(msgid, &msg, sizeof(msg), 0);
	//printf("Send message : \n");
	//puts(msg.str);

	return 0;
}
