#pragma once
#include <iostream>
#include <vector>
#include <string>


class Resource{
    private:
        std::string sourceName;
        int sourceAmount;
        int sourceId;
    public:
        Resource(std::string sourceName, int sourceAmount, int sourceId);

        int getSourceAmount();
        int getSourceId();
        std::string getSourceName();

        void increase(int increaseAmount);
        void reduce(int reduceAmount);
};