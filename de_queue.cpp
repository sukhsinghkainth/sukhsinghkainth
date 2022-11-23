#include<iostream>
using namespace std;
# define MAX 5

class dequeue
{
	public:
int a[MAX];
int left = -1;
int right = -1;





void insert_right()
{
	int item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	cout<<"--------queue overflow------"<<endl;
		return;}
	if (left == -1) 
	{	left = 0;
		right = 0;}
	else
	if(right == MAX-1)  
		right = 0;
	else
		right = right+1;
	cout<<"Input the element for adding in queue : "<<endl;
	cin>>item;
	a[right] = item ;
}

void insert_left()
{	int item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	cout<<"--------queue overflow------ "<<endl;
		return;	 }
	if (left == -1)
	{	left = 0;
		right = 0;	 }
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	cout<<"Input the element for adding in queue : "<<endl;
	cin>>item;
	a[left] = item ;	 }

void delete_left()
{	if (left == -1)
	{	cout<<"--------queue underflow------"<<endl;
		return ;	}
	cout<<"Element deleted from queue is "<<a[left]<<endl;
	if(left == right) 
	{	left = -1;
		right=-1;	 }
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
}

void delete_right()
{if (left == -1)
	{cout<<"-----------------queue underflow--------------"<<endl;
		return ;	 }
	cout<<a[right]<<endl;
	if(left == right) 
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;	}

void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	cout<<"Queue is empty"<<endl;
		return;	 }
	cout<<"Queue elements :"<<endl;
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	cout<<a[front_pos]<<"--"<<endl;
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	cout<<a[front_pos]<<"--"<<endl;
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	cout<<a[front_pos]<<"--"<<endl;
			front_pos++;
		}
	}
	
}

void input_que()
{	int choice;

	do
	{	cout<<"1.Insert at right"<<endl;
		cout<<"2.Delete from left"<<endl;
		cout<<"3.Delete from right"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Quit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;

		switch(choice)
		{	case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
            break;
		 default:
			cout<<"Wrong choice"<<endl;
		}
	}while(choice!=5);
}

void output_que()
{	int choice;
	do
	{	cout<<"1.Insert at right"<<endl;
		cout<<"2.Insert at left"<<endl;
		cout<<"3.Delete from left"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Quit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;
		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
			break;
		 default:
			cout<<"Wrong choice"<<endl;
		}
	}while(choice!=5);
}
};

 int main()
{	int choice;
	dequeue q;
	cout<<"1.Input restricted dequeue"<<endl;
	cout<<"2.Output restricted dequeue"<<endl;
	cout<<"Enter your choice : "<<endl;
	cin>>choice;
	switch(choice)
	{
	 case 1 :
		q.input_que();
		break;
	 case 2:
		q.output_que();
		break;
	 default:
		cout<<"Wrong choice"<<endl;
	}
}
