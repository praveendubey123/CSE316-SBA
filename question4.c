#include<stdio.h>
#include<stdlib.h> 
int bursttime[20],p[20],waittime[20],tatime[20],priority[20],i,j,n,total=0,position,temp,avg_waittime,avg_tatime,at[20];
void insert()
{
    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time for P[%d]:",i+1);
        scanf("%d",&at[i]);
        printf("Enter Burst Time for P[%d]:",i+1);
        scanf("%d",&bursttime[i]);
        printf("Enter Priority for P[%d]:",i+1);
        scanf("%d",&priority[i]);
        p[i]=i+1;           
    }
}
void calcpriority()
{
    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[position])
                position=j;
        }
        temp=priority[i];
        priority[i]=priority[position];
        priority[position]=temp;
 
        temp=bursttime[i];
        bursttime[i]=bursttime[position];
        bursttime[position]=temp;
 
        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }
}
int main()
{   
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("\nEnter data for Process\n");
    insert();
    calcpriority();
    waittime[0]=0;
    for(i=1;i<n;i++)
    {
        waittime[i]=0;
        for(j=0;j<i;j++)
            waittime[i]+=bursttime[j];
 
        total+=waittime[i];
    }
    avg_waittime=total/n;
    total=0;
    printf("\nProcess\t    Burst Time    \tArrival Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tatime[i]=bursttime[i]+waittime[i];
        total+=tatime[i];
        printf("\nP[%d]\t\t  %d\t\t%d\t\t    %d\t\t\t%d",p[i],bursttime[i],at[i],waittime[i],tatime[i]);
    }
    avg_tatime=total/n;
    printf("\n\nAverage Waiting Time=%d",avg_waittime);
    printf("\nAverage Turnaround Time=%d\n",avg_tatime);
    return 0;
}
