// Heap class
#include"HeapADT.h"

template <typename E>
class Heap : public HeapADT<E>
{
    E* content;          // Pointer to the heap array
    int maxsize;         // Maximum size of the content
    int n;               // Number of elements now in the heap
    void heapfy(int pos)
    {
        int heap;
        if(content[pos]<content[this->left(pos)] || content[pos]<content[this->righ(pos)])
        {
            if(content[pos]<content[this->left(pos)] && content[this->left(pos)] > content[this->righ(pos)] )
            {
                swap(content[pos],content[this->left(pos)]);
                heap=this->left(pos);
            }
            if(content[pos]<content[this->righ(pos)] && content[this->left(pos)] < content[this->righ(pos)])
            {
                swap(content[pos], content[this->righ(pos)]);
                heap=this->righ(pos);
            }
            heapfy(heap);
        }
    }

public:
    void heapfy2(int pos)
    {
        heapfy(pos);
    }
    int get(int pos)
    {
        return content[pos];
    }

    Heap()
    {
        content=new E[20];
        maxsize=20;
        n=0;
    }

    void swap(int &prev, int &next)
    {
        prev+=next;
        next=prev-next;
        prev-=next;
    }

    int size() const
    {
        return n;
    }
    bool isLeaf(int pos) const
    {
        if(pos*2>n || pos*2+1>n)
        {
            return true;
        }
        return false;
    }
    int left(int pos) const
    {
        return pos*2;
    }
    int righ(int pos) const
    {
        return pos*2+1;
    }
    int parent(int pos) const
    {
        return pos/2;
    }
    void buildMaxHeap()
    {
        for(int i=this->parent(n);i > 0; i=this->parent(i))
        {
            heapfy(i);
        }
    }

    virtual void insert(const E& it)
    {
        if(n+1>maxsize)
        {
            content=(E *) realloc(content, 2*maxsize*sizeof(E));
            maxsize*=2;
        }
        n++;
        content[n]=it;
        this->buildMaxHeap();
    }

    E removefirst()
    {
        int Delete;
        swap(content[1],content[n]);
        Delete=content[n];
        content[n]=0;
        n--;
        heapfy(1);
        return Delete;
    }

    E remove(int pos)
    {
        int Delete;
        swap(content[pos],content[n]);
        Delete=content[n];
        content[n]=0;
        n--;
        heapfy(pos);
        return Delete;
    }
};
