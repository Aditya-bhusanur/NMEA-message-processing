#include<stdio.h>
#include<string.h>
int main(){
    char gnrmc[]="$GNRMC,072446.00,A,3130.5226316,N,12024.0937010,E,0.01,0.00,040620,0.0,E,D*3D";
    char *token=strtok(gnrmc, ",");
    int i=0;
    while (token != NULL)
    {
        //printf("%d\t%s\n",i, token);
        switch (i)
        {
        case 0:
            printf("<0>\t %s\n", token);
            break;
        case 1:
            printf("UTC time, the format is hhmmss.sss: %s\n", token);
            break;
        case 2:
            printf("Positioning status, A=effective positioning, V=invalid positioning: %s\n", token);
            break;
        case 3:
            printf("Latitude, the format is ddmm.mmmmmmm: %s\n", token);
            break;
        case 4:
            printf("Latitude hemisphere, N or S (north latitude or south latitude): %s\n", token);
            break;
        case 5:
            printf("Longitude, the format is dddmm.mmmmmmm: %s\n", token);
            break;
        case 6:
            printf("Longitude hemisphere, E or W (east longitude or west longitude): %s\n", token);
            break;
        case 7:
            printf("Ground speed: %s\n", token);
            break;
        case 8:
            printf("Ground heading (take true north as the reference datum): %s\n", token);
            break;
        case 9:
            printf("UTC date, the format is ddmmyy (day, month, year): %s\n", token);
            break;
        case 10:
            printf("Magnetic declination (000.0~180.0 degrees): %s\n", token);
            break;
        case 11:
            printf("Magnetic declination direction, E (east) or W (west): %s\n", token);
            break;
        case 12:
            printf("Mode indication (A=autonomous positioning, D=differential, E=estimation, N=invalid data)\n* Statement end marker\nxx XOR check value of all bytes starting from $ to *\n<CR> Carriage return, end tag\n<LF> line feed, end tag: %s\n", token);
            break;
        
        default:
            printf("END\n");
            break;
        }
        token=strtok(NULL, ",");
        i++;
    }
   
    return 0;
}