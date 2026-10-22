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
| **[DA ASSN 5](./DA%20ASSN%205/)** | **Multistage Graph** (Dynamic Programming) | Computes shortest path across stages using backward dynamic programming with support for dynamic edge updates. | `Multistage graph.cpp` |
| **[DAA ASSN 6](./DAA%20ASSN%206/)** | **0/1 Knapsack** (Dynamic Programming) | Solves the 0/1 knapsack problem using dynamic programming table and backtracks to retrieve optimal item selection. | `Knapsack.cpp` |
| **[DAA ASSN 7](./DAA%20ASSN%207/)** | **Graph Coloring** (Greedy Strategy) | Assigns conflict-free exam time slots to courses using greedy vertex coloring. | `graph coloring.cpp` |
| **[DAA ASSN 8](./DAA%20ASSN%208/)** | **Traveling Salesperson Problem** (Branch and Bound) | Solves the TSP problem using Least Cost Branch and Bound (LCBB) with lower-bound bounding functions and a min-heap priority queue. | `TSP using LC.cpp` |

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

### 5. Assignment 5: Multistage Graph
```bash
cd "DA ASSN 5"
g++ -std=c++11 "Multistage graph.cpp" -o multistage_graph
./multistage_graph
```

### 6. Assignment 6: 0/1 Knapsack
```bash
cd "DAA ASSN 6"
g++ -std=c++11 Knapsack.cpp -o knapsack
./knapsack
```

### 7. Assignment 7: Graph Coloring
```bash
cd "DAA ASSN 7"
g++ -std=c++11 "graph coloring.cpp" -o graph_coloring
./graph_coloring
```

### 8. Assignment 8: Traveling Salesperson Problem (LCBB)
```bash
cd "DAA ASSN 8"
g++ -std=c++11 "TSP using LC.cpp" -o tsp_lc
./tsp_lc
```

---

## 🛠 Tech Stack
- **Language:** C++ (C++11/C++14/C++17)
- **Standard Libraries:** STL containers (`vector`, `queue`, `priority_queue`, `algorithm`, `iostream`, `fstream`, `sstream`, `iomanip`, `limits`)
- **Paradigms:** Divide and Conquer, Greedy Algorithms, Dynamic Programming, Branch and Bound, Graph Theory

