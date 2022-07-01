#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char *args[] = {"./EXEC1",NULL};
	execvp(args[0],args);
	
	printf("End of execvp.\n");

	return 0;
}
