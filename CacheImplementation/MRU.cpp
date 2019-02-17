//
//  MRU.cpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include "MRU.hpp"


//Display MEmories
void MRUCache::display(){
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
void MRUCache::inputMemory(){
    std::cout<<"\nEnter into memory"<<std::endl;
    for(int i=0; i<MemorySize; i++){
        std::cout<<i+1<<": ";
        std::cin>>memory[i];
    }
}

//Input number
void MRUCache::input(){
    std::cout<<"\nEnter Element: ";
    std::cin>>number;
}

//LRU main
void MRUCache::LRU(){
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
bool MRUCache::searchMemory(int num){
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            return true;
        }
    }
    return false;
}

//Search the number in Cache
bool MRUCache::searchCache(int num){
    for(int i=0; i<CacheSize; i++){
        if(num == cache[i]){
            counter[i]++;
            return true;
        }
    }
    return false;
}

//Check for overflow
bool MRUCache::overflow(){
    if (head >= CacheSize) {
        return true;
    }
    else{
        return false;
    }
}

//Push Element into Cache
void MRUCache::push(int num){
    cache[head] = num;
    counter[head]++;
    head++;
}

//Pop Element from Cache
void MRUCache::pop(){
    int i;
    for(i=0; i<CacheSize; i++){
        if(counter[i] >= highval){
            highval = counter[i];
            higherindex = i;
        }
    }
    head = higherindex;
    counter[head] = 0;
}

