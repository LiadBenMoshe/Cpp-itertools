

namespace itertools{

    
template <typename T,typename F>
class compress{
    T contain ;
    F contain2;

    public:
    compress(T con1, F con2):contain(con1),contain2(con2){   
    }

    class iterator{
            typename T::iterator current;
            typename T::iterator end;
            typename F::iterator current2;
            typename F::iterator end2;
            

            public:
            iterator(){}
            iterator(typename T::iterator temp,typename T::iterator end1,typename F::iterator temp2,typename F::iterator end3):
            current(temp),end(end1),current2(temp2),end2(end3){//Works
           while(!(*current2) && current!=end && current2!=end2){
                current++;
                current2++;
             }
                


            }
            
             decltype(*contain.begin()) operator*() {  return *current;}
             bool operator==( iterator& other)  { return current == other.current; }
             bool operator!=( iterator& other)  { return !(current == other.current); }
             iterator operator++() {
             current++; 
             current2++;   
             while(!(*current2) && current!=end && current2!=end2){
                current++;
                current2++;
             }
                 
             
             
             return *this;
            }



            

    };

    iterator begin(){
            
        return iterator(contain.begin(),contain.end(),contain2.begin(),contain2.end());
    }
       
    iterator end(){
           
        return iterator(contain.end(),contain.end(),contain2.end(),contain2.end());
    }
 
 };


}