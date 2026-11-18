#include<stdio.h>

typedef struct sjf
{
    int pid,at,bt,tat,wt,ct,rt;
} s;

int main()
{
    int n;

    printf("enter the no of process: ");
    scanf("%d",&n);

    s p[n];

    int i;

    printf("\nenter the AT \t BT\n");

    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        p[i].ct=0;

        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    int timer=0;
    int idle=0;
    int comp=0;

    while(comp<n)
    {
        int index=-1;
        int min=9999;

        for(i=0;i<n;i++)
        {
            if(p[i].ct==0 && p[i].at<=timer)
            {
                if(p[i].bt<min)
                {
                    min=p[i].bt;
                    index=i;
                }
            }
        }

        if(index==-1)
        {
            timer++;
            idle++;
            continue;
        }

        timer+=p[index].bt;

        p[index].ct=timer;
        p[index].tat=p[index].ct-p[index].at;
        p[index].wt=p[index].tat-p[index].bt;

        p[index].rt=p[index].wt;

        comp++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    float totalw=0, totalt=0;

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt,
               p[i].rt);

        totalw+=p[i].wt;
        totalt+=p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f",totalw/n);
    printf("\nAverage TurnAround Time = %.2f\n",totalt/n);

    printf("Idle Time = %d\n",idle);

    return 0;
}
