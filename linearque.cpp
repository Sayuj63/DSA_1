#include<iostream>
using namespace std;
const int MAX=5;
int que[MAX], front=-1, rear=-1;
void insert(int que[], int val);
int del(int que[]);
int peek(int que[]);
void display(int que[]);
int main()
{
    int val, option;
    do
    {
        cout<<"\n *****MAIN MENU*****";
        cout<<"\n 1. INSERT";
        cout<<"\n 2. DELETE";
        cout<<"\n 3. PEEK";
        cout<<"\n 4. DISPLAY";
        cout<<"\n 5. EXIT";
        cout<<"\n Enter your option: ";
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"\n Enter the number to be inserted in queue: ";
                cin>>val;
                insert(que, val);
                break;
            case 2:
                val=del(que);
                if(val!=-1)
                    cout<<"\n The value deleted from queue is: "<<val;
                break;
            case 3:
                val=peek(que);
                if(val!=-1)
                    cout<<"\n The value at front of queue is: "<<val;
                break;
            case 4:
                display(que);
                break;
        }
    }while(option!=5);
    return 0;
}
void insert(int que[], int val)
{
    if(rear==MAX-1)
    {
        cout<<"\n QUEUE OVERFLOW";
    }
    else
    {
        if(front==-1)
            front=0;
        rear++;
        que[rear]=val;
    }
}
int del(int que[])
{
    int val;
    if(front==-1 || front>rear)
    {
        cout<<"\n QUEUE UNDERFLOW";
        return -1;
    }
    else
    {
        val=que[front];
        front++;
        if(front>rear)
        {
            front=rear=-1;
        }
        return val;
    }
}
void display(int que[])
{
    if(front==-1)
        cout<<"\n QUEUE IS EMPTY";
    else
    {
        for(int i=front; i<=rear; i++)
            cout<<"\n"<<que[i];
        cout<<"\n";
    }
}
int peek(int que[])
{
    if(front==-1)
    {
        cout<<"\n QUEUE IS EMPTY";
        return -1;
    }
    else
        return (que[front]);
}