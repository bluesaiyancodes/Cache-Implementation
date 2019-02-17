//
//  LRU.cpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include "LRU.hpp"

//Display MEmories
void LRUCache::display(){
    std::cout<<"\nMemory : ";
    for(int i=0; i<MemorySize; i++){
        std::cout<<memory[i]<<" ";
    }
    std::cout<<"\nCache : ";
    for(int i=0; i<CacheSize; i++){
        std::cout<<cache[i]<<" ";
    }
    std::cout<<"\nCache Counter : ";
    for(int i=0; i<CacheSize; i++){
        std::cout<<counter[i]<<" ";
    }
}

//INput into Memory
void LRUCache::inputMemory(){
    std::cout<<"\nEnter into memory"<<std::endl;
    for(int i=0; i<MemorySize; i++){
        std::cout<<i+1<<": ";
        std::cin>>memory[i];
    }
}

//Input number
void LRUCache::input(){
    std::cout<<"\nEnter Element: ";
    std::cin>>number;
}

//LRU main
void LRUCache::LRU(){
    if(!searchMemory(number)){
        std::cout<<"\nElement not present in memory";
        return;
    }
    if(searchCache(number)){
        std::cout<<"\nHit Occured";
        return;
    }
    
    if(!overflow()){
        push(number);
    }
    else{
        pop();
        push(number);
    }
}

//Search the number in Memory
bool LRUCache::searchMemory(int num){
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            return true;
        }
    }
    return false;
}

//Search the number in Cache
bool LRUCache::searchCache(int num){
    for(int i=0; i<CacheSize; i++){
        if(num == cache[i]){
            counter[i]++;
            return true;
        }
    }
    return false;
}

//Check for overflow
bool LRUCache::overflow(){
    if (head >= CacheSize) {
        return true;
    }
    else{
        return false;
    }
}

//Push Element into Cache
void LRUCache::push(int num){
    cache[head] = num;
    counter[head]++;
    head++;
}

//Pop Element from Cache
void LRUCache::pop(){
    int i;
    for(i=0; i<CacheSize; i++){
        if(counter[i] <= lc){
            lc = counter[i];
            lowerindex = i;
        }
    }
    head = lowerindex;
    counter[head] = 0;
}

