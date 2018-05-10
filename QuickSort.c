#define red printf("%s","\033[1;31m")
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

void quickSort( int[], int, int);
int partition( uint32_t[], uint32_t, uint32_t);

double wtime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec/1E6;
}


int main() 
{
    uint32_t quantity;
    uint32_t *a = (uint32_t *) malloc(sizeof(uint32_t) * 1000000);
    for (quantity=50000 ; quantity<1050000; quantity+=50000){
        memset(a,' ',quantity);
        double ttime;
        ttime=wtime();
        srand(time(0));
        uint32_t i,c;
        for (c = 0; c < quantity; c++)
        a[c] = rand() % 100000;
        quickSort( a, 0, quantity-1);
        ttime=wtime()-ttime;
        printf("Элементов=%d время выполнения=%lf сек\n", quantity, ttime);
    }
    return 0;
}



void quickSort( int a[], int l, int r)
{
    uint32_t j;
    if ( l < r ){
    j = partition( a, l, r);
    quickSort( a, l, j-1);
    quickSort( a, j+1, r);
    }
}

int partition( uint32_t *a, uint32_t l, uint32_t r) {
     uint32_t pivot, i, j, t;
     pivot = a[l];
     i = l; j = r+1;
     while( 1){
         do ++i; 
         while( a[i] <= pivot && i <= r );
         do --j; 
         while( a[j] > pivot );
         if( i >= j ) 
         break;
         t = a[i]; 
           a[i] = a[j]; 
         a[j] = t;
     }
     t = a[l]; 
     a[l] = a[j]; 
     a[j] = t;
     return j;
}

