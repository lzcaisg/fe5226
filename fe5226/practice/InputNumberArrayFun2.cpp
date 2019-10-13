/*
Author: Fabio Cannizzo
NUS FE5226 Example Program

Prompt the user to repeadetly input positive integers numbers from the console
A negative number cause termination of the input phase
Upon termination of the input phase, all inputed numbers are output to the console
Data structure used is a dynamic array
*/

#include <iostream>

#include "GetInteger.h"

using namespace std;

unsigned int *growArray(const unsigned int *current, unsigned& capacity)
{
    unsigned size = capacity;

    // increase capacity variable
    capacity *= 2;

    // allocate new storage space with the new larger capacity
    // note that the pointer variable 'tmp' is local to this statement block
    unsigned int *tmp = new unsigned int[capacity];

    // copy from previous small storage space to new large storage space
    for (auto i = 0u; i < size; ++i) // note the use of 'auto' and of suffix 'u'
        tmp[i] = current[i];

    // release old storage space
    delete[] current;

    // point the 'numbers' pointer to the new storage space
    return tmp;
}


void addNewNumber(unsigned int *numbers, unsigned& size, unsigned userInput)
{
    // Note that in the following instruction 'size' is post-incremented 
    // and userInput is automatically casted from signed to unsigned
    numbers[size++] = userInput;
}

void printArray(const unsigned int *numbers, unsigned size)
{
    for (auto i = 0u; i < size; ++i) // note the use of 'auto' and of suffix 'u'
        cout << numbers[i] << " ";
    cout << endl;
}

int main()
{
    // initialize necessary variables (note the use of unsigned)
    unsigned int capacity = 10;   // storage capacity
    unsigned int size = 0;        // how many numbers have been stored so far
    unsigned int *numbers = new unsigned int[capacity];  // allocate memory storage

    // we start an infinite loop, which we will stop with 'break'
    // we keep asking the user to enter a number until a negative number is entered 
    while (true) {

        int userInput = getInteger("Enter a non-negative integer or a negative to terminate: ");

        // At this point we are sure have a valid integer input

        // if the input is negative, we terminate the input loop
        if (userInput < 0)
            break;

        // At this point we are sure have a valid integer input and we know it is positive

        // do we have enough space to store it? If not, we increase the storage space
        if (size == capacity)
            numbers = growArray(numbers, capacity);

        // At this point we are sure have a valid integer input, we know it is positive
        // and we know we have enough storage space to add it
        // So we add the new number to the existing storage
        addNewNumber(numbers, size, userInput);
    }

    // the input loop is completed.

    // we print the numbers
    printArray(numbers, size);

    // release memory
    delete[] numbers;

    return 0;
}

