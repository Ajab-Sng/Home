#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int g=10;

int main()
{
	int l=5;
	pid_t pid;
	pid=vfork();
	if(pid==0){
		printf("g=%d , l=%d\n",++g,++l);
		printf("Hello , PPid : %d ,Pid : %d\n",getppid(),getpid());
		exit(1);
	}
	else if(pid>0)
	{
		printf("g=%d , l=%d\n",++g,++l);

		printf("Parent Pid : %d\n",getpid()); 
		printf("waiting for child finish.\n");
		wait(NULL);
		printf("Child process finished.\n");
	}
	else
	{
		printf("Child process not created.\n");
	}
	return 0;
}
