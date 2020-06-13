/*

AUTHORS: Liad Ben Moshe


*/
#pragma once
#include<iostream>
#include<vector>


using namespace std;

namespace itertools{
    
    class range{   
        int start;
        int finish;
        public:
        range(){}

        range(int start1,int end1){
            start=start1;
            finish=end1;
        }
        range(int end1){
            start=0;
            finish=end1;
        }

        class iterator{
            int current;
            public:
            iterator(int num){
                current=num;
            }
             int operator*() { return current; }
             iterator& operator=(iterator& other){
                 return other;
             }
      
             bool operator==( iterator other)  { return current == other.current; }
             bool operator!=( iterator other)  { return !(current == other.current); }
             iterator& operator++() {
			 current++;
             return *this;
		    }
            iterator& operator++(int) {
			++current;
             return *this;
		    }

        };
        iterator begin() const{
        
           return iterator(start);
        }
        iterator end() const{
           return iterator(finish);
        }



};



}







