// queue and stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>

using namespace std;

struct stack
{
	struct node
	{
		int data;
		node* next;
		node()
		{
		data=0;
		next=0;
		}
	};
	typedef node* nodeptr;
	nodeptr TOP;
	stack()
	{
	TOP=0;
	}
	
	void push(int newData)
	{
	node *ptr=new node;
	ptr->next=TOP;
	TOP=ptr;
	TOP->data=newData;
	}
	int pop()
	{
		int topData;
		if(TOP==NULL)
		{
		return-1;
		}
		else
		{
			topData=TOP->data;
			TOP=TOP->next;
			return topData;
		}
	}
	
	int top()
	{
		if(TOP==NULL)
		{
			return -1;
		}
		else
		{
		return TOP->data;
		}
	}
	bool isempty()
	{
		if(TOP==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

struct queue
{
	struct node
	{
		int data;
		node* next;
		node()
		{
			data=0;
			next=0;
		}
	};
		typedef node* nodeptr;
		nodeptr front,rear;
		queue()
		{
			front=rear=0;
		}

		void enqueue(int n)
		{
			nodeptr ptr=new node;
			ptr->data=n;
			ptr->next=0;
			if(front==0)
			{
				front=ptr;
				rear=ptr;
			}

			else
			{
				rear->next=ptr;
				rear=ptr;
			}
		}

		void dequeue()
		{
			if(front==0)
			return;

			else
			{
				nodeptr ptr=front;
				front=front->next;
				delete ptr;
			}
		}

		int getfront()
		{
			if(front==0)
				return -1;
			else
				return front->data;
		}

		bool empty()
		{
			if(front==0)
				return true;
			else
				return false;
		}
};
int _tmain(int argc, _TCHAR* argv[])
{
	queue Q;
	stack S;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueue(5);


	while(Q.empty()!=true)
	{
		S.push(Q.getfront());
		Q.dequeue();
	}

	while(S.isempty()!=true)
	{
		Q.enqueue(S.top());
		S.pop();
	}

	while(Q.empty()!=true)
	{
		cout<<Q.getfront() <<endl;
		Q.dequeue();
	}

	system("pause");
	return 0;
}

