#include<stdio.h>

int main(){

	int burst[10]={0},arival[10]={0},turnaround[10]={0},waiting[10]={0},complete[10]={0};
	int i,j,k;
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("Enter number of processes	");
	scanf("%d",&n);

	printf("Enter arrival time and burst time for each process\n\n");

	for(i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]	",i+1);
		scanf("%d",&arival[i]);
		
		printf("Burst time of process[%d]	",i+1);
		scanf("%d",&burst[i]);
		
		printf("\n");
	}
    for(j=0;j<n;j++)
	{
		sum+=burst[j];
		complete[j]+=sum;
	}


	for(k=0;k<n;k++)
	{
		turnaround[k]=complete[k]-arival[k];
		totalTAT+=turnaround[k];
	}

	
	for(k=0;k<n;k++)
	{
		waiting[k]=turnaround[k]-burst[k];
		totalWT+=waiting[k];
	}
	
	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for(i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,arival[i],burst[i],complete[i],turnaround[i],waiting[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	
	return 0;
}
