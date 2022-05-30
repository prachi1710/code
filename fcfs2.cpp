#include<iostream>
using namespace std;
void findwt(int p[],int n,int bt[],int wt[],int at[])
{
    int st[n];
    st[0]=at[0];
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        st[i]=st[i-1]+bt[i-1];
        wt[i]=st[i]-at[i];
        if(wt[i]<0)
        {
            wt[i]=0;
        }
    }
}
void findtat(int p[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }

}
void findavgtime(int p[],int n,int bt[],int at[])
{
    int wt[n],tat[n];
    findwt(p,n,bt,wt,at);
    findtat(p,n,bt,wt,tat);
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";
    int totalwt=0,totaltat=0;
    for(int i=0;i<n;i++)
    {
        totalwt=totalwt+wt[i];
        totaltat=totaltat+tat[i];
        int com_time=tat[i]+at[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t "<< at[i] << "\t\t" << wt[i] << "\t\t  "<< tat[i]  <<  "\t\t " << com_time << endl;
    }
    cout << "Average waiting time = "
         << (float)totalwt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)totaltat / (float)n;
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
    int at[n];
    cout<<"Enter the arrival time of the processes:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>at[i];
    }
    findavgtime(p,n,bt,at);
    return 0;
}