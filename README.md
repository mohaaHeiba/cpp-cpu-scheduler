# CPU Scheduler Simulator C++

A comprehensive console-based CPU scheduling simulator implementing 6 major scheduling algorithms with dynamic memory management and robust error handling.

## 🎯 **Project Names & Descriptions:**

### **Recommended Name:** `cpp-cpu-scheduler`
**Description:** *"Advanced C++ console application for CPU scheduling simulation featuring 6 algorithms (FCFS, SJF, Priority, Round Robin) with dynamic memory management and comprehensive performance analysis."*

---

## 🖥️ Overview

This project provides a robust console-based simulator for understanding CPU scheduling algorithms used in operating systems. Built with modern C++ practices including dynamic memory management, exception handling, and object-oriented design.

**Key Features:**
- 🔧 **6 Scheduling Algorithms** implemented
- 🎯 **Dynamic Memory Management** with proper cleanup
- ⚡ **Exception Handling** for robust error management
- 📊 **Performance Metrics** calculation
- 🔄 **Interactive Console Interface**
- 🛡️ **Input Validation** and error prevention

## 🛠️ Implemented Algorithms

| Algorithm | Type | Features |
|-----------|------|----------|
| **FCFS** | Non-Preemptive | First Come First Serve |
| **SJF (Non-Preemptive)** | Non-Preemptive | Shortest Job First |
| **SJF (Preemptive)** | Preemptive | Shortest Remaining Time |
| **Round Robin** | Preemptive | Time quantum with circular queue |
| **Priority (Non-Preemptive)** | Non-Preemptive | Priority-based scheduling |
| **Priority (Preemptive)** | Preemptive | Dynamic priority scheduling |

## 📋 Project Structure

```
cpp-cpu-scheduler/
├── main.cpp              # Main application with UI
├── process.h             # Process class definition
├── Scheduler.h           # Scheduler algorithms implementation
└── README.md
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- C++11 or later standard

### Compilation
```bash
# Using g++
g++ -std=c++11 main.cpp -o scheduler

# Using clang++
clang++ -std=c++11 main.cpp -o scheduler

# Using MSVC
cl /EHsc main.cpp
```

### Running the Application
```bash
./scheduler          # Linux/Mac
scheduler.exe        # Windows
```

## 💻 Usage Guide

### 1. Process Input Phase
```
Enter Process{0}'S Arrival time: 0
Enter Process{0}'S Burst time: 5
Enter Process{1}'S Arrival time: 1
Enter Process{1}'S Burst time: 3
Enter Process{2}'S Arrival time: -1    # -1 to finish input
```

### 2. Algorithm Selection
```
Select preferred Scheduler algorithm:
1 - FCFS
2 - SJN (Non_Preemptive)
3 - SJN (Preemptive)
4 - Round Robin
5 - Priority Scheduling (Non_Preemptive)
6 - Priority Scheduling (Preemptive)
```

### 3. Additional Inputs
- **Priority Algorithms:** Enter priority values for each process
- **Round Robin:** Choose time quantum (known/unknown)

## 🔧 Technical Implementation

### Process Class Features
- **Dynamic Arrays:** Automatically resizing arrays for processes
- **Memory Management:** Proper allocation and deallocation
- **Bounds Checking:** Safe array access with validation
- **Exception Safety:** Bad allocation handling

### Scheduler Class Features
- **Algorithm Implementation:** All 6 major scheduling algorithms
- **Performance Calculation:** Waiting time and turnaround time
- **Memory Safety:** Dynamic allocation with cleanup
- **Error Handling:** Robust exception management

### Key Technical Highlights
```cpp
// Dynamic memory allocation with exception handling
try {
    WaitingTime = new int[size];
    TurnAroundTime = new int[size];
} catch (const bad_alloc& e) {
    cerr << "Memory allocation failed: " << e.what() << endl;
    return;
}

// Proper cleanup
delete[] WaitingTime;
delete[] TurnAroundTime;
```

## 📊 Algorithm Details

### FCFS (First Come First Serve)
- **Type:** Non-preemptive
- **Logic:** Processes executed in arrival order
- **Complexity:** O(n)

### SJF (Shortest Job First)
- **Non-Preemptive:** Select shortest job among available
- **Preemptive:** Switch to shorter job when it arrives
- **Complexity:** O(n²) for sorting

### Priority Scheduling
- **Non-Preemptive:** Sort by priority, then FCFS
- **Preemptive:** Dynamic priority-based preemption
- **Feature:** Lower number = higher priority

### Round Robin
- **Type:** Preemptive with time quantum
- **Feature:** Circular queue implementation
- **Options:** User-defined or automatic quantum

## 🛡️ Error Handling Features

- **Input Validation:** Integer input checking
- **Bounds Checking:** Array access validation
- **Memory Management:** Exception-safe allocation
- **Stream Error Recovery:** Input stream cleanup
- **Graceful Degradation:** Continue operation after errors

## 🔄 Program Flow

1. **Process Input:** Dynamic process creation
2. **Algorithm Selection:** User choice validation
3. **Additional Parameters:** Priority/quantum input
4. **Execution:** Algorithm-specific scheduling
5. **Results Display:** Formatted output with metrics
6. **Continuation:** Option to rerun or exit

## 💡 Learning Outcomes

Perfect for understanding:
- **Operating Systems Concepts:** Process scheduling
- **C++ Programming:** Dynamic memory, OOP, exception handling
- **Algorithm Analysis:** Time complexity and performance
- **System Design:** Robust error handling and validation

## 🚀 Future Enhancements

- [ ] Gantt chart visualization
- [ ] File input/output for process data
- [ ] Multilevel queue scheduling
- [ ] GUI interface implementation
- [ ] Performance benchmarking tools

## 🔧 Technical Requirements

- **C++ Standard:** C++11 or later
- **Memory:** Dynamic allocation supported
- **Platform:** Cross-platform compatible
- **Dependencies:** Standard C++ library only

---

⭐ **Perfect for learning CPU scheduling and C++ programming!** ⭐
