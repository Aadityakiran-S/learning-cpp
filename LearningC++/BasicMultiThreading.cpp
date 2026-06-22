#include "BasicMultiThreading.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

namespace MultiThreading {

// Constructor - initialize member variables
Demo::Demo() : OddSum(0), EvenSum(0) {
}

// Reset values to initial state
void Demo::reset() {
    OddSum = 0;
    EvenSum = 0;
}

void Demo::findEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0) {
            EvenSum += i;
        }
    }
}

void Demo::findOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 1) {
            OddSum += i;
        }
    }
}

void Demo::run() {
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    // Create threads - use lambda to capture 'this' for member functions
    thread t1([this, start, end]() { this->findEven(start, end); });
    thread t2([this, start, end]() { this->findOdd(start, end); });

    // Wait for threads to finish
    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum: " << OddSum << endl;
    cout << "EvenSum: " << EvenSum << endl;
    cout << "Time taken: " << duration.count() / 1000000.0 << " seconds" << endl;

    // Reset values after run completes
    reset();
}

} // namespace MultiThreading