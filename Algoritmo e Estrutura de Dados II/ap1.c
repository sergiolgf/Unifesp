#include <stdio.h>

int primoREC(int num, int div){
    if(num<=1){
        return 0;
    }else if(num==div){
        return 1;
    }else if(num%div==0){
        return 0;
    }else return primoREC(num,div+1);
}

int primoITE(int num){
    int i=2;
    for(i=2;i<num;i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

void main(){
    int num;
    scanf("%d",&num);
    //printf("%d",primoREC(num,2));
    printf("%d",primoITE(num));
}