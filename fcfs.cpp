#include<iostream>
using namespace std;
void waitingtime(int p[],int n,int bt[],int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }
}
void findtat(int p[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}
void avgwt(int p[],int n,int bt[])
{
    int wt[n],tat[n],totalwt=0,totaltat=0;
    waitingtime(p,n,bt,wt);
    findtat(p,n,bt,wt,tat);
    cout<<"processes "<<"Burst time "<<"waiting time "<<"turn around time \n";
    for(int i=0;i<n;i++)
    {
        totalwt=totalwt+wt[i];
        totaltat=totaltat+tat[i];
        cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t "<<wt[i]<<"\t\t "<<tat[i]<<endl;
    }
    cout<<"avg waiting time="<<(float)totalwt/(float)n;
    cout<<"\navg turn around time="<<(float)totaltat/(float)n;
}
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int bt[n];
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    avgwt(p,n,bt);
    return 0;
}