#include<iostream>

using namespace std;


namespace itertools{
  


template <typename T,typename F>
class filterfalse{
    T contain ;
    F function;

    public:
    filterfalse(F func, T con):contain(con),function(func){   
    }

    class iterator{
            typename T::iterator current;
            typename T::iterator end;
            F f1;

            public:
            iterator(){}
            iterator(typename T::iterator temp,typename T::iterator end1 ,F f11):
            current(temp),end(end1),f1(f11){//Works
            while(f1(*current)&& current!=end){
                current++;
            }


            }
            
             decltype(*contain.begin()) operator*() {  return *current;}
             bool operator==( iterator& other)  { return current == other.current; }
             bool operator!=( iterator& other)  { return !(current == other.current); }
             iterator operator++() {
             current++;    
             while(f1(*current) && current!=end)
                current++;
                 
             
             
             return *this;
            }



            

    };

    iterator begin(){
            
        return iterator(contain.begin(),contain.end(),function);
    }
       
    iterator end(){
           
        return iterator(contain.end(),contain.end(),function);
    }
 
 };


}