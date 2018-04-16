#include <stdio.h>
#include <stdlib.h>
int a,b,i,j,process,count;
int maxmatrix[20][20],needmatrix[20][20],allocmatrix[20][20],availmatrix[20],finished[20],safeseq[20];
void insertdata()
{
    printf("\n\nEnter the maximum matrix for every process: ");
    for(i=0;i<a;i++)
    {
        printf("\nMaximum matrix ");
        printf("P[%d]: ",i+1);
        for(j=0;j<b;j++)
        {
            scanf("%d",&maxmatrix[i][j]);
        }
    }
    printf("\n\nEnter the allocation for every process: ");
    for(i=0;i<a;i++)
    {
        printf("\nAllocation matix ");
        printf("\nP[%d]: ",i+1);
        for(j=0;j<b;j++)
        {
            scanf("%d",&allocmatrix[i][j]);
        }
    }
    printf("\n\nEnter the Available Resources: ");
    for(i=0;i<b;i++)
    {
        scanf("%d",&availmatrix[i]);
    }
}
int main()
{
    count=0;
    printf("Enter the number of processes: ");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        finished[i]=0;
    }
    printf("\n\nEnter the number of resources: ");
    scanf("%d",&b);
    insertdata();
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            needmatrix[i][j]=maxmatrix[i][j]-allocmatrix[i][j];
			do
        {
            printf("\nMax matrix: ");
            printf("Allocation matrix: \n");
            for(i=0;i<a;i++)
            {
                for(j=0;j<b;j++)
                printf("%d",maxmatrix[i][j]);
                printf("\t\t");
                for(j=0;j<b;j++)
                printf("%d",allocmatrix[i][j]);
                printf("\n");
            }
            process=-1;
            for(i=0;i<a;i++)
            {
                if(finished[i]==0)//if the process is not completed 
                {
                    process=i;
                    for(j=0;j<b;j++)
                    {
                        if(availmatrix[j]<needmatrix[i][j])
                        {
                            process=-1;
                            break;
                        }
                    }
                }
                if(process!=-1)
                    break;
            }

            if(process!=-1)
            {
                printf("\nProcess %d runs to completion: ",process+1);
                safeseq[count]=process+1;
                count++;
                for(j=0;j<b;j++)
                {
                    availmatrix[j]+=allocmatrix[process][j];
                    allocmatrix[process][j]=0;
                    maxmatrix[process][j]=0;
                    finished[process]=1;
                }
            }
        }while(count!=a && process!=-1);
        if(count==a)
        {
            printf("\nThe system is in safe state!!!!!\n");
            printf("Safe Sequence: ");
            for( i=0;i<a;i++)
            printf("%d",safeseq[i]);
            printf("\n");
        }
        else
            printf("\nThe system is in unsafe state!!!!!");

}
