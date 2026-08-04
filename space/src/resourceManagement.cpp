#include "../headers/resource.hpp"
#include "../headers/resourceManagement.hpp"
#include <iostream>
#include <vector>
#include <string>

ResourceManagement::ResourceManagement(){}

sourceVector &ResourceManagement::getSources(){
    return ResourceManagement::sources;
}

void ResourceManagement::sourceIncrease(int sourceId, int increaseAmount){
    Resource source("Default", 0, -1);

    if(increaseAmount < 0 ) std::cout << "Please enter a valid increase (zero or pozitive) amount.\n";
    else{
        for(Resource &source : getSources()){
            if(sourceId == source.getSourceId()){
                source.increase(increaseAmount);
                std::cout << "Increase process is successfull --> " << source.getSourceName() << ": " << source.getSourceAmount() << '\n';
                break;
            }
        }
        
    }
}

void ResourceManagement::sourceReduce(int sourceId, int reduceAmount){
    Resource source("Default", 0, -1);

    if(reduceAmount < 0 ) std::cout << "Please enter a valid reduce (zero or pozitive) amount.\n";
    else{
        bool isFoundSourceID = 0;
        for(Resource &source : getSources()){
            if(sourceId == source.getSourceId()){
                source.reduce(reduceAmount);
                isFoundSourceID = 1;

                if(source.getSourceAmount() >= 0 && source.getSourceId() == sourceId)
                    std::cout << "Reduce process is successfull --> " << source.getSourceName() << ": " << source.getSourceAmount() << '\n';
                else if(source.getSourceAmount() < 0){
                    std::cout << "The source amount cannot be less than 0.\n";
                    source.increase(reduceAmount);// The funds have been refunded
                }
                break;
            }
        }

        if(!isFoundSourceID) std::cout << "No resource with this ID was found.\n";
        
        
    }
}

void ResourceManagement::addSource(std::string sourceName, int sourceAmount, int sourceId){
    ResourceManagement::getSources().push_back(Resource(sourceName, sourceAmount, sourceId));
}

void ResourceManagement::showSourceData(){
    Resource mySource("Default", 0, -1);
    for(const Resource &source : ResourceManagement::getSources()){
        mySource = source;
        std::cout << "=========================================\n";
        std::cout << "Source Name: " << mySource.getSourceName() << '\n';
        std::cout << "Source Amount: " << mySource.getSourceAmount() << '\n';
        std::cout << "Source ID: " << mySource.getSourceId() << '\n';
        std::cout << "=========================================\n";
    }
}

void ResourceManagement::showOneSource(int sourceId){
    bool isPrinted = 0;
    Resource mySource("Default", 0, -1);
    for(const Resource &source : getSources()){
        mySource = source;
        if(mySource.getSourceId() == sourceId){
            std::cout << "=========================================\n";
            std::cout << "Source Name: " << mySource.getSourceName() << '\n';
            std::cout << "Source Amount: " << mySource.getSourceAmount() << '\n';
            std::cout << "Source ID: " << mySource.getSourceId() << '\n';
            std::cout << "=========================================\n";
            isPrinted = 1;
            break;
        }
    }
    if(!isPrinted) std::cout << "No resource with this ID was found.\n";
}