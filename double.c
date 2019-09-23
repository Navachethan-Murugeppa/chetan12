#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int q[MAX];
int r=-1;
int f=-1;
void insert_rear(int data)
{
	if(f==0 && r==MAX-1)
	{
		printf("queue is full\n");
		 return;
	 }
	else if(r==-1 && f==-1)
	{
		q[++r]=data;
		f=0;
	}
	else
		q[++r]=data;
}
void insert_front(int data)
{
	 if(f==-1 && r==-1)
	{
		printf("data cannot be inserted\n");
	}	
	else if((f==0 && r==MAX-1)|| f==0)
	{
		printf("queue if full\n");
		return;
	}
	else if(f!=0 && f<r)
	{
		q[--f]=data;
	}
	else if((f==-1 && r==-1)||(f>r))
	{		
		printf("queue is empty\n");
	}	

}
void deleteq_front()
{
	if((f==-1 && r==-1)||(f>r))
	{
		printf("queue is empty\n");
		f=r=-1;
		return;
	}
	else
		printf("the data deleted is %d\n",q[f]);
		f++;
}
void deleteq_rear()
{
	if((f==-1 && r==-1)||(f>r))
	{
		printf("queue is empty\n");
		f=r=-1;
		return;
	}
	else
		printf("the data deleted is %d\n",q[r]);
		r--;
}
void display()
{
	int i;
	if(f==-1 && r==-1)
	{
		printf("queue is empty\n");
		return;
	}
	else
	{
		for(i=f;i<=r;++i)
		{
				printf("%d\n",q[i]);
		}
	}
}
int main()
{
	int ch,data;
	printf("\n program to insert delete and display elements in a queue\n");
	while(1)
	{
		printf("1.insert_rear\t2.insert_front\t3.delete_front\n4.delete_rear\t5.display\t6.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the number\n");
				scanf("%d",&data);
				insert_rear(data);
				break;
			case 3: printf("deleted data\n");
				deleteq_front();
				break;
			case 5: printf("display the elemnts\n");
				display();
				break;
			case 6:exit(0);
			case 2: printf("enter the number\n");
				scanf("%d",&data);
				insert_front(data);
				break;
			case 4: printf("dleted value\n");
				deleteq_rear();
				break;
			default: printf("wrong choice\n");
				break;
		}
	}
	return 0;
}
