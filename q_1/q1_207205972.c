#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            // 1. Uninitialized data section
int primes[] = { 2, 3, 5, 7 };  // 2. Initialized data section

static int
square(int x)               //3. Text section - allocated in frame for square() 
{
    int result;                 // 4. allocated in the Stack of square() function

    result = x * x;
    return result;              // 5. return value is passed via register
}

static void
doCalc(int val)                 // 6. Text section- allocated in frame for doCalc()
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  // 7. allocated in the Stack of doCalc() function

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    // 8.Text section- allocated in frame for main()
{
    static int key = 9973;         // 9. Initialized data section
    static char mbuf[10240000];   // 10. Uninitialized data section
    char* p;                     // 11. allocated in the Stack 


    doCalc(key);

    exit(EXIT_SUCCESS);
}
