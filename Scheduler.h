#pragma once
#include <iostream>
#include "process.h"
#include <string>
using namespace std;

class Scheduler
{
public:

    void FCFS(process& p) {
        int size = p.get_size();
        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* arrivalTime = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            arrivalTime = new int[size];
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }

        WaitingTime[0] = 0;

        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            arrivalTime[i] = p.get_arrival_time(i);
        }

        for (int i = 1; i < size; i++) {
            WaitingTime[i] = BurstTime[i - 1] + WaitingTime[i - 1];
        }

        for (int i = 0; i < size; i++) {
            TurnAroundTime[i] = BurstTime[i] + WaitingTime[i];
        }

        int totalWaitingTime = 0, totalTurnAroundTime = 0;
        cout << "Processes  " << "Burst time  " << "Arrival time  " << "Waiting time  " << "Turn around time\n";
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            totalWaitingTime += WaitingTime[i];
            totalTurnAroundTime += TurnAroundTime[i];
            cout << "    " << i + 1 << "           " << BurstTime[i] << "          " << arrivalTime[i]
                << "               " << WaitingTime[i] << "             " << TurnAroundTime[i] << endl;
            cout << "--------------------------------------------------------------------\n";
        }

        float averageWaitingTime = static_cast<float>(totalWaitingTime) / size;
        float averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / size;
        for (int i = 0; i < size; i++) {
            p.set_turnaround(TurnAroundTime[i]);
        }

        cout << "Average Waiting Time: " << averageWaitingTime << endl;
        cout << "Average Turn Around Time: " << averageTurnAroundTime << endl;

        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] arrivalTime;
    }

    void PriorityScheduling(process& p) {
        int size = p.get_size();
        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* arrivalTime = nullptr;
        int* Priority = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            arrivalTime = new int[size];
            Priority = new int[size];
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            arrivalTime[i] = p.get_arrival_time(i);
            Priority[i] = p.get_priority(i);
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (Priority[i] > Priority[j]) {
                    swap(BurstTime[i], BurstTime[j]);
                    swap(Priority[i], Priority[j]);
                    swap(arrivalTime[i], arrivalTime[j]);
                }
            }
        }

        p.emptyIndex();
        for (int i = 0; i < size; i++) {
            p.set_burst_time(BurstTime[i]);
            p.set_priority(Priority[i]);
            p.set_arrival_time(arrivalTime[i]);
            p.set_turnaround(TurnAroundTime[i]);
        }

        cout << endl;
        FCFS(p);

        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] arrivalTime;
        delete[] Priority;
    }

    void Preemptive_PriorityScheduling(process& p) {
        int size = p.get_size();

        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* RemainingTime = nullptr;
        int* ArrivalTime = nullptr;
        int* Priority = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            RemainingTime = new int[size];
            ArrivalTime = new int[size];
            Priority = new int[size];
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            ArrivalTime[i] = p.get_arrival_time(i);
            Priority[i] = p.get_priority(i);
            RemainingTime[i] = BurstTime[i];
            WaitingTime[i] = 0;
            TurnAroundTime[i] = 0;
        }

        int completedCount = 0;
        int currentTime = 0;

        while (completedCount < size) {
            int highestPriority = INT_MAX;
            int processIndex = -1;

            for (int i = 0; i < size; i++) {
                if (ArrivalTime[i] <= currentTime && RemainingTime[i] > 0 && Priority[i] < highestPriority) {
                    highestPriority = Priority[i];
                    processIndex = i;
                }
            }

            if (processIndex != -1) {
                RemainingTime[processIndex]--;

                if (RemainingTime[processIndex] == 0) {
                    completedCount++;
                    TurnAroundTime[processIndex] = currentTime - ArrivalTime[processIndex] + 1;
                    WaitingTime[processIndex] = TurnAroundTime[processIndex] - BurstTime[processIndex];
                }
            }

            currentTime++;
        }

        int totalWaitingTime = 0, totalTurnAroundTime = 0;
        cout << "Processes  " << "Burst time  " << "Arrival time  " << "Waiting time  " << "Turn around time\n";
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            totalWaitingTime += WaitingTime[i];
            totalTurnAroundTime += TurnAroundTime[i];
            cout << "    " << i + 1 << "           " << BurstTime[i] << "          " << ArrivalTime[i]
                << "               " << WaitingTime[i] << "             " << TurnAroundTime[i] << endl;
            cout << "--------------------------------------------------------------------\n";
        }
        for (int i = 0; i < size; i++) {
            p.set_turnaround(TurnAroundTime[i]);
        }

        float averageWaitingTime = static_cast<float>(totalWaitingTime) / size;
        float averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / size;

        cout << "Average Waiting Time: " << averageWaitingTime << endl;
        cout << "Average Turn Around Time: " << averageTurnAroundTime << endl;

        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] RemainingTime;
        delete[] ArrivalTime;
        delete[] Priority;
    }

    void Non_preemptive_SJF(process& p) {
        int size = p.get_size();
        cout << size << endl;

        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* ArrivalTime = nullptr;
        bool* completed = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            ArrivalTime = new int[size];
            completed = new bool[size] { false };
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            ArrivalTime[i] = p.get_arrival_time(i);
            WaitingTime[i] = 0;
            TurnAroundTime[i] = 0;
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (ArrivalTime[i] > ArrivalTime[j]) {
                    swap(ArrivalTime[i], ArrivalTime[j]);
                    swap(BurstTime[i], BurstTime[j]);
                }
            }
        }

        int completedProcesses = 0;
        int currentTime = 0;

        while (completedProcesses < size) {
            int minBurstTime = INT_MAX;
            int selectedProcess = -1;

            for (int i = 0; i < size; i++) {
                if (!completed[i] && ArrivalTime[i] <= currentTime && BurstTime[i] < minBurstTime) {
                    minBurstTime = BurstTime[i];
                    selectedProcess = i;
                }
            }

            if (selectedProcess != -1) {
                completed[selectedProcess] = true;
                WaitingTime[selectedProcess] = currentTime - ArrivalTime[selectedProcess];
                TurnAroundTime[selectedProcess] = WaitingTime[selectedProcess] + BurstTime[selectedProcess];

                currentTime += BurstTime[selectedProcess];
                completedProcesses++;
            }
            else {
                currentTime++;
            }
        }

        cout << "PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << "\t" << BurstTime[i] << "\t\t" << ArrivalTime[i]
                << "\t\t" << WaitingTime[i] << "\t\t" << TurnAroundTime[i] << endl;
        }

        float totalWaitingTime = 0, totalTurnAroundTime = 0;
        for (int i = 0; i < size; i++) {
            totalWaitingTime += WaitingTime[i];
            totalTurnAroundTime += TurnAroundTime[i];
        }
        for (int i = 0; i < size; i++) {
            p.set_turnaround(TurnAroundTime[i]);
        }

        cout << "Average Waiting Time: " << totalWaitingTime / size << endl;
        cout << "Average Turnaround Time: " << totalTurnAroundTime / size << endl;

        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] ArrivalTime;
        delete[] completed;
    }

    void Preemptive_SJF(process& p) {
        int size = p.get_size();

        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* RemainingTime = nullptr;
        int* ArrivalTime = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            RemainingTime = new int[size];
            ArrivalTime = new int[size];
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }

        // Initializing arrays
        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            ArrivalTime[i] = p.get_arrival_time(i);
            RemainingTime[i] = BurstTime[i];
            WaitingTime[i] = 0;
            TurnAroundTime[i] = 0;
        }

        int complete = 0, currentTime = 0, finishTime;
        int shortest = -1;
        bool found = false;

        // Preemptive SJF scheduling loop
        while (complete != size) {
            int minRemainingTime = INT_MAX; // Reset for each loop
            found = false;

            // Find the process with the smallest remaining time
            for (int i = 0; i < size; i++) {
                if (ArrivalTime[i] <= currentTime && RemainingTime[i] > 0 && RemainingTime[i] < minRemainingTime) {
                    minRemainingTime = RemainingTime[i];
                    shortest = i;
                    found = true;
                }
            }

            if (!found) {
                currentTime++;  // No process is ready to execute, increment time
                continue;
            }

            // Execute the selected process for one unit of time (preemptive)
            RemainingTime[shortest]--;

            // Update finish time if this is the last unit for the process
            if (RemainingTime[shortest] == 0) {
                complete++;
                finishTime = currentTime + 1; // The process finishes at the next time unit
                TurnAroundTime[shortest] = finishTime - ArrivalTime[shortest];
                WaitingTime[shortest] = TurnAroundTime[shortest] - BurstTime[shortest];
                if (WaitingTime[shortest] < 0) WaitingTime[shortest] = 0; // Avoid negative waiting time
            }

            currentTime++;  // Increment time after each cycle
        }

        // Calculate average times
        int totalWaitingTime = 0, totalTurnAroundTime = 0;
        cout << "Processes  " << "Burst time  " << "Arrival time  " << "Waiting time  " << "Turnaround time\n";
        cout << "---------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            totalWaitingTime += WaitingTime[i];
            totalTurnAroundTime += TurnAroundTime[i];
            cout << "    " << i + 1 << "           " << BurstTime[i] << "          " << ArrivalTime[i]
                << "               " << WaitingTime[i] << "             " << TurnAroundTime[i] << endl;
            cout << "---------------------------------------------------------\n";
        }

        // Set turnaround times for the process class
        for (int i = 0; i < size; i++) {
            p.set_turnaround(TurnAroundTime[i]);
        }

        float averageWaitingTime = static_cast<float>(totalWaitingTime) / size;
        float averageTurnAroundTime = static_cast<float>(totalTurnAroundTime) / size;

        cout << "Average Waiting Time: " << averageWaitingTime << endl;
        cout << "Average Turn Around Time: " << averageTurnAroundTime << endl;

        // Clean up dynamically allocated memory
        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] RemainingTime;
        delete[] ArrivalTime;
    }

    void Round_Robin(process& p) {
        int size = p.get_size();
        int* WaitingTime = nullptr;
        int* TurnAroundTime = nullptr;
        int* BurstTime = nullptr;
        int* RemainingTime = nullptr;
        int* arrivalTime = nullptr;

        try {
            WaitingTime = new int[size];
            TurnAroundTime = new int[size];
            BurstTime = new int[size];
            RemainingTime = new int[size];
            arrivalTime = new int[size];
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return;
        }
     int decision;
     jump:
        int quantum;
        cout << "Is your time quantum known?(known 1,unknown 0)\n";
        cin>>decision;
        if(decision==1){
                cout<<"Enter your time quantum:\n";
        cin >> quantum;}
        else if(decision==0){
            quantum=p.get_burst_time(0);
        }else{
        cout<<"Enter correct input\n";
        cin.clear();
        cin.ignore();
        goto jump;}

        for (int i = 0; i < size; i++) {
            BurstTime[i] = p.get_burst_time(i);
            RemainingTime[i] = BurstTime[i];
            arrivalTime[i] = p.get_arrival_time(i);
            WaitingTime[i] = 0;
            TurnAroundTime[i] = 0;
        }

        int currentTime = 0;
        bool done;

        do {
            done = true;

            for (int i = 0; i < size; i++) {
                if (RemainingTime[i] > 0) {
                    done = false;

                    if (RemainingTime[i] > quantum) {
                        currentTime += quantum;
                        RemainingTime[i] -= quantum;
                    }
                    else {
                        currentTime += RemainingTime[i];
                        WaitingTime[i] = currentTime - BurstTime[i];
                        RemainingTime[i] = 0;
                    }
                }
            }
        } while (!done);

        int total_WaitingTime = 0, total_TurnAroundTime = 0;

        for (int i = 0; i < size; i++) {
            TurnAroundTime[i] = BurstTime[i] + WaitingTime[i];
            total_WaitingTime += WaitingTime[i];
            total_TurnAroundTime += TurnAroundTime[i];
        }

        cout << "Processes  " << "Burst time  " << "Arrival time  " << "Waiting time  " << "Turn around time\n";
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            cout << "    " << i + 1 << "           " << BurstTime[i] << "          " << arrivalTime[i]
                << "               " << WaitingTime[i] << "             " << TurnAroundTime[i] << endl;
            cout << "--------------------------------------------------------------------\n";
        }

        float averageWaitingTime = static_cast<float>(total_WaitingTime) / size;
        float averageTurnAroundTime = static_cast<float>(total_TurnAroundTime) / size;
        for (int i = 0; i < size; i++) {
            p.set_turnaround(TurnAroundTime[i]);
        }

        cout << "Average Waiting Time: " << averageWaitingTime << endl;
        cout << "Average Turn Around Time: " << averageTurnAroundTime << endl;

        delete[] WaitingTime;
        delete[] TurnAroundTime;
        delete[] BurstTime;
        delete[] RemainingTime;
        delete[] arrivalTime;
    }

};
