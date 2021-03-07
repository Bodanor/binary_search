//
//  main.c
//  binary_search
//
//  Created by Christos Papadopoulos on 07/03/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *createList(int N)
{
    int *liste;
    liste = malloc(sizeof(int)*N);
    for (int x = 0; x <= N; x++)
    {
        liste[x] = x;
        
    }
    
    return liste;
    
    
}


int linearSearch(int *list , int nb , int N)
{
    int i = 0;
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

int binarySearch(int *list, int nb, int N)
{
    int left = 0;
    int right = N-1;
    
    while (left <= right)
    {
        int middle = left + (right - left) /2;
        
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

int main(int argc, const char * argv[]) {
    
    
    int N =1000000;
    int nombre_recherche = 939827;
    struct timeval *start = malloc(sizeof(start));
    struct timeval *end = malloc(sizeof(end));
    
    gettimeofday(start, 0);
    
    int *list = createList(N);
    
    gettimeofday(end, 0);
    long seconds = end->tv_sec - start->tv_sec;
    long microseconds = end->tv_usec - start->tv_usec;
    
    double time_taken = seconds + microseconds*1e-6;
    
    printf("Liste crée en %f secondes !\n", time_taken);
    
    free(start);
    free(end);
    
    start = malloc(sizeof(start));
    end = malloc(sizeof(end));
    gettimeofday(start, 0);
    
    
    int linear_result = linearSearch(list, nombre_recherche, N);
    
    if (linear_result == 0)
    {
        gettimeofday(end, 0);
        long seconds = end->tv_sec - start->tv_sec;
        long microseconds = end->tv_usec - start->tv_usec;
        
        double time_taken = seconds + microseconds*1e-6;
        
        printf("Linéaire : Nombre trouvé en %f secondes !\n", time_taken);
    }
    else{
        printf("Linéaire : Nombre non trouvé !\n");
    }
    
    free(start);
    free(end);
    
    start = malloc(sizeof(start));
    end = malloc(sizeof(end));
    
    int binary_result = binarySearch(list, nombre_recherche, N);
    
    
    if (binary_result == 0)
    {
        gettimeofday(end, 0);
        long seconds = end->tv_sec - start->tv_sec;
        long microseconds = end->tv_usec - start->tv_usec;
        
        double time_taken = seconds + microseconds*1e-6;
        
        printf("Binaire : Nombre trouvé en %f secondes !\n", time_taken);
    }
    else{
        printf("Binaire : Nombre non trouvé !\n");
    }
    
    free(start);
    free(end);
    free(list);
}
