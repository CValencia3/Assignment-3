#include <iostream>

using namespace std;

template <class T>
class GenStack
{
    public:
        GenStack(); //constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor

        void push(T d);
        T pop();
        T peak(); //aka top()

        bool isFull();
        bool isEmpty();

        int size;
        int top;

        T *myArray; //pointer to array
};

template <class T>
GenStack<T>::GenStack() //default constructor
{
    //initialization of default values
    myArray = new T[128];
    size = 128;
    top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize) //overloaded constructor
{
    myArray = new T[maxSize]; //on the heap. We need to deallocate
    size = maxSize;
    top = -1; // empty GenStack
}

template <class T>
GenStack<T>::~GenStack()
{
    delete[] myArray;
}

template <class T>
void GenStack<T>::push(T d)
{
        //need to check error/boundary check
        if(isFull())
        {
            throw out_of_range("The GenStack is full.");
        }
        myArray[++top] = d;
}

template <class T>
T GenStack<T>::pop()
{
    if(isEmpty())
    {
        throw out_of_range("The GenStack is empty.");
    }
    return myArray[top--];
}

template <class T>
T GenStack<T>::peak()
{
    if(isEmpty())
    {
        throw out_of_range("The GenStack is empty.");
    }
    return myArray[top];
}

template <class T>
bool GenStack<T>::isFull()
{
    return(top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
    return(top == -1);
};
