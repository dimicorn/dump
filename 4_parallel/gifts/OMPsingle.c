#include <stdio.h>
int main() {
#pragma omp parallel num_threads(3)
{
	#pragma omp single
	{
		printf("Pragma 1, %d\n",omp_get_thread_num());
	}
	printf("All threads %d\n",omp_get_thread_num());
	#pragma omp single
	{
		printf("Pragma 2, %d\n",omp_get_thread_num());
	}
}
return 0;
}