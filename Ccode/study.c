#include<stdio.h>

int main(){
    int i = 6;
    int *p = &i;
    printf("&i=%p\n",&i);
    printf("*p=%d\n",*p);
    printf("*p=%p\n",*p);
    printf("&p=%p\n",&p);
    printf("p=%p\n",p);
    printf("p=%d\n",p);
    return 0;
}