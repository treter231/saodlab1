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

int getMax(uint32_t A[], int k);
//void print(uint32_t A[], int k);
void radixsort(uint32_t A[], int k);


int main()
{
    int k,s,i;
    double ttime;
    //uint32_t *A=NULL;
    FILE *ptrfile;

ptrfile=fopen("chisla (1).txt","r"); //открываем файл для чтения
 
while ((fscanf(ptrfile, "%d",&s)!=EOF))
{    if(!ptrfile) break;   
        k++;
}
uint32_t *A = (uint32_t *) malloc(sizeof(uint32_t) * k); //должен быть динамическим k*sizeof(int)
rewind(ptrfile); //перематываем файл для повторного чтения
for(i = 0; i < k; i++)
    
{
    fscanf(ptrfile, "%d\n",&A[i]);
    
//    printf("A[%d]=%d\n",i,A[i]);

}
    fclose(ptrfile);
   
      
for(k = 50000; k <= 1000000 ; k+=50000)
{
   
    ttime=wtime();
    srand(time(0));

    radixsort(A, k);
    /*printf("Отсортировано: ");

    for (i = 0 ; i < k; i++) 
    {
        printf("%d ", A[i]);
        } 
        printf("\n");*/
    ttime=wtime()-ttime;
    printf("Элементов: %d время выполнения %.4lf\n", k, ttime);

}
    return 0;
}

int getMax(uint32_t A[], int k)
{
    int mx = A[0];
    for (int i = 1; i < k; i++){
        if (A[i] > mx)
        {
            mx = A[i];
        }
    }
  
    return mx;
}


void countSort(uint32_t A[], int k, int exp)
{
    uint32_t output[k];
    int i, count[10] = {0};
 
    // Количество вхождений в count[] число сколько раз встречается разряд от exp
    for (i = 0; i < k; i++)
    {
        count[ (A[i]/exp)%10 ]++;
    }
 
    // Изменить count[i] чтобы понять позицию разряда на выходе
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    // Выход
    for (i = k - 1; i >= 0; i--){
       output[count[ (A[i]/exp)%10 ] - 1] = A[i];
       count[ (A[i]/exp)%10 ]--;
    }
 
    
    for (i = 0; i < k; i++)
    {
        A[i] = output[i];
    }
}

void radixsort(uint32_t A[], int k)
{
    int m = getMax(A, k);
    for (int exp = 1; m/exp > 0; exp *= 10){
        countSort(A, k, exp);
    }
} 
