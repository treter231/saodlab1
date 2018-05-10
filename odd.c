#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>

double wtime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec/1E6;
}

void swap(uint32_t *, uint32_t *);
void oddeven_sort(uint32_t *, int);
void print(uint32_t arr[], int n);

int main()
{
    int n,i;
    double ttime;
 
    for(n = 50000; n <= 1000000; n+=50000){
        uint32_t *arr = (uint32_t *) malloc(sizeof(uint32_t) * n);
        for (i = 0; i < n; i++){
            arr[i] = rand() % 100000;
        }
        ttime=wtime();
        srand(time(0));
        oddeven_sort(&arr[0], n);
        ttime=wtime()-ttime;
        printf("Элементов: %d время выполнения %.4lf\n", n, ttime);
    }
    return 0;
}

void swap(uint32_t * x, uint32_t * y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; 
}

void oddeven_sort(uint32_t * x, int t)
{
    int sort = 0, i;
    while (!sort){
       sort = 1;
       for (i = 1;i < t-1;i += 2)
        {
            if (x[i] > x[i+1])
            {
               swap(&x[i], &x[i+1]);
               sort = 0;
            }
        }

        for (i = 0;i < t-1;i += 2)
        {
            if (x[i] > x[i + 1])
            {
                swap(&x[i], &x[i + 1]);
                sort = 0;
            }
        }
    }
}


void print(uint32_t arr[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ", (arr)[i] );
    }
    printf("\n ");
}
