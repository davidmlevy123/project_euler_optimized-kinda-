#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <functional>

namespace Utils {

    class Benchmarker {
    public:
        // This function handles void functions (no return value)
        static void Measure(const std::string& name, std::function<void()> func, int iterations = 100) {
            runBenchmark(name, func, iterations);
        }

        // This function handles functions that return a value (like int, long long, string)
        // It prints the answer first, then runs the benchmark.
        template<typename Func>
        static void MeasureAndPrint(const std::string& name, Func func, int iterations = 100) {
            // 1. Run once to get the result and print it
            auto result = func();
            std::cout << "[Result] " << name << ": " << result << "\n";

            // 2. Run the benchmark loop
            // We wrap the function in a lambda because runBenchmark expects a void function
            runBenchmark(name, [func]() { func(); }, iterations);
        }

    private:
        // Private helper that actually does the timing
        static void runBenchmark(const std::string& name, std::function<void()> func, int iterations) {
            if (iterations < 1) iterations = 1;

            // Warmup run (gets the CPU cache ready)
            func();

            auto start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < iterations; ++i) {
                func();
            }

            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<long double, std::milli> total_ms = end - start;
            std::chrono::duration<long double, std::micro> total_micro = end - start;
            std::chrono::duration<long double> total_sec = end - start;

            double average_ms = (long double)(total_ms.count() / iterations);
            std::cout << "[Time]   " << name << " Average: " << (long double)(total_micro.count() / iterations) << " microseconds (" << iterations << " runs)\n";
            std::cout << "[Time]   " << name << " Average: " << average_ms << " milliseconds (" << iterations << " runs)\n";
            std::cout << "[Time]   " << name << " Average: " << (long double)(total_sec.count() / iterations) << " seconds (" << iterations << " runs)\n";
            std::cout << "[Total Time]     " << (long double)(total_sec.count()) << " seconds (" << iterations << " runs)\n";
            std::cout << "---------------------------------------------------------------------\n";
        }
    };
}