#include <stdio.h>
#include <string.h>
char *tokenize(char *s1, const char *delim);
int main()
{
    char gnrmc[] = "$GNRMC,072446.00,A,3130.5226316,N,12024.0937010,E,0.01,0.00,040620,0.0,E,D*3D";
    char *token = tokenize(gnrmc, ",");
    int i = 0;
    while (token != NULL)
    {
        // printf("%d\t%s\n",i, token);
        switch (i)
        {
        case 0:
            printf("<0>\t%s\n", token);
            break;
        case 1:
            printf("UTC time, the format is hhmmss.sss:\t%s\n", token);
            break;
        case 2:
            printf("Positioning status, A=effective positioning, V=invalid positioning:\t%s\n", token);
            break;
        case 3:
            printf("Latitude, the format is ddmm.mmmmmmm:\t%s\n", token);
            break;
        case 4:
            printf("Latitude hemisphere, N or S (north latitude or south latitude):\t%s\n", token);
            break;
        case 5:
            printf("Longitude, the format is dddmm.mmmmmmm:\t%s\n", token);
            break;
        case 6:
            printf("Longitude hemisphere, E or W (east longitude or west longitude):\t%s\n", token);
            break;
        case 7:
            printf("Ground speed:\t%s\n", token);
            break;
        case 8:
            printf("Ground heading (take true north as the reference datum):\t%s\n", token);
            break;
        case 9:
            printf("UTC date, the format is ddmmyy (day, month, year):\t%s\n", token);
            break;
        case 10:
            printf("Magnetic declination (000.0~180.0 degrees):\t%s\n", token);
            break;
        case 11:
            printf("Magnetic declination direction, E (east) or W (west):\t%s\n", token);
            break;
        case 12:
            printf("Mode indication (A=autonomous positioning, D=differential, E=estimation, N=invalid data)\n* Statement end marker\nxx XOR check value of all bytes starting from $ to *\n<CR> Carriage return, end tag\n<LF> line feed, end tag:\t%s\n", token);
            break;

        default:
            break;
        }

        token = tokenize(NULL, ",");
        i++;
    }

    return 0;
}
char *tokenize(char *s1, const char *delim)
{
    static char *ptr;
    if (s1 == NULL)
    {
        s1 = ptr;
    }
    if (*s1 == '\0')
    {
        return NULL;
    }
    ptr = s1 + strspn(s1, delim);
    if (*ptr == '\0')
    {
        return NULL;
    }
    s1 = ptr;
    ptr = s1 + strcspn(s1, delim);
    if (*ptr == '\0')
    {
        return NULL;
    }
    else
    {
        *ptr++ = '\0';
    }
    return s1;
}