//
//  bench.c
//  Bench
//
//  Created by Christos Papadopoulos on 08/03/2021.
//

#include "bench.h"

unsigned long int *createList(unsigned long int N)
{
    unsigned long int *liste;
    liste = (unsigned long int*)calloc(N,sizeof(unsigned long int));
    if (liste == NULL)
    {
        return NULL;
        
    }
    for (unsigned long int x = 0; x <= N; x++)
    {
        liste[x] = x;
        
    }
    
    return liste;
    
    
}

int linearSearch(unsigned long int *list , unsigned long int nb , unsigned long int N)
{
    unsigned long int i = 0;
    while (nb != list[i] && i <= N)
    {
        i++;
    }
    if (nb == list[i])
    {
        return 0;
        
    }
    else
    {
        return 1;
        
    }
}


int binarySearch(unsigned long int *list, unsigned long int nb, unsigned long int N)
{
    unsigned long int left = 0;
    unsigned long int right = N-1;
    
    while (left <= right)
    {
        unsigned long int middle = left + (right - left) /2;
        
        if (list[middle] == nb)
        {
            return 0;
            
        }
        else if (list[middle] > nb)
        {
            right = middle -1;
            
        }
        else
        {
            left = middle+1;
            
        }
        
        
    }
    return 1;
    
}


int runBench(unsigned long int N, unsigned long int nombre_recherche)
{
    
    
    
    struct timespec *start = malloc(sizeof(start));
    struct timespec *end = malloc(sizeof(end));
    
    clock_gettime(CLOCK_REALTIME, start);
    
    unsigned long int *list = createList(N);
    if (list == NULL)
    {
        return -1;
        
    }
    
    clock_gettime(CLOCK_REALTIME, end);
    double time_taken = (end->tv_sec - start->tv_sec) + (end->tv_nsec - start->tv_nsec)/1E9;
    printf("Liste crée en %f secondes !\n", time_taken);
    
    free(start);
    free(end);
    
    start = malloc(sizeof(start));
    end = malloc(sizeof(end));
    
    clock_gettime(CLOCK_REALTIME, start);
    
    int linear_result = linearSearch(list, nombre_recherche, N);
    
    if (linear_result == 0)
    {
        clock_gettime(CLOCK_REALTIME, end);
        double time_taken = (end->tv_sec - start->tv_sec) + (end->tv_nsec - start->tv_nsec)/1E9;
        
        printf("Linéaire : Nombre trouvé en %f secondes !\n", time_taken);
    }
    else{
        printf("Linéaire : Nombre non trouvé !\n");
    }
    
    free(start);
    free(end);
    
    start = malloc(sizeof(start));
    end = malloc(sizeof(end));
    
    clock_gettime(CLOCK_REALTIME, start);
    
    int binary_result = binarySearch(list, nombre_recherche, N);
    
    
    if (binary_result == 0)
    {
        
        clock_gettime(CLOCK_REALTIME, end);
        double time_taken = (end->tv_sec - start->tv_sec) + (end->tv_nsec - start->tv_nsec)/1E9;
        
        printf("Binaire : Nombre trouvé en %f secondes !\n", time_taken);
    }
    else{
        printf("Binaire : Nombre non trouvé !\n");
    }
    
    free(start);
    free(end);
    free(list);
    return 0;
    
}
