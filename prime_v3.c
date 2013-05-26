#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//gcc fastprime.c -o fastprime -lm

int main(int varc, char *vars[]) {
    int *prime;
    int end_prime, n = 1, high, lines = 0;

    prime = (int *)malloc((n+1)*sizeof(int));
    prime[0] = 2;
    lines++;

    if( varc > 1 ) {
      end_prime = atoi(vars[1]);
    } else {

      printf("End at:");
      scanf("%d", &end_prime);
      //end_prime = 100000;
    }
    high = (int)sqrt(end_prime)+1;

    printf("%d ", prime[0]);

    int i, j, flag = 1;

    for(i = 3; i <= end_prime; i++) {
        flag = 1; // reset flag
        if(i % 2 == 0) // if it's divisible by 2, then it's not a prime
            continue;  // so, just move on to the next number

        // divide i by all current prime numbers
        for(j = 0; j < n; j++) {
            if(i % prime[j] == 0) { // if it's divisible by a previous prime number,
                flag = 0;           // change flag so it does not get added to the prime array
                continue;           // if we found a number for which the mod is 0 then just skip to the next number
            }
        }
        // if flag remains at 1 we found a new prime
        if(flag == 1) {
            if(i < high){
                n++;
                prime = (int *)realloc(prime, (n+1)*sizeof(int));
                prime[n-1] = i;
            }
            printf("%d ", i);
            lines++;
            if(lines == 10) {
                printf("\n");
                lines = 0;
            }
        }
    }

    return 0;

}

