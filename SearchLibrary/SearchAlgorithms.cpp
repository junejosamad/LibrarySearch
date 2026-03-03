#include "SearchAlgorithms.h"

// 1. Original Binary Search
int SearchAlgorithms::BinarySearch(int key, const std::vector<int>& elemArray) {
    if (elemArray.empty()) return -1;

    int bottom = 0;
    int top = elemArray.size() - 1;
    int mid;
    int index = -1;
    bool found = false;

    while (bottom <= top && !found) {
        mid = (top + bottom) / 2;
        if (elemArray[mid] == key) {
            index = mid;
            found = true;
            return index;
        }
        else {
            if (elemArray[mid] < key)
                bottom = mid + 1;
            else
                top = mid - 1;
        }
    }
    return index;
}

// 2. Linear Search
int SearchAlgorithms::LinearSearch(int key, const std::vector<int>& elemArray) {
    for (size_t i = 0; i < elemArray.size(); i++) {
        if (elemArray[i] == key) return static_cast<int>(i);
    }
    return -1;
}

// 3. Jump Search (Requires sorted array)
int SearchAlgorithms::JumpSearch(int key, const std::vector<int>& elemArray) {
    if (elemArray.empty()) return -1;

    int n = elemArray.size();
    int step = std::sqrt(n);
    int prev = 0;

    while (elemArray[std::min(step, n) - 1] < key) {
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) return -1;
    }

    while (elemArray[prev] < key) {
        prev++;
        if (prev == std::min(step, n)) return -1;
    }

    if (elemArray[prev] == key) return prev;
    return -1;
}