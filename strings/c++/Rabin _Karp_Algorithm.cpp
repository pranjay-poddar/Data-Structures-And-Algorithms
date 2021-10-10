#include<iostream>
#include<string.h>
using namespace std;
#define d 10
void rabinkarp(char pattern[],char text[],int q)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    for(i=0;i<m-1;i++)
    {
        h=(h*d)%q;
        
        
    }
    //calucalte hash value for pattern and text
    for(i=0;i<m;i++)
    {
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;

    }

    //find the match
    for(i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    break;
                }
            }

            if(j==m)
            {
                cout<<"pattern is found at position::"<<i+1<<endl;
            }
        }
        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
            
            if(t<0)
            {
                t=(t+q);

            }
        }


    }
}

int main()
{
    char text[]="ABCCDDAEFG";
    char pattern[]="CDD";
    int q=13;
    rabinkarp(pattern,text,q);


}

