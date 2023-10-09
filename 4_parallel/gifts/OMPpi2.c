#include <stdio.h>
#include<math.h>
#include<string.h>
int main() 
{
int N,i;
double h,sum,sumthread,f1,f2,x1,x2;

//Считывание из файлаи
if (fopen("N.dat","r") ==0)
{
        printf("Error no such file\n");
return 0;
}
FILE *fl;
fl=fopen("N.dat","r");
if ( fscanf(fl,"%d",&N) != 1){
printf("Error fscanf\n");
}
fscanf(fl,"%d",&N);
fclose(fl);
	h=2.0/N;
//Параллельная часть

#pragma omp parallel shared(N,h) private(f1,f2,x1,x2,sum) reduction(+:sumthread)
{
#pragma omp for
	for (i=0; i<N; i++)
	{
		x1=h*i;
		x2=h*(i+1);
		f1=pow(4.0-x1*x1,1.0/2);
		f2=pow(4.0-x2*x2,1.0/2);
		sum=h*(f1+f2)/2;
		sumthread=sumthread+sum;
	}

}

//Окончательный результат
printf("pi=%f\n",sumthread);
return 0;
}