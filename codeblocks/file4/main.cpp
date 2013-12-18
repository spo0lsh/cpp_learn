#include <iostream>
#include <fstream>
#include <share.h>
#include <memory.h>
#include <stdio.h>
#include <cmath>

#define DEFAULT_BUFFER      2048
using namespace std;
int main()
{
    FILE *input;
    FILE *output;
    char sBuffer[DEFAULT_BUFFER];
    if((input=_fsopen("input.exe", "rb", _SH_DENYWR )) == NULL )
    {
        printf("problem z input\n");
        return 1;
    }
    if((output=_fsopen("output.exe", "wb", _SH_DENYWR )) == NULL )
    {
        printf("problem z output\n");
        return 1;
    }
    double fileSize;
    int bytesRead;
    fseek (input , 0 , SEEK_END);
    fileSize = ftell (input);
    rewind (input);
    printf("filesize %lf\n", fileSize);
    if(fileSize < DEFAULT_BUFFER)
    {
        memset(sBuffer, 0, sizeof(sBuffer));
        bytesRead=fread(sBuffer,sizeof(char),DEFAULT_BUFFER,input);
        printf("Readed bytes %d\n", bytesRead);
        fwrite(sBuffer , sizeof(char), bytesRead, output);
    }
    else
    {
        int i;
        double packets=ceil(fileSize/DEFAULT_BUFFER);
        printf("packets=%lf  %lf/%d\n",packets,fileSize,DEFAULT_BUFFER);
        for(i=0;i<packets;++i)
        {
            memset(sBuffer, 0, sizeof(sBuffer));
            bytesRead=fread(sBuffer,sizeof(char),DEFAULT_BUFFER,input);
            printf("Readed bytes %d\n", bytesRead);
            fwrite(sBuffer , sizeof(char), bytesRead, output);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
