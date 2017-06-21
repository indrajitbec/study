#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#define INC_TO 1000000 // one million...
#define NR_THRAEDS 100

int global_int = 0;

pid_t gettid( void )
{
	return syscall( __NR_gettid );
}

void *thread_routine( void *arg )
{
	int i;
	int proc_num = (int)(long)arg;
	cpu_set_t set;

	CPU_ZERO( &set );
	CPU_SET( proc_num, &set );

	//if (sched_setaffinity( gettid(), sizeof( cpu_set_t ), &set ))
	if (pthread_setaffinity_np( pthread_self(), sizeof( cpu_set_t ), &set ))
	{
		perror( "sched_setaffinity" );
		return NULL;
	}

	for (i = 0; i < INC_TO; i++)
	{
		//global_int++;
		__sync_fetch_and_add( &global_int, 1 );
	}

	return NULL;
}

int main()
{
	int procs = 0;
	int i;
	pthread_t *thrs;

	// Getting number of CPUs
	procs = (int)sysconf( _SC_NPROCESSORS_ONLN );
	if (procs < 0)
	{
		perror( "sysconf" );
		return -1;
	}

	thrs = malloc( sizeof( pthread_t ) * NR_THRAEDS );
	if (thrs == NULL)
	{
		perror( "malloc" );
		return -1;
	}

	printf( "Starting %d threads...\n", NR_THRAEDS );

	for (i = 0; i < NR_THRAEDS; i++)
	{
		if (pthread_create( &thrs[i], NULL, thread_routine,
			(void *)(long)(i%procs) ))
		{
			perror( "pthread_create" );
			procs = i;
			break;
		}
	}

	for (i = 0; i < NR_THRAEDS; i++)
		pthread_join( thrs[i], NULL );

	free( thrs );

	printf( "After doing all the math, global_int value is: %d\n",
		global_int );
	printf( "Expected value is: %d\n", INC_TO * NR_THRAEDS);
    if(global_int == (INC_TO * NR_THRAEDS))
        printf("Perfect !!!\n");
    else
        printf("Wrong !!!\n");

	return 0;
}
