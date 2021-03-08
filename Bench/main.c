#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "bench.h"

void printUsage(void)
{
    printf("Usage : ./bench :\n");
    printf("\t\t--short || -s : Create a list with a size of 5000000 int\n");
    printf("\t\t--medium || -m : Create a list with a size of 50000000 int\n");
    printf("\t\t--long || -l : Create a list with a size of 50000000 int\n");
    printf("\t\t--custom || -c <size> : Create a list with a custom size \n\n");
    
}

int main(int argc, char **argv){
    const char *optstring=":smlc:";
    int benchFlag = 0;
    unsigned long int N = 0;
    unsigned long int nombre_recherche = 0;
    
    unsigned long int converted = 0;
    const struct option lopts[] = {
        {"short", no_argument, NULL, 's'},
        {"medium", no_argument, NULL, 'm'},
        {"long", no_argument, NULL, 'l'},
        {"custom", required_argument, NULL, 'c'},
        {NULL, no_argument, NULL, 0},
    };
    
    int val, index = -1;
    
    while(EOF!=(val = getopt_long(argc, argv, optstring, lopts, &index))){
        
        
        switch(val){
            case 's':
                N = 5000000;
                nombre_recherche = 4999999;
                benchFlag = 1;
                break;
                
            case 'm':
                N = 50000000;
                nombre_recherche = 49999999;
                benchFlag = 2;
                break;
                
            case 'l':
                N = 500000000;
                nombre_recherche = 499999999;
                benchFlag = 3;
                break;
                
            case 'c':
                converted = strtoul(optarg, NULL ,0);
                if (converted == 0)
                {
                    printf("argument for %s must be an integer !\n", argv[optind-2]);
                    return -2;
                }
                else if (converted == -1)
                {
                    printf("int argument for %s is too big !\n", argv[optind-2]);
                    return -2;
                    
                }
                else{
                    N = converted;
                    nombre_recherche = N-1;
                    
                }
                break;
            case ':':
                printf("missing arg: %c\n", optopt);
                break;
            case '?':
                printf("unknown option: %s\n", argv[optind-1]);
                printUsage();
                exit(EXIT_FAILURE);
                
                
                
        }
        
        index = -1;
    }
    
    index = optind;
    if (index < argc)
    {
        printf("Non-option argument \'%s\'\n", argv[index]);
        
        
    }
    
    if (benchFlag != 0 || N != 0)
    {
        int status = runBench(N, nombre_recherche);
        if (status == -1)
        {
            printf("Error in memory allocation. Please try a lower bench with the option flag :\t--custom\n");
        }
        
    }
    
    else {
        printUsage();
        
    }
    
    
    
}

