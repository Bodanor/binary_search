//
//  bench.h
//  Bench
//
//  Created by Christos Papadopoulos on 08/03/2021.
//

#ifndef bench_h
#define bench_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long int *createList(unsigned long int N);
int linearSearch(unsigned long int *list , unsigned long int nb , unsigned long int N);
int binarySearch(unsigned long int *list, unsigned long int nb, unsigned long int N);
int runBench(unsigned long int N, unsigned long int nombre_recherche);


#endif /* bench_h */
