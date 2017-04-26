#include <stdio.h>
#include <pthread.h>
#include <signal.h>

#if 0

int glob=0;

 void* threadfun1(void *arg)
{
	int loop,loc,i;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
	 loc=glob;
	 loc++;
	 glob=loc;
	}
	//return (void*)glob;
}
 void*  threadfun2(void *arg)
{
	int loop,loc,i;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
	 loc=glob;
	 loc++;
	 glob=loc;
	}
	//return (void*)glob;
}

void main()
{
	pthread_t t1,t2;
	int loop=100000,res;
	pthread_create(&t1,NULL,threadfun1,&loop);
	pthread_create(&t2,NULL,threadfun2,&loop);
	pthread_join(t1,&res);
	pthread_join(t2,&res);
	printf("%d",glob);
}


#endif

#if 1
//#include <pthread.h>

 int glob = 0;
pthread_mutex_t mtx;
 void* threadFunc1(void *arg)
{
	int loops = *((int *)arg);
	int loc, j;
	for(j=0;j<loops;j++)
	{	
	  pthread_mutex_lock(&mtx);
	  pthread_mutex_trylock(&mtx);	
		loc = glob;
		loc++;
		glob = loc;
	  pthread_mutex_unlock(&mtx);	
	}
	//return NULL; 
	//return (void*)strlen(s);
}

void* threadFunc2(void *arg)
{
	int loops = *((int *)arg);
	int loc, j;
	for(j=0;j<loops;j++)
	{	
	  pthread_mutex_lock(&mtx);
	  pthread_mutex_trylock(&mtx);
		loc = glob;
		loc++;
		glob = loc;
	  pthread_mutex_unlock(&mtx);
	}
	//return NULL; 
	//return (void*)strlen(s);
}

//int main(int argc, char *argv[])
int main()
{
	pthread_t t1, t2;
	long int loops, res,s;
	//printf("enter loooop value:");
	//scanf("%ld",&loops);
	//loops = (argc > 1) ? (getInt(argv[1],GN_GT_0,"num-loops") : 10000000;
	loops = 150000;
	 pthread_create(&t1, NULL, threadFunc1, &loops);
/*	if(s != 0)
	{
		printf("pthread_create 1 ERROR\n");
		return 0;
	} */
	pthread_create(&t2, NULL, threadFunc2, &loops);
/*	if(s != 0)
	{
		printf("pthread_create 2 ERROR\n");
		return 0;
	} */
	
	pthread_join(t1,&res);
/*	if(s!=0)
	{
		printf("pthread_join 1 ERROR\n");
		return 0;
	} */
	pthread_join(t2,&res);
/*	if(s!=0)
	{
		printf("pthread_join 2 ERROR\n");
		return 0;
	} */
	printf("glob = %d\n", glob);
	return 0;
}
	
#endif
