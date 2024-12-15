#include<stdio.h>
#include<string.h>

int main()
{
    int count = 0;
    char s[20],buf[99];
    scanf("%s",s);
    for(int abc = 111;abc<=999;abc++){
        for(int de = 11;de<=99;de++){
            int x = abc*(de%10);//与个位相乘
            int y = abc*(de/10);//与十位相乘
            int z = abc*de;//总乘积
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);//sprintf将数字输出到buf数组中
            int ok = 1;
            for(int i = 0;i<strlen(buf);i++){   //strlen()用于获取buf的实际长度
                if(strchr(s,buf[i])==NULL){ //strchr()用于查找字符串s中是否包含字符buf[i]     
                    ok = 0;
                    }
                }
            if(ok){
                    printf("<%d>\n",++count);
                    printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);

            }
        }
    }
    printf("The number of solutions = %d\n",count);
    return 0;
}