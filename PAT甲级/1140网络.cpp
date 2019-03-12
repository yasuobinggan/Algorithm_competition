#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j,k,n;
    char c[100000]={"\0"},d[100000]={"\0"},m[10]={"\0"};
    scanf("%c%*c%d",&c[0],&n);
    for (i=1;i<n;i++)
    {
        strcpy(d,"\0");
 //       memset(d,'\0',sizeof(d));
        j=1;k=0;
        do
        {
            while(c[j]!='\0' && c[j]==c[k])
            {
                j++;
            }
            m[0]=c[k];
            strcat(d,m);
            m[0]=j-k+'0';k=j;
            strcat(d,m);
        }while(c[j]!='\0');
        strcpy(c,d);
    }
    puts(c);
    return 0;
}

