#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int qf(int count)
{
	return(count==MAX)? 1:0;
}
int qe(int count)
{
	return(count==0)? 1:0;
}
void rear_insert(int num, int q[], int *r, int *count)
{
	if(qf(*count))
	{
		printf("\n queue is overflown\n");
		return;
	}
	*r=(*r+1)%MAX;
	q[*r]=num;
	*count+=1;
}
void front_delete(int q[], int *f, int *count)
{
	if(qe(*count))
	{
		printf("\n queue is underflown\n");
		return;
	}
	printf("\n the deleted value if %d\n",q[*f]);
	*f=(*f+1)%MAX;
	*count-=1;
}
void display(int q[], int f, int count)
{
	int i,j;
	if(qe(count))
	{
		printf("queue is empty\n");
		return;
	}
	printf("The contents of the queue are:\n");
	i=f;
	for(j=1;j<=count;j++)
	{
		printf("%d\n",q[i]);
		i=(i+1)%MAX;
	}
	printf("\n");
}
int main()
{
	int choice,num,count,f,r,q[20];
	f=0;
	r=-1;
	count=0;
	printf("\n program to insert delete and display elements in a circular queue\n");
	for(;;)
	{
		printf("1.insert\t2.delete\t3.display\t4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the number\n");
				scanf("%d",&num);
				rear_insert(num,q,&r,&count);
				break;
			case 2: printf("deleted data\n");
				front_delete(q,&f,&count);
				break;
			case 3: printf("display the elemnts\n");
				display(q,f,count);
				break;
			case 4:exit(0);
			default: printf("wrong choice\n");
				break;
		}
	}
	return 0;
}
