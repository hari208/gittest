#include <stdio.h>
void main()
{
	int pid;
	printf("enter the PID:");
	scanf("%d",&pid);
	kill(pid,9);
}
