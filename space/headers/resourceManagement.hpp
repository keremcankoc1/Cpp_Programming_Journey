#pragma once
#include <iostream>
#include <vector>
#include "resource.hpp"

using sourceVector = std::vector<Resource>;

class ResourceManagement{
    private:
        sourceVector sources;
    public:
        ResourceManagement();

        sourceVector &getSources();

        void showSourceData();
        void showOneSource(int sourceId);

        void sourceReduce(int sourceId, int reduceAmount);
        void sourceIncrease(int sourceId, int increaseAmount);

        void addSource(std::string sourceName, int sourceAmount, int sourceId);
};