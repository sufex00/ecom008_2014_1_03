#include <qdebug.h>
#include "Heap.h"

int main()
{
    Heap<int> heap=Heap <int> ();
    heap.insert(1);
    heap.insert(3);
    heap.insert(7);
    heap.insert(4);
    heap.insert(5);
    heap.insert(15);
    heap.remove(2);
    for(int i=1; i<=heap.size(); i++)
    {
        qDebug()<<heap.get(i);
    }

}
