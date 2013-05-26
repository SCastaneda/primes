#include <stdio.h>
#include <time.h>


int main() {
	double start_time, end_time;
	
	int prime = 2, end_prime;
	int i = 2, x = 1;
	
	printf("End with:");
	scanf("%d", &end_prime);
	
	for(;prime <= end_prime; prime++) {
		x = 1;
		for(i = 2; i <= prime; i++)
			if(prime % i == 0)
				x = 0;		
		if (x)
			printf("%d ", prime);
	
	}
	return 0;
}
