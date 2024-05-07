#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;


vector<int> generateRandomVector(int size) {
    vector<int> v(size);
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        v[i] = rand() % 1000;
    }
    return v;
}


template<typename T>
double measureSortingTime(void (*sortingAlgorithm)(vector<T>&), vector<T>& data) {
    clock_t start = clock();
    sortingAlgorithm(data);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int vectorSize;
    cout << "Enter the size of the vector: "<< endl;
    cin >> vectorSize;

    if (vectorSize <= 0) {
        cerr << "Vector size must be a positive integer." << endl;
        return 1;
    }

    vector<int> randomVector = generateRandomVector(vectorSize);
    vector<int> randomVectorCopy = randomVector;

    cout << "Vector Size: " << vectorSize << endl;

    cout << "BubbleSort:" << endl;
    double bubbleSortTime = measureSortingTime(BubbleSort<int>, randomVectorCopy);
    cout << "Time taken: " << bubbleSortTime << " seconds" << endl;

    vector<int> mergeSortVector = randomVector;
    cout << "MergeSort:" << endl;
    double mergeSortTime = measureSortingTime(MergeSort<int>, mergeSortVector);
    cout << "Time taken: " << mergeSortTime << " seconds" << endl;

    return 0;
}
