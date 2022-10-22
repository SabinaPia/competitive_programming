#include<iostream>
#include<stdio.h>
#include<string.h>

int main()
{
    char a[30];
	int b[110];
    int T, n, s = 0, e;
	
    while(scanf("%d",&T)==1){
        for(int i = 0; i < T; i++){
            scanf("%d",&n);
            for(int j = 1; j <= n; j++){
                scanf("%s",a);
                if(strcmp(a,"LEFT") == 0){
                    s--;
                    b[j] = -1;
                }
                else if(strcmp(a,"RIGHT") == 0){
                    s++;
                    b[j] = 1;
                }
                else{
                    scanf("%s%d",a,&e);
                    s += b[e];
                    b[j] = b[e];
                }
            }
            
            printf("%d\n",s);
        }
    }
    
    
    return 0;
}
