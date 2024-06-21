#include <stdio.h>
#include <stdlib.h>

void parsecsv8080ops(char ***opsarr){
    //D8 means one byte address reference D16 means two byte address reference?
    //do it in format opsarr[][x] where x = 0 is size of op, 1 is the front most part of op, 2 is the args of the op (skip the part where memory is referenced i.e. D8 or adr)
    char[50] buf = "\0";
    FILE *fp;

    fp = fopen("8080ops.csv", "r");
    if(!fp){
        printf("File didn't open");
        exit(1);
    }

    for(;*fp; fp++){

    }

}

int 8080op(FILE *fp, int pc, char ***opsarr]){
    int bytes = 1;
    printf("%04x ", pc);

    //use opsarr to print operation line

    return bytes;
}

int main(){
    int byte = 0;
    char[256][3][10];
    FILE *fp;

    fp = fopen("spaceinvaders.h", "r");
    if(!fp){
        printf("File didn't open");
        exit(1);
    }

    while(*fp){
        printf("%04i ", byte);
        byte = 8080op(fp, byte);
    }

}
