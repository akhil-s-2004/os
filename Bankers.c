#include<stdio.h>
#include<stdbool.h>
int m,n;
int ss[20],avail[20],max[20][20],alloc[20][20],need[20][20]; bool finish[20];
void c_need()
{
   int i,j;
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
         need[i][j]=max[i][j]-alloc[i][j];
      }
   }
}
bool safe()
{
   int work[20];
   int i,j,k;
   for(i=0;i<n;i++)
   {
      work[i]=avail[i];
   }
   for(j=0;j<m;j++)
   {
      finish[j]=false;
   }
   int count=0;
   while(count<m)
   {
      bool found=false;
      for(i=0;i<m;i++)
      {
         if(!finish[i])
         {
            bool can_allocate=true;
            for(j=0;j<n;j++)
            {
               if(need[i][j]>work[j])
               {
                  can_allocate=false;
                  break;
               }
            }
            if(can_allocate)
            {
               for(k=0;k<n;k++)
               {
                  work[k]+=alloc[i][k];
               }
               finish[i]=true;
               ss[count++]=i;
               found=true;
            }
         }
      }
      if(!found)
      {
         return false;
      }
   }
   return true;
}
void main()
{
   int i,j;
   printf("Enter number of processes: ");
   scanf("%d",&m);
   printf("Enter number of resources: ");
   scanf("%d",&n);
   printf("Enter allocation matrix for %d process and %d resources ",m,n);
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%d",&alloc[i][j]);
      }
   }
   printf("Enter maximum matrix for %d process and %d resources ",m,n);
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%d",&max[i][j]);
      }
   }
   printf("Enter the available resources: ");
   for(i=0;i<n;i++)
   {
      scanf("%d",&avail[i]);
   }
   c_need();
   if(safe())
   {
      printf("Safe!!!\n");
      for(i=0;i<m;i++)
      {
         printf("%d--",ss[i]);
      }
      printf("\n");
   }
   else
   {
      printf("UNsafe!!!\n");
   }
}
