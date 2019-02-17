//
//  LIFO.cpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include "LIFO.hpp"




//Display Cache
void LIFOCache::display(){
    std::cout<<"\nMemory : ";
    for(int i=0; i<MemorySize; i++){
        std::cout<<memory[i]<<" ";
    }
    std::cout<<"\nCache : ";
    for(int i=0; i<CacheSize; i++){
        std::cout<<cache[i]<<" ";
    }
}

//Input into memory
void LIFOCache::inputMemory(){
    std::cout<<"\nInput into Memory"<<std::endl;
    for(int i=0; i<MemorySize; i++){
        std::cout<<i+1<<": ";
        std::cin>>memory[i];
    }
}

//Input Number
void LIFOCache::input(){
    std::cout<<"\nEnter Number: ";
    std::cin>>number;
}

//Lifo Main
void LIFOCache::lifo(){
    if(!searchMemory(number)){
        std::cout<<"\nNumber not found in memory";
        return;
    }
    if(searchCache(number)){
        std::cout<<"\nHit Occured";
        return;
    }
    
    if(!Overflow()){
        push(number);
    }
    else{
        pop();
        push(number);
    }
}

//Search the momery for the number
bool LIFOCache::searchMemory(int num){
    flag = false;
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            flag = true;
        }
    }
    return flag;
}

//Search Cache
bool LIFOCache::searchCache(int num){
    flag = false;
    for(int i=0; i<CacheSize; i++){
        if(num == cache[i]){
            flag = true;
        }
    }
    return flag;
}

//Return the location of number in memory
int LIFOCache::getlocMemory(int num){
    for(int i=0; i<MemorySize; i++){
        if(num == memory[i]){
            return i;
        }
    }
    return 0;
}

//Push element into Cache
void LIFOCache::push(int num){
    int locMemory = getlocMemory(number);
    cache[top++] = memory[locMemory];
}

//Pop element from Cache
void LIFOCache::pop(){
    cache[--top] = 0;
}

//Check Overflow 
bool LIFOCache::Overflow(){
    if(top >= CacheSize){
        return true;
    }
    return false;
}



