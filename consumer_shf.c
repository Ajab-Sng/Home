#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define FileName "data.dat"

void report_and_exit(const char* msg){
	perror(msg);
	exit(-1);
}

int main()
{
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();


	int fd;
	if((fd = open(FileName, O_RDONLY))<0)
		report_and_exit("Open to read failed...");
	fcntl(fd, F_GETLK, &lock);
	if(lock.l_type != F_UNLCK)
		report_and_exit("File is still write locked...");
	lock.l_type = F_RDLCK;
	if(fcntl(fd, F_SETLK, &lock) < 0)
		report_and_exit("Can't get a read-only lock...");
	printf("Read from Process ID : %d\n",lock.l_pid);


	int c;
	while(read(fd, &c, 1) > 0)
		write(STDOUT_FILENO, &c, 1);
	lock.l_type = F_UNLCK;
	if(fcntl(fd, F_SETLK, &lock) < 0)
		report_and_exit("Explicit unlocking failed...");

	close(fd);
	return 0;
}


