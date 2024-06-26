#include <stdio.h>
#include <stdlib.h>

struct op{
    int size;
    char op[10];
};

void parsecsv8080ops(struct op *operations){
    //D8 means one byte address reference D16 means two byte address reference?
    //do it in format opsarr[][x] where x = 0 is size of op, 1 is the front most part of op, 2 is the args of the op (skip the part where memory is referenced i.e. D8 or adr)
    char[50] buf = "\0";
    FILE *fp;

    fp = fopen("../data/8080ops.csv", "r");
    if(!fp){
        printf("8080ops.csv file didn't open.\n");
        exit(1);
    }

    int r = 0, c = 0, i = 0, inquotemark = 0;
    char *toremove;

    for(;*fp; fp++){
        if(*fp == '"') inquotemark = !inquotemark;
        else if(*fp == ',' && !inquotemark){
            c++;
        }
        else if(c == 1){
            buf[i] = *fp;
            i++
        }
        else if(c == 2){
            buf[i] = '\0';
            toremove = strstr(buf,"D8") | strstr(buf,"D16") | strstr(buf,"adr");
            if(toremove) *toremove = '\0';
            strcpy(operations[r].op, buf);
            i = 0;
            operations[r].size = (int) *fp - '0';
        }
        else if(c >= 4){
            c = 0;
            r++;
        }
    }
}

int 8080op(FILE *fp, int pc, struct op *operations){
    int bytes = operations[*fp].size;
    printf("%04x ", pc);

    for(int i = 0; i < operations[*fp].size; i++) printf("#02x ", fp[i]);
    for(int i = 0; i < 3 - operations[*fp].size; i++) printf("   ");

    //still need to do the extra args associated with operations
    printf("%s", op);

    //use opsarr to print operation line

    return bytes;
}

int main(){
    int pc = 0;
    struct op operations[256];
    FILE *fp;

    fp = fopen("../data/spaceinvaders.h", "r");
    if(!fp){
        printf("spaceinvaders.h file didn't open.\n");
        exit(1);
    }

    parsecsv8080ops(operations);

    while(*fp){
        pc = 8080op(fp, pc);
        for(int i = 0; i < pc; i++) fp++;
    }
}
