//
//  LIFO.hpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#ifndef LIFO_hpp
#define LIFO_hpp

#include <stdio.h>
#include <iostream>

class LIFOCache{
private:
    int *cache, CacheSize;
    int *memory, MemorySize;
    int top, number;
    bool flag;
public:
    LIFOCache(){
        std::cout<<"\nEnter the size of LIFOmemory: ";
        std::cin>>MemorySize;
        std::cout<<"Enter the size of cache: ";
        std::cin>>CacheSize;
        
        memory = new int[MemorySize];
        cache = new int[CacheSize];
        top = 0;
        
        for(int i=0; i<CacheSize; i++){
            cache[i] = 0;
        }
    }
    
    void input();
    void lifo();
    void push(int );
    void pop();
    void display();
    void inputMemory();
    bool searchMemory(int );
    bool searchCache(int );
    bool Overflow();
    int getlocMemory(int );
};


#endif /* LIFO_hpp */
