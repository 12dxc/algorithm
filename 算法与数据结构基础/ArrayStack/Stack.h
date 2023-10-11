#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack
{
public:
    virtual int size() = 0;
    virtual int capacity() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};

#endif
