#include <stdio.h>

int main() 
{
    /*this is were the decleration of variable*/
    int start, end;
    int validInput;
    // the start variable is the starting number to be input and the end is the last number 
    while (1)
    {
        // i use while loop to detect error while entering input so it will repeat the question if there's a typo
        printf("Enter the starting number: ");
        validInput = scanf("%d", &start);
        if (validInput =! 1 )
        {
            // this code detects if the input is a string 
            printf("Invalid input! Please enter an integer.\n");
            
             while (getchar() != '\n');  
             continue;  
        }
        printf("Enter the end number: ");
        validInput = scanf("%d", &end);  

        
        if (validInput != 1)
        {
            //this code detects if the input is float
            printf("Invalid input! Please enter an integer.\n");
            
            while (getchar() != '\n');  
            continue;  
        }
        //this code detects if the start input is the larger than end 
        if(start > end){
            printf("invalid input, the start input must be the lowest number. \n");
            continue;
        }
        break;


    }

    //if the user doesnt have any error it will continue to the main code
    printf("You entered a valid range: %d to %d\n", start, end);

    
    printf("Prime numbers in the range:\n");
    for (int num = start; num <= end; num++) {

        // i use for loop because the prime numbers continues to print and will stop to specific number were it will end
        int isPrime = 1;
        if (num <= 1) continue;  
        
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d is prime\n", num);
        }
    }

    return 0;
}


    








