#include <iostream>
#include "process.h"
#include "Scheduler.h"
#include <iomanip>
#include <limits>
#include <exception>

using namespace std;

int main() {
	try {
	    int size=1;
	    int * arrivaltime=new int(size);
	    int * bursttime=new int(size);
	    int * priority=new int(size);
	    int m=0;
		bool b = true;
		while (b == true) {

			cout << "\t \t \t \tCPU Scheduling Simulation in C++\n\n\n";
			int i = 0;
			process p;

			cout << "Process Entry Phase: (Enter -1 to finish)\n\n\n\n\n";
			int x = 0;
			int y = 0;
			int l = 0;
			while (i != -1) {
				cout << "Enter Process{" << i << "}'S Arrival time:\n";
				cin >> x;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter an integer.\n";
					continue;
				}
				if (x == -1) {
					i--;
					break;
				}

				p.set_arrival_time(x);

				cout << "Enter Process{" << i << "}'S Burst time:\n";
				cin >> y;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter an integer.\n";
					continue;
				}
				if (y == -1) {
					i--;
					break;
				}
				p.set_burst_time(y);

				i++;
			}
			cout << "----------------------------------------------------------------------------------\n|Process id      |      Process Arrival time       |       Process burst time    |\n";
			int k = 0;
			int k2 = 0;
			while (k <= i) {
				cout << "----------------------------------------------------------------------------------\n";
				try {
					cout << "|Process{" << k << "}      |                 " << p.get_arrival_time(k)
						<< "                              " << p.get_burst_time(k) << "              \n";
				}
				catch (exception& e) {
					cout << "Error accessing process data: " << e.what() << endl;
				}
				k++;
			}jump:
			cout << "----------------------------------------------------------------------------------\n";
			cout << "\t\t\tSelect preferred Scheduler algorithm\n";
			cout << "1-FCFS\n2-SJN (Non_Preemptive)\n3-SJN (Preemptive)\n4-Round Robin\n5-Priority Scheduling (Non_Preemptive)\n6-Priority Scheduling (Preemptive)\n";
			int selection;
			cin >> selection;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid selection.\n";
				continue;
			}
			Scheduler h;


			switch (selection) {
			case 1:
				h.FCFS(p);
				break;
			case 2:
				h.Non_preemptive_SJF(p);
				break;
			case 3:
				h.Preemptive_SJF(p);
				break;
			case 5:
				for (int m = 0; m <= i; m++) {
					cout << "Enter Process{" << m << "}'S Priority:\n";
					cin >> l;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input. Please enter an integer.\n";
						m--;
						continue;
					}
					if (l == -1) {
						m--;
						break;
					}
					p.set_priority(l);
				}

				cout << "-----------------------------------------------------------------------------------------------------------\n";

				cout << "-----------------------------------------------------------------------------------------------------------\n|Process id      |      Process Arrival time       |       Process burst time    |        Priority        |\n";
				k = 0;
				while (k <= i) {
					cout << "-----------------------------------------------------------------------------------------------------------\n";
					try {
						cout << "|Process{" << k << "}                       " << p.get_arrival_time(k)
							<< "                              " << p.get_burst_time(k)
							<< "                        " << p.get_priority(k) << "            |\n";
					}
					catch (exception& e) {
						cout << "Error accessing process data: " << e.what() << endl;
					}
					k++;
				}
				cout << "-----------------------------------------------------------------------------------------------------------\n";

				h.PriorityScheduling(p);
				break;

			case 6:
				for (int m = 0; m <= i; m++) {
					cout << "Enter Process{" << m << "}'S Priority:\n";
					cin >> l;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input. Please enter an integer.\n";
						m--;
						continue;
					}
					if (l == -1) {
						m--;
						break;
					}
					p.set_priority(l);
				}

				cout << "-----------------------------------------------------------------------------------------------------------\n";

				cout << "-----------------------------------------------------------------------------------------------------------\n|Process id      |      Process Arrival time       |       Process burst time    |        Priority        |\n";
				k2 = 0;
				while (k2 <= i) {
					cout << "-----------------------------------------------------------------------------------------------------------\n";
					try {
						cout << "|Process{" << k2 << "}      |                 " << p.get_arrival_time(k2)
							<< "               |               " << p.get_burst_time(k2)
							<< "             |           " << p.get_priority(k2) << "            |\n";
					}
					catch (exception& e) {
						cout << "Error accessing process data: " << e.what() << endl;
					}
					k2++;
				}
				cout << "-----------------------------------------------------------------------------------------------------------\n";
				h.Preemptive_PriorityScheduling(p);
				break;

			case 4:
				h.Round_Robin(p);
				break;
			default:
				cout << "Out of bounds\n";
				break;
			}
cout << endl<<"Do you want to continue with same numbers? (1-yes, 0-no)\n";
			cin >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter 1 or 0.\n";
				continue;
			} if(b==1){
			    system("cls");
			goto jump;}
			cout << endl<<"Do you want to continue the program? (1-yes, 0-no)\n";
			cin >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter 1 or 0.\n";
				continue;
			}
			if (b == 0) {
				return 0;
			}
			system("cls");
		}

	}
	catch (exception& e) {
		cout << "An error occurred: " << e.what() << endl;
	}
}
