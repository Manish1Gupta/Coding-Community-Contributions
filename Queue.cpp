#include <bits/stdc++.h>  
using namespace std;


int q[100];   
int front=-1;  
int rear=-1;  

void insert(int n)  
{  
    if(front==-1 && rear==-1)     
    {  
        front=0;  
        rear=0;  
        q[rear]=n;  
    }  
    else if((rear+1)%100==front)    
    {  
        cout<<"queue overflow";  
    }  
    else  
    {  
        rear=(rear+1)%100;         
        q[rear]=n;       
    }  
}  

int del()  
{  
    if((front==-1) && (rear==-1))   
    {  
        cout<<"\nQueue underflow";  
    }  
    else if(front==rear)  
    {  
         cout<<"\nthe element deleted is "<<q[front]<<"\n";  
         front=-1;  
         rear=-1;  
    }   
    else  
    {  
         cout<<"\nthe element deleted is "<<q[front]<<"\n";  
         front=(front+1)%100;  
    }  
}  
  
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        cout<<"\nqueue is empty";  
    }  
    else  
    {  
          
        while(i<=rear)  
        {  
            cout<<q[i]<<" ";  
            i=(i+1)%100;  
        }  
    } 
    printf("\n");
}  
int main()  
{  
    int ch=1,n;     
      
    while(ch!=0)     
    {  
    cout<<"\n1: Insert | 2: Delete | 3: Display\n ";
    cin>>ch;  
      
    switch(ch)  
    {  
          
        case 1:  cout<<"\nEnter the element which is to be inserted:-";  
                 cin>>n;  
                 insert(n);  
                 break;  
        case 2:  del(); 
                 break;
        case 3:  display();
                 break;
        default: cout<<"\nEnter the correct choice";
                 ch =1;
                 break;
  
    }
}  
    return 0;  
}