#include<stdio.h> 
#include<stdlib.h> 
#include<pthread.h> 

void* func(void* arg) 
{ 

	pthread_detach(pthread_self()); 

	printf("This line is Inside the thread\n"); 
	pthread_exit(NULL); 
} 

void func2() 
{ 
	pthread_t ptid; 
	pthread_create(&ptid, NULL, &func, NULL); 
	printf("This line printed before thread terminates\n"); 


	if(pthread_equal(ptid, pthread_self()))
		printf("The threads are equal\n"); 
	else
		printf("The threads are not equal\n"); 

	pthread_join(ptid, NULL); 

	printf("This line will be printed after thread ends\n"); 

	pthread_exit(NULL); 
} 
 
int main() 
{ 
	func2(); 
	return 0; 
} 

