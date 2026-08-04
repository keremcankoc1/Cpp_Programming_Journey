#include "../headers/resource.hpp"
#include <iostream>
#include <vector>
#include <string>

Resource::Resource(std::string sourceName, int sourceAmount, int sourceId)
    :sourceName(sourceName),
    sourceAmount(sourceAmount),
    sourceId(sourceId)
{}

int Resource::getSourceId(){
    return sourceId;
}

int Resource::getSourceAmount(){
    return sourceAmount;
}

std::string Resource::getSourceName(){
    return sourceName;
}

void Resource::increase(int increaseAmount){
    sourceAmount += increaseAmount;
}

void Resource::reduce(int reduceAmount){
    sourceAmount -= reduceAmount;
}

