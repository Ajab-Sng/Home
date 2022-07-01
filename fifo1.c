#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int main()
{

	if(mkfifo("fifofile",0777) == -1)
	{
		if(errno != EEXIST)
		{
			printf("File could not open.\n");
			return 1;
		}
	}

	printf("Opening...\n");
	int fd = open("fifofile", O_WRONLY);
	if(fd == -1)
	{
		printf("Error : File Opening.\n");
		return 2;
	}

	printf("File Opened..\n");

	int x=5;

	if(write(fd,&x,sizeof(int)) == -1)
	{
		printf("Error : write()\n");
		return 3;
	}
	printf("Written..\n");
	close(fd);

	printf("Closed FIFO 1\n");
	return 0;
}
