#include <stdio.h>
int n;

struct process
{
   int pid;
   int at;
   int bt;
   int priority;
   int rst;
   int cplt;
   int tat;
   int wt;
}p[20];

void display(struct process t[])
{
   int i,avgrs=0,avgtat=0,avgwt=0;
   printf("\n|\tpid\t|arrivaltime\t|burst time\t|response time\t|completion time|\tturn\t|wait time\n");
   for(i=0;i<n;i++)
   {
      printf("|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",t[i].pid,t[i].at,t[i].bt,t[i].rst,t[i].cplt,t[i].tat,t[i].wt);
      avgrs+=t[i].rst;
      avgtat+=t[i].tat;
      avgwt+=t[i].wt;
   }
   printf("AVG RESPONSE TIME = %.2f\n",(float)avgrs/n);
   printf("AVG WAIT TIME = %.2f\n",(float)avgwt/n);
   printf("AVG TAT TIME = %.2f\n",(float)avgtat/n);
}

void FCFS()
{
   int i,j,systime=0;
   struct process temp,pr[n];

   for(i=0;i<n;i++)
   {
      pr[i]=p[i];
      pr[i].rst=systime-p[i].at;
      pr[i].cplt=systime+pr[i].bt;
      pr[i].tat=pr[i].cplt-pr[i].at;
      pr[i].wt=pr[i].tat-pr[i].bt;
      systime+=p[i].bt;
   }
   printf("\t\tFCFS\n");
   display(pr);
}


void SJF()
{
   struct process temp,psjf[n];
   int i,j,systime=0;
   for(i=0;i<n;i++)
   {
      psjf[i]=p[i];
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(psjf[j].bt>psjf[j+1].bt && psjf[j].at!=0)
         {
            temp=psjf[j];
            psjf[j]=psjf[j+1];
            psjf[j+1]=temp;
         }
      }
   }
   for(i=0;i<n;i++)
   {
      psjf[i].rst=systime-psjf[i].at;
      psjf[i].cplt=systime+psjf[i].bt;
      psjf[i].tat=psjf[i].cplt-psjf[i].at;
      psjf[i].wt=psjf[i].tat-psjf[i].bt;
      systime+=psjf[i].bt;
   }

   printf("\t\tSJF\n");
   display(psjf);
}

void priority()
{
   int i,j,systime=0;
   struct process temp,prio[n];
   for(i=0;i<n;i++)
   {
      prio[i]=p[i];
   }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (prio[j].at > prio[j + 1].at || (prio[j].at == 0 && prio[j + 1].at != 0))
            {
                temp = prio[j];
                prio[j] = prio[j + 1];
                prio[j + 1] = temp;
            }
        }
    }

    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (prio[j].at != 0 && prio[j].priority > prio[j + 1].priority)
            {
                temp = prio[j];
                prio[j] = prio[j + 1];
                prio[j + 1] = temp;
            }
        }
    }

    
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (prio[i].priority == prio[j].priority && prio[i].at > prio[j].at)
            {
                temp = prio[i];
                prio[i] = prio[j];
                prio[j] = temp;
            }
        }
    }
   for(i=0;i<n;i++)
   {
      if (systime < prio[i].at)
      {
         systime = prio[i].at;
      }
      prio[i].rst=systime-prio[i].at;
      prio[i].cplt=systime+prio[i].bt;
      prio[i].tat=prio[i].cplt-prio[i].at;
      prio[i].wt=prio[i].tat-prio[i].bt;

      systime+=prio[i].bt;
   }
   printf("\t\tPRIORITY\n");
   display(prio);
}

void roundRobin(int quantum)
{
    int i, systime = 0, remaining = n;
    struct process rrobin[n];
    int remaining_burst[n];

    for (i = 0; i < n; i++)
    {
        rrobin[i] = p[i];
        remaining_burst[i] = rrobin[i].bt;
        rrobin[i].rst = -1;
    }
    while (remaining > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (remaining_burst[i] > 0)
            {
                if (rrobin[i].rst == -1)
                    rrobin[i].rst = systime - rrobin[i].at;

                if (remaining_burst[i] > quantum)
                {
                    systime += quantum;
                    remaining_burst[i] -= quantum;
                }
                else
                {
                    systime += remaining_burst[i];
                    rrobin[i].cplt = systime;
                    rrobin[i].tat = rrobin[i].cplt - rrobin[i].at;
                    rrobin[i].wt = rrobin[i].tat - p[i].bt;
                    remaining--;
                    remaining_burst[i] = 0;
                }
            }
        }
    }
    printf("\t\tROUNDROBIN\n");
    display(rrobin);
}

int main(void)
{
   int i,q;
   printf("Enter how many processes : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("Enter the pid,arivaltime,burst time,priority : ");
      scanf("%d%d%d%d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].priority);
   }
   printf("Enter time slice : ");
   scanf("%d",&q);
   FCFS();
   SJF();
   priority();
   roundRobin(q);
}
