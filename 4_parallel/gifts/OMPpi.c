#include <stdio.h>
#include<math.h>
#include<string.h>
int main() {
int count=0;
int N,i;
int thr;
int thread,size;
int alf;
double h,sum,sumthread,f1,f2,x1,x2;

//Считывание из файлаи
if (fopen("N.dat","r") ==0)
{
        printf("Error no such file\n");
MPI_Finalize();
return 0;
}
FILE *fl;
fl=fopen("N.dat","r");
if ( fscanf(fl,"%d",&N) != 1){
printf("Error fscanf\n");
}
fscanf(fl,"%d",&N);
fclose(fl);

//Параллельная часть
#pragma omp parallel shared(N) private(f1,f2,x1,x2,sum,i,alf,thr) reduction(+:sumthread)
{
{
	size=omp_get_num_threads();
	thr=omp_get_thread_num();
	h=2.0/N;
	alf=(int)(1.0*N/size);
	i=0;
}
if (thr !=(size-1)){
	while(i<alf){
		x1=h*(i+thr*alf);
		x2=h*((i+1)+thr*alf);
		i=i+1;
		f1=pow(4.0-x1*x1,1.0/2);
		f2=pow(4.0-x2*x2,1.0/2);
		sum=h*(f1+f2)/2;
		sumthread=sumthread+sum;
	}
}
if (thr==(size-1)){
	i=thr*alf;
	while (i<N){
		x1=h*(i);
		x2=h*(i+1);
		i=i+1;
		f1=pow(4.0-x1*x1,1.0/2);
		f2=pow(4.0-x2*x2,1.0/2);
		sum=h*(f1+f2)/2;
		sumthread=sumthread+sum;
	}
}
//printf("pi=%f\n",sumthread);
}

//Окончательный результат
printf("pi=%f\n",sumthread);
return 0;
}