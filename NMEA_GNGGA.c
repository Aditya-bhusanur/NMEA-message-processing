#include<stdio.h>
#include<string.h>
int main(){
    char gngga[]="$GNRMC,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,< 12>*xx<CR><LF> ";
    char *token=strtok(gngga, ",");
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
            printf("%s\t UTC time, the format is hhmmss.sss\n", token);
            break;
        case 2:
            printf("%s\t Positioning status, A=effective positioning, V=invalid positioning\n", token);
            break;
        case 3:
            printf("%s\t Latitude, the format is ddmm.mmmmmmm\n", token);
            break;
        case 4:
            printf("%s\t Latitude hemisphere, N or S (north latitude or south latitude)\n", token);
            break;
        case 5:
            printf("%s\t Longitude, the format is dddmm.mmmmmmm\n", token);
            break;
        case 6:
            printf("%s\t Longitude hemisphere, E or W (east longitude or west longitude)\n", token);
            break;
        case 7:
            printf("%s\t Ground speed\n", token);
            break;
        case 8:
            printf("%s\t Ground heading (take true north as the reference datum)\n", token);
            break;
        case 9:
            printf("%s\t UTC date, the format is ddmmyy (day, month, year)\n", token);
            break;
        case 10:
            printf("%s Magnetic declination (000.0~180.0 degrees)\n", token);
            break;
        case 11:
            printf("%s Magnetic declination direction, E (east) or W (west)\n", token);
            break;
        case 12:
            printf("<12> Mode indication (A=autonomous positioning, D=differential, E=estimation, N=invalid data)\n* Statement end marker\nxx XOR check value of all bytes starting from $ to *\n<CR> Carriage return, end tag\n<LF> line feed, end tag\n", token);
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