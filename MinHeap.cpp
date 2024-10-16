#include <iostream>
using namespace std;

#define MAX 1000
#define leftChild(x) 2*x+1
#define rightChild(x) 2*x+2
#define parent(x) x/2

class Heap{
  private:
  
  int minHeap[MAX] = {0xFFFF};
  int lastInd = -1;
  
  public:
  Heap()
  {
      for(int ind=0;ind<MAX;ind++)
        minHeap[ind]=0xFFFF;
  }
  int getSize()
  {
      return lastInd+1;
  }
  bool isEmpty()
  {
      return getSize()==0;
  }
  bool isFull()
  {
      return getSize()==MAX;
  }

  void SiftUp(int ind)
  {
      while(ind && minHeap[parent(ind)]>minHeap[ind])
      {
          swap(minHeap[parent(ind)],minHeap[ind]);
          ind  = parent(ind);
      }
  }
  
  void SiftDown(int ind)//or heapify
  {
      while(leftChild(ind) <= lastInd && rightChild(ind) <= lastInd && 
      minHeap[leftChild(ind)]< minHeap[ind] && minHeap[rightChild(ind)]< minHeap[ind])
      {
          if(minHeap[leftChild(ind)] < minHeap[rightChild(ind)])
          {
              swap(minHeap[leftChild(ind)],minHeap[ind]);
              ind = leftChild(ind);
          }
          else
          {
              swap(minHeap[rightChild(ind)],minHeap[ind]);
              ind = rightChild(ind);
          }
      }
      
      
  }
  
  void add(int val)
  {
    if(isFull())
    {
      cout<<"\nRemove first.";
      return;
    }
    
    minHeap[++lastInd] = val;
    SiftUp(lastInd);//will correct the orientation.
  }
  
  void remove(int ind)
  {
      
      if(ind>0 && ind<MAX && !isEmpty())
      {
          cout<<"\nremoving "<<minHeap[ind];
          minHeap[ind]=minHeap[lastInd--];
          //print();
          SiftDown(ind);
      }
      
  }
  
  void print()
  {
      cout<<"\nsize: "<<getSize()<<"\n";
      for(int ind = 0;ind<=lastInd;ind++)
      {
          
          cout<<minHeap[ind]<<" ";
      }
  }
};


int main()
{
    Heap obj;
    
    obj.add(20);
    obj.add(200);
    obj.add(9);
    obj.add(220);
    obj.add(22);
    obj.add(90);
    obj.add(203);
    obj.add(0);
    obj.add(1);
    
    obj.print();
    obj.remove(1);
    obj.print();
    
    
    return 0;
}