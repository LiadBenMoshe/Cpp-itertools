#include<iostream>
#include <functional>
#include"range.hpp"


using namespace std;


namespace itertools{
      struct Sum {
        template<typename W>
        W operator()(W a, W b) const {
            
            return a+b;
        }
    };


template <typename T,typename F=Sum>
class accumulate{
    T contain ;
    F function;
    
   public:
   
   
     
   
   
    accumulate(T con,F func=Sum()):contain(con),function(func){   
    }

   
    
    class iterator{
            typename T::iterator current;
            typename decay<decltype(*(contain.begin()))>::type sum;
             F f1;

             public:
            iterator(){}
            iterator(typename T::iterator temp,decltype(*(contain.begin())) tsum,F f11): current(temp),sum(tsum),f1(f11){//Works
            }

            //dont work
           /* iterator(typename T::iterator temp,decltype(*(contain.begin())) tsum,F f11){
                this->current=temp;
                this->sum=tsum;
                this->f1=f11;
            }
*/
           

             decltype(*contain.begin()) operator*() { return sum; }
             bool operator==( iterator& other)  { return current == other.current; }
             bool operator!=( iterator& other)  { return !(current == other.current); }
             iterator operator++() {
             current++;
             try
             {
                 
                  sum=f1(sum,*current);
             } 
             catch(const std::exception& e)
             {
                 
             }
             
            
             return *this;
             }
            

        };
        
           
            


        iterator begin(){
            
            return iterator(contain.begin(),*contain.begin(),function );
        }
       
        iterator end(){
           
            return iterator(contain.end(),*contain.begin(),function);
        }
   
    


    };


}