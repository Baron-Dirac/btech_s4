/*
BANKERS ALGORITHM
Author: Hisham Munna
RollNO: 31
*/
#include<stdio.h>
void main()
{
	int p,n,i,j,m,alloc[30][30],avail[30],count=0,c=0,flag=0,max[30][30],need[30][30],finish[30],req[30],w[30],f;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	printf("Enter the resource types\n");
	scanf("%d",&m);
	printf("Allocation matrix\n");
	for(i=0;i<n;i++)
	{
		finish[i]=0;
		printf("Process %d",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Max matrix\n");
	for(i=0;i<n;i++)
	{
		printf("Process %d",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Available!....\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&avail[j]);
	}
	printf("Need matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("The resource allocation table....\n");
	printf("process\tallocation\tmax\tneed\tavailable\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t",i);
		for(j=0;j<m;j++)
		{
			printf("%d",alloc[i][j]);
		}
		printf("\t\t");
		for(j=0;j<m;j++)
		{
			printf("%d",max[i][j]);
		}
		printf("\t\t");
		for(j=0;j<m;j++)
		{
			printf("%d",need[i][j]);
		}
		printf("\t\t");
		if(i==0)
		{
			for(j=0;j<m;j++)
			{
				printf("%d",avail[j]);
			}
		}
		printf("\n");
	}
	printf("Enter the request process number\n");
	scanf("%d",&p);
	printf("Enter the request sequence\n");
	for(j=0;j<m;j++)
	{
		scanf("%d",&req[j]);
	}
	for(i=0;i<m;i++)
	{
		flag=0;
		if(req[i]>need[p][i] || req[i]>avail[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Request granted\n");
		for(j=0;j<m;j++)
		{
			alloc[p][j]=alloc[p][j]+req[j];
			avail[j]=avail[j]-req[j];
			need[p][j]=need[p][j]-req[j];
		}
		printf("The modified resource allocation table\n");
		printf("process\tallocation\tmax\tneed\tavailable\n");
		for(i=0;i<n;i++)
		{
			printf("p%d\t",i);
			for(j=0;j<m;j++)
			{
				printf("%d",alloc[i][j]);
			}
			printf("\t\t");
			for(j=0;j<m;j++)
			{
				printf("%d",max[i][j]);
			}
			printf("\t\t");
			for(j=0;j<m;j++)
			{
				printf("%d",need[i][j]);
			}
			printf("\t\t");
			if(i==0)
			{
				for(j=0;j<m;j++)
				{
					printf("%d",alloc[i][j]);
				}
			}
			printf("\n");
		}
		c=0;
		flag=0;
		while(count<n)
		{
		
			f=0;
			for(i=0;i<n;i++)
			{
				flag=0;
				if(finish[i]==0)
				{
					for(j=0;j<m;j++)
					{
						if(need[i][j]>=avail[j])
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						w[c]=i;
						c++;
						finish[i]=1;
						count++;
						for(j=0;j<m;j++)
						{
							avail[j]=avail[j]+alloc[i][j];
						}
						f=1;
					}
				}
			}
			if(f==0)
			{
				printf("Deadlock occurs\n");
				break;
			}
		}
		if(count==n)
			{
				printf("Safe sequence\n");
				printf("p%d",w[0]);
				for(i=1;i<n;i++)
				{
					printf("-->p%d",w[i]);
				}
			}
	}
	else
	{
		printf("Request not granted\n");
	}
}
/*OUTPUT
Enter the number of process 
Enter the resource types 
Allocation matrix 
Process 0Process 1Process 2Process 3Process 4Max matrix
Process 0Process 1Process 2Process 3Process 4Available!....
Need matrix
The resource allocation table....
process	allocation	max	need	available
p0	010		753	743	101010
p1	200		322	122		
p2	302		902	600		
p3	211		222	011		
p4	002		433	431		
Enter the request process number
Enter the request sequence
Request granted
The modified resource allocation table
process	allocation	max	need	available
p0	111		753	642	111
p1	200		322	122		
p2	302		902	600		
p3	211		222	011		
p4	002		433	431		
Safe sequence
p0-->p1-->p2-->p3-->p4
*/











