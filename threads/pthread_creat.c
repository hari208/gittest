#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#if 0
void* threadfun(void *arg)
{
	char *ptr=(char*)arg;
	//ptr=arg;
	//printf("%s",(char*)ptr);
	printf("%s",ptr);
	
	return (void*)strlen(ptr);
   //pthread_exit(NULL);
 	//return 0;
}
	
void main()
{
	pthread_t ti;
	ptr=pthread_create(&ti,NULL,threadfun,"Hello");
	
 //  pthread_exit(NULL);	
//	return 0;
}
//gcc pthread_creat.c -lpthreaad

#endif
////////////
#if 1

static void* threadfun(void *arg)
{
	char *s=(char*)arg;
	printf("hai:%s\n",s);
	return (void*)(s);
}

int main()
{
 	pthread_t ti;
	long int *res;
	int s;
	
	#if 1

	s=pthread_create(&ti,NULL,threadfun,"hello world");
	printf("...s=%d",s);
	if(s!=0)
	{
	 printf("pthread_create: %d\n",s);
	 return 0;
	}

	sleep(5);
	
	printf("message from main()\n");
	
	#endif
	

	#if 1
	
	s=pthread_join(ti,&res);
	printf("s=%d",s);
	if(s!=0)
	{
	 printf("pthread_join error: %d\n",s);
	 return 0;
	}
	printf("pthread returned %s\n",res);
	exit (0);

	#endif









}


#endif	
