//
//  FIFO.hpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#ifndef FIFO_hpp
#define FIFO_hpp

#include <iostream>
class FIFOCache{
private:
    int *cache;
    int *memory;
    int point, number;
    int MemorySize, CacheSize;
public:
    FIFOCache(){
        std::cout<<"\nEnter the size of FIFO memory: ";
        std::cin>>MemorySize;
        std::cout<<"Enter the size of cache: ";
        std::cin>>CacheSize;
        
        memory = new int[MemorySize];
        cache = new int[CacheSize];
        point = 0;
        
        for(int i=0; i<CacheSize; i++){
            cache[i] = 0;
        }
    }
    void inputarray();
    void input();
    void fifo();
    void display();
    void push(int );
    int getlocMemory(int );
    void setindex();
    bool searchMemory(int );
    bool searchCache(int );
    bool overflow();
};
#endif /* FIFO_hpp */
