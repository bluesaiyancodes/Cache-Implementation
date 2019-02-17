//
//  main.cpp
//  CacheImplementation
//
//  Created by Bishal Blue on 03/12/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include <iostream>
#include "LIFO.hpp"
#include "FIFO.hpp"
#include "LRU.hpp"
#include "MRU.hpp"

int main(int argc, const char * argv[]) {
    std::cout<<"\nCache Simulation"<<std::endl;
    std::cout<<"1: FIFO"<<std::endl;
    std::cout<<"2: LIFO"<<std::endl;
    std::cout<<"3: LRU"<<std::endl;
    std::cout<<"4: MRU"<<std::endl;
    
    std::cout<<"\nChoose: ";
    int choicein;
    std::cin>>choicein;
    
    
    int choice;
    
    if(choicein == 1){
        FIFOCache fifocache;
        fifocache.inputarray();
        do{
            fifocache.display();
            fifocache.input();
            fifocache.fifo();
            fifocache.display();
            std::cout<<"\nEnter 1 to continue.";
            std::cin>>choice;
        }while(choice == 1);
    }
    else if (choicein == 2){
        LIFOCache lifocache;
        lifocache.inputMemory();
        do{
            lifocache.display();
            lifocache.input();
            lifocache.lifo();
            lifocache.display();
            std::cout<<"\nEnter 1 to continue.";
            std::cin>>choice;
        }while(choice == 1);
    }
    else if(choicein == 3){
        LRUCache lrucache;
        lrucache.inputMemory();
        do{
            lrucache.display();
            lrucache.input();
            lrucache.LRU();
            lrucache.display();
            std::cout<<"\nEnter 1 to continue.";
            std::cin>>choice;
        }while(choice == 1);
    }
    else if(choicein == 4){
        MRUCache mrucache;
        mrucache.inputMemory();
        do{
            mrucache.display();
            mrucache.input();
            mrucache.LRU();
            mrucache.display();
            std::cout<<"\nEnter 1 to continue.";
            std::cin>>choice;
        }while(choice == 1);
        
    }
    else{
        std::cout<<"\nInvalid Input"<<std::endl;
    }
    
    return 0;
}
