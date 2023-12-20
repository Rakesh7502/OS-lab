
#include<bits/stdc++.h>

using namespace std;


void bubSort(vector<int> &arrival, vector<int> &burst, vector<string> &processors, vector<int> &priority) {
	int n = arrival.size();
	for(int i=0; i<n-1; i++) {
		for(int j = 0; j<n-1-i; j++) {
			if(arrival[j] > arrival[j+1]) {
				swap(arrival[j], arrival[j+1]);
				swap(burst[j], burst[j+1]);
				swap(processors[j], processors[j+1]);
				swap(priority[j], priority[j+1]);
			}
		}
	}
}

int main() {
    int n;
    cout<<"Enter the number of processors : "<<endl;
    cin>>n;

    vector<int> arrival(n), burst(n), priority(n);
    vector<string>  processors(n);

    int a,b;
    for(int i=0; i<n; i++) {
        cout<<"Enter Arrival and Burst time and priority of P"<<i+1<<" : ";
        cin>>a>>b;
        processors[i] = "p" + to_string(i+1);
        arrival[i] = a;
        burst[i]  =  b;
        cin>>priority[i];
    }

    vector<int> completion(n), tat(n), wait(n);

    int count = 0, smallest,end;
    bubSort(arrival, burst, processors, priority);
    bool first = true;
    int totalBurst = accumulate(burst.begin(), burst.end(), 0);
    vector<int> remaining(burst.begin(), burst.end());

    for(int time = arrival[0]; count != n; time++) {


        int mini = INT_MAX;
        for(int i=0; i<n; i++) {
            if(arrival[i] <= time) {
                if(priority[i] < mini && burst[i] > 0) {
                    mini = priority[i];
                    smallest = i;
                }
            }
        }

        burst[smallest]--;


        if(burst[smallest] == 0) {
            count++;
            end = time+1;
            completion[smallest] = end;
            tat[smallest] = end - arrival[smallest];
            wait[smallest] = tat[smallest] - remaining[smallest];
        }

        if(time > totalBurst) {
            cout<<"Please Enter Valid arrival and burst time"<<endl;
            break;
        }
    }

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
