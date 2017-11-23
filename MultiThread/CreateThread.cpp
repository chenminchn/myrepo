#include <thread>
#include <apue.h>
#include <myerr.h>

void *thr1_func(void *arg){
	printf("Thread 1 returning.\n");
}

void *thr2_func(void *arg){
	printf("Thread 2 exiting.\n");
	pthread_exit((void *)2);
}
int main(){
    void *tret;
	int err;
	pthread_t tid1,tid2;
	err=pthread_create(&tid1,NULL,thr1_func,NULL);
	if(err!=0)
		err_exit(err,"Can't create thread 1.");
	err=pthread_create(&tid2,NULL,thr2_func,NULL);
	if(err!=0)
		err_exit(err,"Can't create thread 2.");
	err=pthread_join(tid1,&tret);
	if(err!=0)
		err_exit(err,"Cant't join with thread 1.\n");
	printf("Thread 1 exit code %ld\n",(long)tret);
	err=pthread_join(tid2,&tret);
	if(err!=0)
		printf("Can't join with thread 2.\n");
	printf("Thread 2 exit code %ld",(long)tret);
	exit(0);
}
