#include <iostream>
#include <exception>
#include <cmath>
using namespace std;

template <class T>
T oper(char symb, T op1, T op2);

int prior(char ch);


class StackEmpty : public exception
{
    public:
        const char* what() const throw()
        {
            return ("StackEmptyException: Stack is empty!");
        }
};

class StackFull : public exception
{
    public:
        const char* what() const throw()
        {
            return ("StackFullException: Stack is full!");
        }
};

template <class T>
class ArrayStack
{
   enum {DEF_CAPACITY = 100};
   
   public :
       ArrayStack(int cap = DEF_CAPACITY)
       {
           arr = new T[cap];
           capacity = cap;
           t = -1;
       }
       
       ~ArrayStack()
       {
           delete[] arr;
           t = -1;
           cout << "Stack is terminated!" << endl;
       }
       
       ArrayStack(const ArrayStack<T> &obj)
       {
            capacity = obj.capacity;
            arr = new T[capacity];
            
            for(int i = 0; i<obj.size(); i++)
            {
                arr[i] = obj.arr[i];
            }
            
            t = obj.t;
       }
       
       void operator =(const ArrayStack<T> &obj)
       {
           arr = obj.arr;
           capacity = obj.capacity;
           t = obj.t;
       }
       
       int size() const;
       bool isEmpty() const;
       const T& top() const;
       void push(const T& e);
       const T& pop();
       void clear();
       void display() const;
       
   private:    
       int capacity;
       T* arr;
       int t;
};

template <class T>
int ArrayStack<T>::size() const
{
   return(t + 1);
}

template <class T>
bool ArrayStack<T>::isEmpty() const
{
    return(t < 0);
}

template <class T>
const T& ArrayStack<T>::top() const
{
    if(isEmpty())
    {
        throw StackEmpty();
    }
    
    return (arr[t]);
}

template <class T>
void ArrayStack<T>::push(const T& e)
{
    if(size() == capacity)
    {
        throw StackFull();
    }
    
    arr[++t] = e;
}

template <class T>
const T& ArrayStack<T>::pop()
{
    if(isEmpty())
    {
        throw StackEmpty();
    }
    
    return(arr[t--]);
}

template <class T>
void ArrayStack<T>::clear()
{
    delete[] arr;
    arr = new T[capacity];
    t = -1;
}

template <class T>
void ArrayStack<T>::display() const
{
    if(isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }
    
    else
    {   
        cout << "Element(s) of the stack are : [ ";
        for(int i = 0; i<size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }
}

template <class T>
T eval(char expr[])
{
    char c;
    int position;
    T opnd1, opnd2, value;
    ArrayStack <T> s;
    
    for(position = 0; (c = expr[position]) != '\0'; position++)
    {
        if(isdigit(c))
        {
            s.push( T(c - '0') );
        }
        
        else
        {
            opnd2 = s.pop();
            opnd1 = s.pop();
            
            value = oper<T>(c,opnd1,opnd2);
            s.push(value);
        }
    }
    return (s.pop());
}

template <class T>
T oper(char symb, T op1, T op2)
{
    switch(symb)
    {
        case '+' : return(op1 + op2);
        
        case '-' : return(op1 - op2);
        
        case '*' : return(op1 * op2);
        
        case '/' : return(op1 / op2);
        
        case '$' : return( pow(op1,op2) );
        
        default : cout << "Illegal operation\n";
                  exit(1);
    }
}

void convert(char expr[], char* postfix)
{
    char c;
    int position;
    int index = 0;

    ArrayStack <char> s;
    
    for(position = 0; (c = expr[position]) != '\0'; position++)
    {
        if(isdigit(c))
        {
            postfix[index] = c;
            index++;
        }
        
        else if(c == '(')
        {
            s.push(c);
        }
        
        else if(c == ')')
        {
            while(s.top() != '(')
            {
                postfix[index] = s.pop();
                index++;
            }
            s.pop();
        }
        
        else
        {
            if(s.isEmpty())
            {
                s.push(c);
            }
            else
            {
                while(!(s.isEmpty()) && (prior(s.top()) >= prior(c)))
                {
                    postfix[index] = s.pop();
                    index++;
                }
                s.push(c);
            }
        }
    }
    
    if(!s.isEmpty())
    {
        while(!s.isEmpty())
        {
            postfix[index] = s.pop();
            index++;
        }
    }
}

int prior(char ch)
{
    switch(ch)
    {
        case '(' : return (1);
        case '+' : return (2);
        case '-' : return (2);
        case '/' : return (3);
        case '*' : return (3);
        case '$' : return (4);
        default : cout << "Illegal character!\n";
                  exit(1);
    }
}

template <class T>
void reverse(ArrayStack<T> &stk, ArrayStack<T> &stk_r)
{
    while(!stk.isEmpty())
    {
        stk_r.push(stk.pop());
    }
}

int main()
{
    const unsigned int size = 100;
    
    cout << "Welcome, User! Create your own Stack :)\n";
    cout << "-----------------------------------------------";
    ArrayStack <int> STACK(size);
    unsigned int SIZE;
    cout << "\nEnter the size of the stack : ";
    cin >> SIZE;
    
    int VAL;
    cout << "Enter the elements (space separated) : ";
    for (int i=0; i<SIZE; i++)
    {
        cin >> VAL;
        STACK.push(VAL);
    }
    
    STACK.display();
    
    unsigned int pop;
    cout << "\nEnter the no. of elements to be popped: ";
    cin >> pop;
    cout << "Element(s) popped: ";
    for(int i = 0; i<pop; i++)
    {
        cout << (STACK.pop()) << " ";
    }
    
    cout << "\n\nYour Stack Info: \n";
    cout << "---------------\n";
    STACK.display();
    cout << "Top element -> " << STACK.top() << endl;
    cout << "Capacity -> " << size << endl;
    cout << "Size -> " << STACK.size() << endl;
    cout << "Data Type -> " << "<int>" << endl;
    
    char ans;
    cout << "\nDo you want to clear your stack? (Y or N): ";
    cin >> ans;
    if(ans == 'Y' || ans == 'y')
    {
        STACK.clear();
        STACK.display();
    }
    cin.ignore();

    char postfix1[size];
    cout << "\n--------------------------------------------------";
    cout << "\nImplementation 1 (Postfix evaluation) : \n";
    cout << "--------------------------------------------------";
    cout << "\nEnter a postfix expression: ";
    cin.getline(postfix1,size);
    
    int result;
    result = eval<int>(postfix1);
    cout << "The Result = " << result << endl << endl;


    char infix[size];
    cout << "--------------------------------------------------";
    cout << "\nImplementation 2 (Infix to Postfix conversion) : \n";
    cout << "--------------------------------------------------";
    cout << "\nEnter an infix expression : ";
    cin.getline(infix,size);
    
    int i = 0;
    int len = 0;
    while(infix[i] != '\0')
    {
        if((infix[i] != '(') && (infix[i] != ')'))
        {
            len++;
        }
        i++;
    }
    
    char postfix2[len];
    convert(infix, postfix2);
    
    cout << "Postfix expression: ";
    for(i = 0; i<len; i++)
    {
        cout << postfix2[i];
    }
    cout << endl << endl;
    
    
    cout << "--------------------------------------------------";
    cout << "\nImplementation 3 (Reverse of a Stack) : \n";
    cout << "--------------------------------------------------";
    ArrayStack <int> stk1;
    int size1;
    cout << "\nEnter the no. of elements in stack : ";
    cin >> size1;
    
    int val;
    cout << "Enter elements (space separated) : ";
    for(int i = 0; i<size1; i++)
    {
        cin >> val;
        stk1.push(val);
    }
    
    ArrayStack <int> stk_temp(stk1);
    
    ArrayStack <int> stk2;
    reverse<int>(stk_temp,stk2);
    
    cout << "\nOriginal Stack->  ";
    stk1.display();
    cout << "Reverse Stack->  ";
    stk2.display();
    
    return 0;
}
