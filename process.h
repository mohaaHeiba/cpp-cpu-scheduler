#pragma once
#include <iostream>

class process {
private:
    int* burst_time;
    int* arrival_time;
    int burst_time_size;
    int* turnaround;
    int turnaround_size;
    int arrival_time_size;
    int size;
    int* priority;
    int priority_size;

public:
    process() {
        size = 0;
        priority_size = 0;
        burst_time_size = 0;
        arrival_time_size = 0;
		turnaround_size = 0;
        burst_time = nullptr;
        arrival_time = nullptr;
        priority = nullptr;
        turnaround = nullptr;
    }

    ~process() {
        emptyIndex();
    }

    void set_burst_time(int input) {
        int* temp = nullptr;
        try {
            temp = new int[burst_time_size + 1];
            for (int i = 0; i < burst_time_size; i++) {
                temp[i] = burst_time[i];
            }
            temp[burst_time_size] = input;

            delete[] burst_time;
            burst_time = temp;
            burst_time_size++;
            size++;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed in set_burst_time: " << e.what() << std::endl;
            delete[] temp;
        }
    }

    int get_burst_time(int k) {
        if (k < 0 || k >= burst_time_size) {
            std::cerr << "Index out of bounds in get_burst_time!" << std::endl;
            return -1;
        }
        return burst_time[k];
    }

    void set_arrival_time(int input) {
        int* temp = nullptr;
        try {
            temp = new int[arrival_time_size + 1];
            for (int i = 0; i < arrival_time_size; i++) {
                temp[i] = arrival_time[i];
            }
            temp[arrival_time_size] = input;

            delete[] arrival_time;
            arrival_time = temp;
            arrival_time_size++;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed in set_arrival_time: " << e.what() << std::endl;
            delete[] temp;
        }
    }

    int get_arrival_time(int k) {
        if (k < 0 || k >= arrival_time_size) {
            std::cerr << "Index out of bounds in get_arrival_time!" << std::endl;
            return -1;
        }
        return arrival_time[k];
    }

    int get_size() {
        size = burst_time_size;
        return size;
    }

    void set_priority(int input) {
        int* temp = nullptr;
        try {
            temp = new int[priority_size + 1];
            for (int i = 0; i < priority_size; i++) {
                temp[i] = priority[i];
            }
            temp[priority_size] = input;

            delete[] priority;
            priority = temp;
            priority_size++;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed in set_priority: " << e.what() << std::endl;
            delete[] temp;
        }
    }

    int get_priority(int k) {
        if (k < 0 || k >= priority_size) {
            std::cerr << "Index out of bounds in get_priority!" << std::endl;
            return -1;
        }
        return priority[k];
    }
    void set_turnaround(int input) {
        int* temp = nullptr;
        try {
            temp = new int[turnaround_size + 1];
            for (int i = 0; i < turnaround_size; i++) {
                temp[i] = turnaround[i];
            }
            temp[turnaround_size] = input;

            delete[] turnaround;
            turnaround = temp;
            turnaround_size++;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed in set_turnaround: " << e.what() << std::endl;
            delete[] temp;
        }
    }

    int get_turnaround(int k) {
        if (k < 0 || k >= turnaround_size) {
            std::cerr << "Index out of bounds in get_turnaround!" << std::endl;
            return -1;
        }
        return turnaround[k];
    }

    void emptyIndex() {
        delete[] priority;
        priority = nullptr;

        delete[] burst_time;
        burst_time = nullptr;

        delete[] arrival_time;
        arrival_time = nullptr;
        delete[] turnaround;
        turnaround = nullptr;
		turnaround_size = 0;
        arrival_time_size = 0;
        priority_size = 0;
        burst_time_size = 0;
        size = 0;
    }
};
