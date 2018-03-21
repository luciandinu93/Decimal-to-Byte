#include <stdio.h>
#include <stdlib.h>

char *decimal_to_binary(int); // function declaration

//Program converts decimal value to a byte
int main()
{
    int n, c, k; // defining integer values
    char *pointer; // defining pointer for saving the values

    printf("Enter an integer in decimal number system\n");
    scanf("%d", &n);// <- decimal value

    pointer = decimal_to_binary(n);// <- convert decimal to byte
    printf("Binary string of %d is: %s\n", n, pointer);

    free(pointer);// releasing char array memory

    return 0;
}

char *decimal_to_binary(int n) {
    int c, d, count;
    char *pointer;

    count = 0;
    pointer = (char*)malloc(8+1);// allocating memory 9 chars bbbbbbbb/0

    if (pointer == NULL)   //check statements exit(-1) if pointer is not defined
        exit(EXIT_FAILURE);

    for (c = 7; c >= 0; c--) {
        d = n >> c; //in 'd' we keep the value of n[c] (the decimal value is automatically transformed into binary ...0000...)

        if( d & 1)//check if n[c] == 1
            *(pointer+count) = 1 + '0'; // initial value of pointer is n[0] , return 1 if n[c] == 1
        else
            *(pointer+count) = 0 + '0';// return 0 if n[c] == 0

        count++;
    }
    *(pointer+count) = '\0';// end of char array

    return pointer;  // return array of char
}
