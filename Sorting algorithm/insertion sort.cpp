#include <iostream>
#include <chrono>

void sortArray(int array[], int arraySize);
void printArray(int arr[], int n);

int main()
{
    // initialize
    int myArray[] = { 22, 9, 2, -3, 20, 150 };
    int myArraySize = sizeof(myArray)/sizeof(int);

    // print array pre-sort
    std::cout << "Contents of array pre-sort: ";
    printArray(myArray, myArraySize);

    // time the sort function
    auto startTimer = std::chrono::steady_clock::now();
    sortArray(myArray, myArraySize);
    auto endTimer = std::chrono::steady_clock::now();

    // print array post-sort
    std::cout << "Contents of array post-sort: ";
    printArray(myArray, myArraySize);

    // display elapsed time of the sort function
    std::chrono::duration<double> elapsed_seconds = endTimer - startTimer;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return 0;
}

void sortArray(int array[], int arraySize) // insertion sort
{
    int key, j = 0;

    for (int i = 1; i < arraySize; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
}