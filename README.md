# CPU Scheduler Simulator

A console-based CPU scheduling simulator implementing 6 major scheduling algorithms with dynamic memory management.

## Features
- **6 Scheduling Algorithms:** FCFS, SJF (Non-Preemptive/Preemptive), Round Robin, Priority (Non-Preemptive/Preemptive)
- **Dynamic Memory Management** with proper cleanup
- **Exception Handling** for robust error management
- **Performance Metrics** calculation
- **Input Validation** and error prevention

## Algorithms

| Algorithm | Type | Description |
|-----------|------|-------------|
| FCFS | Non-Preemptive | First Come First Serve |
| SJF | Non-Preemptive/Preemptive | Shortest Job First |
| Round Robin | Preemptive | Time quantum scheduling |
| Priority | Non-Preemptive/Preemptive | Priority-based scheduling |

## Structure
```
├── main.cpp      # Main application
├── process.h     # Process class
├── Scheduler.h   # Scheduler algorithms
```

## Technical Highlights
- Dynamic arrays with bounds checking
- Exception-safe memory allocation
- Stream error recovery
- Cross-platform compatible

## Requirements
- C++11 or later
- Standard C++ library only

Perfect for learning CPU scheduling and C++ programming!
