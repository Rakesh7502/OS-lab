#include<bits/stdc++.h>

using namespace std;


void bubSort(vector<int> &arrival, vector<int> &burst, vector<string> &processors) {
	int n = arrival.size();
	for(int i=0; i<n-1; i++) {
		for(int j = 0; j<n-1-i; j++) {
			if(arrival[j] > arrival[j+1]) {
				swap(arrival[j], arrival[j+1]);
				swap(burst[j], burst[j+1]);
				swap(processors[j], processors[j+1]);
			}
		}
	}
}

int main() {
    int n;
    cout<<"Enter the number of processors : "<<endl;
    cin>>n;

    vector<int> arrival(n), burst(n);
    vector<string>  processors(n);

    int a,b;
    for(int i=0; i<n; i++) {
        cout<<"Enter Arrival and Burst time of P"<<i+1<<" : ";
        cin>>a>>b;
        processors[i] = "p" + to_string(i+1);
        arrival[i] = a;
        burst[i] =  b;
    }

    bubSort(arrival, burst, processors);

    int quantum;

    cout<<"Enter Time Quantum of the for this Round Robin Scheduling : ";
    cin>>quantum;

    vector<int> completion(n), tat(n), wait(n);
    vector<int> remaining(burst.begin(), burst.end());
    vector<int> visited(n, 0);


    queue<int> que;

    que.push(0);
    visited[0] = 1;
    int time = arrival[0];


//    if(burst[0] >= quantum) {
//        burst[0] -= quantum;
//        time = quantum;
//    }
//    else {
//        time = burst[0];
//        burst[0] = 0;
//    }

    int complete, index;

    while(!que.empty()) {
        index = que.front();
        que.pop();
        cout<<processors[index]<<" ";

        if(burst[index] >= quantum) {
            burst[index] -= quantum;
            time += quantum;
        }

        else {
            time += burst[index];
            burst[index] = 0;
        }

        for(int i=0; i<n; i++) {
            if(arrival[i] <= time && visited[i] == 0 && burst[i] > 0) {
                que.push(i);
                visited[i] = 1;
            }
        }

//
//        if(burst[index] == 0) {
//
//            continue;
//        }




        if(burst[index] > 0) {
            que.push(index);
            visited[index] = 1;
        }

        else {
            visited[index] = 0;
        }



        if(burst[index] == 0) {
            completion[index] = time;
            tat[index] = time - arrival[index];
            wait[index] = tat[index] - remaining[index];
        }

    }

    cout<<endl;
    cout<<"Process"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"Completion Time"<<"\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
    double avg = 0, tt = 0;
    for(int i=0; i<n; i++) {
        cout<<processors[i]<<"\t\t"<<arrival[i]<<"\t\t"<<remaining[i]<<"\t\t"<<completion[i]<<"\t\t"<<tat[i]<<"\t\t"<<wait[i]<<endl;
        avg = avg + wait[i];
        tt = tt + tat[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;



}
