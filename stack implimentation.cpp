#include <iostream>
#include <cstdlib>
using namespace std;
 

#define SIZE 10
 

class Stack
{
    int *arr;
    int top;
    int capacity;
 
public:
    Stack(int size = SIZE);         
    ~Stack();                       
 
    void push(int);
    int pop();
    int peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
 

Stack::~Stack() {
    delete[] arr;
}
 

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 

int Stack::pop()
{
    
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 
    
    return arr[top--];
}
 

int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 

int Stack::size() {
    return top + 1;
}
 

bool Stack::isEmpty() {
    return top == -1;               
}
 

bool Stack::isFull() {
    return top == capacity - 1;    
}
 
int main()
{
    Stack pt(3);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
 
    pt.pop();
 
    if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
 
    return 0;
}
