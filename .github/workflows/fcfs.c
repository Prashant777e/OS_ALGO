#include<stdio.h>

typedef struct process
{
	int pid,at,bt,ct,tat,wt,rt;
}tf;

int main()
{
	int n;
	printf("enter the no of processes: ");
	scanf("%d",&n);
	
	tf p[n];
	
	printf("\nenter AT \t BT \n");
	
	int i;
	for ( i=0;i<n;i++)
	{
		p[i].pid=i+1;
		
		scanf("%d%d",&p[i].at,&p[i].bt);
	}
	
	int j;
	// sort the process based on the arrival time
	for (i=0;i<n;i++)
	{
		for ( j=i+1;j<n;j++)
		{
			if (p[i].at > p[j].at)
			{
				tf temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	
	int timer=0;
	int idle=0;
	int sumw=0;
	int sumt=0;
	
	
	for ( i=0;i<n;i++)
	{
		//time is less than the arrival time    ==(timer=arrival time)   and   idle==arrival time)
		if (timer <p[i].at)
		{
			idle+=p[i].at-timer;
			timer=p[i].at;
		 } 
		 p[i].rt=timer-p[i].at;
		 
		 timer+=p[i].bt;
		 p[i].ct=timer;
		 p[i].tat=p[i].ct-p[i].at;
		 p[i].wt=p[i].tat-p[i].bt;
		 
		 sumt+=p[i].tat;
		 sumw+=p[i].wt;
	}
	
	
	float avgtat=(float)sumt/n;
	float avgwt=(float)sumw/n;
	
	float cpu=((float)(timer-idle)/timer)*100;
	float throughput=(float)n/timer;
	
	
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	
	
	for( i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		p[i].pid,
		p[i].at,
		p[i].bt,
		p[i].ct,
		p[i].tat,
		p[i].wt,
		p[i].rt);
	}
	
	printf("\nAverage TAT = %.2f",avgtat);
	printf("\nAverage WT = %.2f",avgwt);
	printf("\nIdle Time = %d",idle);
	printf("\nCPU Utilization = %.2f%%",cpu);
	printf("\nThroughput = %.2f",throughput);
	
	return 0;
}
