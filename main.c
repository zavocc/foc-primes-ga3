#include <stdio.h>

int main() 
{
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    int primes[1000], odd_primes[1000], even_primes[1000];
    int prime_count = 0, odd_count = 0, even_count = 0;

    for (int i = start; i <= end; i++) 
    {
        int is_prime = 1;

        if (i <= 1) 
        {
            is_prime = 0;
        } 
        else 
        {
            for (int j = 2; j * j <= i; j++) 
            {
                if (i % j == 0) 
                {
                    is_prime = 0;
                    break;
                }
            }
        }

        
        if (is_prime) 
        {
            primes[prime_count++] = i; 
            if (i % 2 == 0) 
            {
                even_primes[even_count++] = i;  
            } 
            else 
            {
                odd_primes[odd_count++] = i;
            }
        }
    }

    printf("All prime numbers: ");
    for (int i = 0; i < prime_count; i++) 
    {
        printf("%d ", primes[i]);
    }
    printf("\n");

    printf("Odd prime numbers: ");
    for (int i = 0; i < odd_count; i++) 
    {
        printf("%d ", odd_primes[i]);
    }
    printf("\n");

    printf("Even prime numbers: ");
    for (int i = 0; i < even_count; i++) 
    {
        printf("%d ", even_primes[i]);
    }
    printf("\n");

    return 0;
}