//when arrival time is given
#include<iostream>
using namespace std;
void findwt(int p[],int n,int bt[],int wt[],int at[])
{
    wt[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i]==at[j])
            {
                if(bt[i]>bt[j])
                {
                    swap(p[i],p[j]);
                    swap(bt[i],bt[j]);
                    swap(at[i],at[j]);
                }
            }
        }
    }
    for(int k=1;k<n;k++)
    {
        wt[k]=bt[k-1]+wt[k-1];
    }
}