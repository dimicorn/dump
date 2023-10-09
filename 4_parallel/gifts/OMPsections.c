#include <stdio.h>
int main() {
#pragma omp parallel
{
	#pragma omp sections
	{
		#pragma omp section
		{
			printf("Section 1, thread %d\n",omp_get_thread_num());		
		}
		#pragma omp section
		{
			printf("Section 2, thread %d\n",omp_get_thread_num());		
		}
		#pragma omp section
		{
			printf("Section 3, thread %d\n",omp_get_thread_num());		
		}
		#pragma omp section
		{
			printf("Section 4, thread %d\n",omp_get_thread_num());		
		}
		#pragma omp section
		{
			printf("Section 5, thread %d\n",omp_get_thread_num());		
		}
		#pragma omp section
		{
			printf("Section 6, thread %d\n",omp_get_thread_num());		
		}
	}
printf("Worked thread %d\n",omp_get_thread_num());	
}
return 0;
}