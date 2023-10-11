template <class T>
class Queue
{
public:
    virtual int size() = 0;
    virtual int capacity() = 0;
    virtual bool isEmpty() = 0;
    virtual void enqueue(T e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
};
