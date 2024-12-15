#include<stdio.h>
#include<string.h>

int main(){
    char s[] = "hello world";
    char *buf;
    char *buf2;
    buf = strchr(s,'w');
    buf2 = strchr(s,'a');

    if(buf == NULL){
    printf("not found\n");
    }else{
        printf("found\n");
    }

    if(buf2 == NULL){
    printf("not found\n");
    }else{
        printf("found\n");
    }
    return 0;
}