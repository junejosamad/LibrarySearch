#pragma once
#include <vector>
#include <cmath>
#include <algorithm>

class SearchAlgorithms {
public:
    int BinarySearch(int key, const std::vector<int>& elemArray);
    int LinearSearch(int key, const std::vector<int>& elemArray);
    int JumpSearch(int key, const std::vector<int>& elemArray);
};