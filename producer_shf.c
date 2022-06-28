#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


#define FileName "data.dat"
#define DataString "This is team ACP.\nI am in amantya technologies.\nI am Ajab Singh\n"

void report_and_exit(const char* msg){
	perror(msg);
	exit(-1);
}

int main(){
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();


	int fd;
	if((fd = open (FileName , O_RDWR | O_CREAT, 0666))<0)
		report_and_exit("Open Failed...");
	if(fcntl(fd, F_SETLK , &lock)<0)
		report_and_exit("fcntl Failed to get lock...");
	else{
		write(fd ,DataString, strlen(DataString));
		fprintf(stderr , "Process %d has written tom data file..\n",lock.l_pid);
	}

	lock.l_type = F_UNLCK;
	if(fcntl(fd , F_SETLK, &lock)<0)
		report_and_exit("Explicit unlocking Failed...");
	close(fd);
	return 0;
}


