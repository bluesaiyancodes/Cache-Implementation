//
//  FIFO.cpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include "FIFO.hpp"

//Display Memories
void FIFOCache::display(){
    std::cout<<"\nMemory : ";
    for(int i=0; i<MemorySize; i++){
        std::cout<<memory[i]<<" ";
    }
    std::cout<<"\nCache : ";
    for(int i=0; i<CacheSize; i++){
        std::cout<<cache[i]<<" ";
    }
}

//Input into Memory
void FIFOCache::inputarray(){
    std::cout<<"\nEnter into memory"<<std::endl;
    for(int i=0; i<MemorySize; i++){
        std::cout<<i+1<<": ";
        std::cin>>memory[i];
    }
}

//Input the number
void FIFOCache::input(){
    std::cout<<"\nEnter Element: ";
    std::cin>>number;
}

//Fifo main
void FIFOCache::fifo(){
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
        setindex();
        push(number);
    }
}

//Search Memory
bool FIFOCache::searchMemory(int num){
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            return true;
        }
    }
    return false;
}

//Search Cache
bool FIFOCache::searchCache(int num){
    for(int i=0; i<CacheSize; i++){
        if(num == cache[i]){
            return true;
        }
    }
    return false;
}

//Checks Overflow
bool FIFOCache::overflow(){
    if (point >= CacheSize) {
        return true;
    }
    else{
        return false;
    }
}

//Push
void FIFOCache::push(int num){
    int locMemory = getlocMemory(number);
    cache[point++] = memory[locMemory];
}

//Get the location of the element to insert into array
int FIFOCache::getlocMemory(int num){
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            return i;
        }
    }
    return 0;
}

//Pop
void FIFOCache::setindex(){
    point = 0;
}
