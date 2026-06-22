#pragma once

namespace MultiThreading {
    class Demo {
    public:
        Demo();  // Constructor
        void run();
    
    private:
        unsigned long long OddSum;
        unsigned long long EvenSum;
        
        void findEven(unsigned long long start, unsigned long long end);
        void findOdd(unsigned long long start, unsigned long long end);
        void reset();  // Reset values to initial state
    };
}
