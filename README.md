# Design and Analysis of Algorithms (DAA) - Lab Assignments

**Author:** Soham Sapkal  
**PRN:** 124B1F047  
**Course:** Design and Analysis of Algorithms Laboratory  

---

## Repository Overview

This repository contains C++ implementations and problem-solving solutions for Design and Analysis of Algorithms (DAA) laboratory assignments. Each assignment covers fundamental algorithmic strategies including Divide and Conquer, Greedy Techniques, and Graph Algorithms.

---

## Assignments Directory

| Assignment | Topic / Algorithm | Description | Key Files |
|---|---|---|---|
| **[ASSN_1](./ASSN_1/)** | **Merge Sort** (Divide & Conquer) | Sorts user records from `social_media_usage.csv` in ascending order based on daily minutes spent on apps. | `merge_sort.cpp`, `social_media_usage.csv` |
| **[ASSN_2](./ASSN_2/)** | **Quick Sort** (Divide & Conquer) | Sorts movie records from `movies.csv` by IMDb score using the Lomuto partitioning scheme. | `quick_sort.cpp`, `movies.csv` |
| **[ASSN_3](./ASSN_3/)** | **Fractional Knapsack** (Greedy Strategy) | Optimizes disaster relief supply selection for a rescue boat (capacity: 55 kg) based on value-to-weight utility ratio. | `fractional_knapsack.cpp` |
| **[ASSN_4](./ASSN_4/)** | **Dijkstra's Algorithm** (Graph Algorithm) | Computes single-source shortest paths in an emergency road network using a min-heap to find the nearest hospital for an ambulance. | `DIJKSTRA.cpp` |

---

## 🚀 Compilation and Execution

All programs are written in standard C++ and can be compiled using `g++` (C++11 or higher recommended).

### 1. Assignment 1: Merge Sort
```bash
cd ASSN_1
g++ -std=c++11 merge_sort.cpp -o merge_sort
./merge_sort
```

### 2. Assignment 2: Quick Sort
```bash
cd ASSN_2
g++ -std=c++11 quick_sort.cpp -o quick_sort
./quick_sort
```

### 3. Assignment 3: Fractional Knapsack
```bash
cd ASSN_3
g++ -std=c++11 fractional_knapsack.cpp -o fractional_knapsack
./fractional_knapsack
```

### 4. Assignment 4: Dijkstra's Algorithm
```bash
cd ASSN_4
g++ -std=c++11 DIJKSTRA.cpp -o DIJKSTRA
./DIJKSTRA
```

---

## 🛠 Tech Stack
- **Language:** C++ (C++11/C++14/C++17)
- **Standard Libraries:** STL containers (`vector`, `queue`, `priority_queue`, `algorithm`, `iostream`, `fstream`, `sstream`, `iomanip`)
- **Paradigms:** Divide and Conquer, Greedy Algorithms, Graph Theory
