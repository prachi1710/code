#include<iostream>
using namespace std;
void findwt(int p[],int n,int bt[],int wt[])
{
    wt[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(p[i],p[j]);
                swap(bt[i],bt[j]);
            }
        }
    }
    for(int k=1;k<n;k++)
    {
        wt[k]=bt[k-1]+wt[k-1];
    }
}
void avgwt(int p[],int n,int bt[])
{
    int wt[n],totalwt=0;
    findwt(p,n,bt,wt);
    cout<<"processes "<<"Burst time "<<"waiting time \n";
    for(int i=0;i<n;i++)
    {
        totalwt=totalwt+wt[i];
        cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t "<<wt[i]<<"\t\t "<<endl;
    }
    cout<<"avg waiting time="<<(float)totalwt/(float)n;
}
int main()
{
    int n;
    cout<<"Enter the number of processes:"<<endl;
    cin>>n;
    int p[n];
    cout<<"enter the process id:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int bt[n];
    cout<<"enter the burst time of the processes:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    avgwt(p,n,bt);
    return 0;
}