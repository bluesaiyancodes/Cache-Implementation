//
//  LRU.hpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#ifndef LRU_hpp
#define LRU_hpp

#include <iostream>

class LRUCache{
private:
    int *cache;
    int *memory;
    int *counter;
    int lc = 100, lowerindex;
    int number, MemorySize, CacheSize, head;
public:
    LRUCache(){
        std::cout<<"\nEnter the size of LRU memory: ";
        std::cin>>MemorySize;
        std::cout<<"Enter the size of cache: ";
        std::cin>>CacheSize;
        
        head = 0;
        memory = new int[MemorySize];
        cache = new int[CacheSize];
        counter = new int[CacheSize];
        
        for(int i=0; i<CacheSize; i++){
            cache[i] = 0;
            counter[i] = 0;
        }
    }
    void inputMemory();
    void input();
    void display();
    void LRU();
    bool searchMemory(int );
    bool searchCache(int );
    bool overflow();
    void push(int );
    void pop();
    
    
};

#endif /* LRU_hpp */



