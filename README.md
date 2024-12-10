# GaleShapley Algorithm for Hospital-Student Matching
## Description 
This repository contains a C++ implementation of the Gale-Shapley algorithm, also known as the Stable Matching Algorithm. The algorithm is designed to find a stable matching between two sets (hospitals and medical students in this case) based on their preference rankings.

The implementation uses random preference lists for hospitals and medical students, allowing for dynamic testing of the algorithm.

## **Features**
  _Implements the Gale-Shapley algorithm for stable matching.
  _Randomized preference lists for dynamic testing.
  _Clean and modular C++ code with clear separation of logic.
  _Console output of the stable matching results.

## **How it Works**
  _**Inputs:** Randomly generated preferences for both hospitals and medical students.
  _**Algorithm Execution:** The algorithm matches hospitals to medical students while ensuring stability (no pair prefers each     other over their current matches).
  _**Output:** Prints the stable matching to the console.

## **Code Structure
  _main(): Sets up random preference lists and calls the galeShapley function.
  _galeShapley(): Implements the Gale-Shapley algorithm and prints the matching.

## How to run

Clone the repository:
````
```
git clone https://github.com/r8bhavneet/GaleShapley.git
```
````
Navigate to the project directory:
````
```
cd GaleShapley
```
````
Ensure that you have C++ compiler(like g++) installed. You can then compile the code with:
````
```
g++ -o gale_shapley gale_shapley.cpp
```
```
Run the program:
````
```
./gale_shapley
```
```

