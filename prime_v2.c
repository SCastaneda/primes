#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int *prime;
    int end_prime, n = 1, lines = 0;

    prime = (int *)malloc((n+1)*sizeof(int));
    prime[0] = 2;

        //printf("End at:");
        //scanf("%d", &end_prime);
        end_prime = 100000;

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
            n++;
            prime = (int *)realloc(prime, (n+1)*sizeof(int));
            prime[n-1] = i;
        }
    }
    for(i = 0; i <  n; i++) {
        printf("%d ", prime[i]);
        lines++;
        if(lines == 10) {
            printf("\n");
            lines = 0;
        }
    }

    return 0;

}

