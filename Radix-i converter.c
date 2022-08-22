#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Name"
#define YEAR "2022"

void print_header(){    // Prints the header of the program
    printf("***************************");
    printf("\n%s",TITLE);   // Prints the title of the program
    printf("\nWritten by: %s",AUTHOR);  // Prints the author of the program
    printf("\nDate: %s",YEAR);  // Prints the year of the program
    printf("\n***************************\n");
}

char* Dec2RadixI(int decValue, int radValue){   // Converts a decimal value to a radix-i value
    char *radixI = (char*)malloc(sizeof(char)*100); // Allocates memory for the radix-i value
    int i = 0;                                  // Counter for the loop
    while(decValue > 0){                    // While the decimal value is greater than 0
        radixI[i] = decValue % radValue + '0';  // Converts the decimal value to a radix-i value
        decValue /= radValue;                // Divides the decimal value by the radix-i value
        i++;                             // Increments the counter
    }
    radixI[i] = '\0';                       // Adds a null character to the end of the string
    // reverse the string
    int j = 0;                             // Counter for the loop
    int k = i - 1;                       // Counter for the loop
    while(j < k){                      // While the counter is less than the other counter
        char temp = radixI[j];        // Stores the value of the first character in a temporary variable
        radixI[j] = radixI[k];      // Stores the value of the last character in the first character
        radixI[k] = temp;         // Stores the value of the temporary variable in the last character
        j++;                     // Increments the counter
        k--;                 // Decrements the counter
    }
    return radixI;                        // Returns the radix-i value
}

int main(){
    print_header(); // Prints the header of the program
    int decValue;   // Stores the decimal value
    int radValue;   // Stores the radix-i value

    while (true){
        printf("Enter a decimal number: "); // Prompts the user to enter a decimal number
        scanf("%d",&decValue);           // Stores the decimal value
        if(decValue == -1){             // If the decimal value is -1
            printf("EXIT\n");         // Prints EXIT
            break;                 // Breaks the loop
        }
        printf("The number you have entered is %d\n",decValue); // Prints the decimal value
        printf("Enter a radix for the converter between 2 and 16: ");   // Prompts the user to enter a radix for the converter
        scanf("%d",&radValue);         // Stores the radix-i value
        if(radValue == -1 || radValue < 2 || radValue > 16){    // If the radix-i value is -1, less than 2, or greater than 16
            printf("EXIT\n");   // Prints EXIT
            break;           // Breaks the loop
        }
        printf("The radix you have entered is %d\n",radValue);  // Prints the radix-i value
        printf("The log2 of the number is %.2lf\n",log2(decValue)); // Prints the log2 of the decimal value
        printf("The integer result of the number divided by 2 is %d\n",decValue/2); // Prints the integer result of the decimal value divided by 2
        printf("The remainder is %d\n",decValue%2); // Prints the remainder of the decimal value divided by 2
        printf("The radix-%d value is ",radValue);  // Prints the radix-i value
        printf("%s\n",Dec2RadixI(decValue,radValue));   // Prints the radix-i value
    }
    return 0;   // Returns 0
}