# Project Euler: Generalized & Optimized Solutions

A collection of high-performance C++ solutions to Project Euler challenges. Unlike standard solutions that solve for fixed constants, this repository focuses on generalized algorithms capable of handling dynamic inputs and large-scale cases.

## 🚀 Key Features

* **Generalized Logic:** Every solution in the main mode is written to handle dynamic inputs, allowing for calculations like the n’th prime, custom grid sizes, or variable digit lengths, rather than just the specific Project Euler target.
* **Performance Tracking:** Integrated time checks using `<chrono>` for every problem to ensure solutions stay within the "one-minute rule" (with outputs in microseconds, milliseconds, and seconds).
* **The helpers Namespace:** A centralized library of reusable mathematical utilities, including optimized prime sieves, palindrome checkers, greatest common divisor (GCD) calculators, and string-based large number arithmetic.
* **answer_test Mode:** A dedicated benchmarking framework (Benchmark.h) that allows for:
  * **Stress Testing:** Running a hardcoded solution multiple times to calculate the average execution time.
  * **Verification:** Quickly retrieving the standard Project Euler answer for a specific problem.

## 🛠 Project Structure

* **main.cpp:** The core interactive CLI that routes between standard generalized problem solving and the testing suite.
* **answers.h / answers.cpp:** The dynamic, generalized logic for problems.
* **answers_test.h:** Hardcoded versions of the solutions specifically optimized for the benchmarker.
* **helpers.h / helpers.cpp:** The custom math and utility namespace.
* **Benchmark.h:** The timing and performance measurement engine.

## ⚙️ Running the Tests

To test efficiency or solve a specific case, compile the project and use the interactive menu:

1. Input `-1` to enter the `answer_test` mode.
2. Input the desired problem number to test.
3. Provide the number of iterations for the performance test. The system will run warmup cycles and output the standard Project Euler result along with the average microsecond execution time across all runs.
