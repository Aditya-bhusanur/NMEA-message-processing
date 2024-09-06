#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *tokenize(char *ptr, char *buff, char delim); // Function-0, declaration.
int main()
{
    char *ptr;
    char buff[100];
    char str[] = "$GNRMC,072446.00,A,3130.5226316,N,12024.0937010,E,0.01,0.00,040620,0.0,E,D*3D"; // GNRMC message sentance
    ptr = str;
    while (ptr)
    {
        memset(buff, 0, sizeof(buff));  // Clearing the buffer.
        ptr = tokenize(ptr, buff, ','); // Function-0, call-0
        printf("%s\n", buff);           // Print tokens
    }
    return 0;
}
char *tokenize(char *ptr, char *buff, char del) // Function-0, defination
{
    int i = 0;
    while ((*ptr != del) && (*ptr != 0)) // Ckeck for delimiter condition AND check for null charecter
    {
        buff[i++] = *ptr++; // Add charecter to buffer and update both buffer and pointer
    }
    (*ptr == 0) ? ptr = 0 : ptr++; // Condition to terminate in case of emergency
    return ptr;
}