#include<bits/stdc++.h>

using namespace std;

void bubSort(vector<int> &arrival, vector<int> &burst, vector<string> & processors) {
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

void completeTime(vector<int> &completion, vector<int> &arrival, vector<int> &burst) {
	int n = arrival.size();

	for(int i=1; i<n; i++) {
		if(arrival[i] < completion.back()) {
			completion.push_back(completion.back() + burst[i]);
		}

		else {
			completion.push_back(arrival[i] + burst[i]);
		}
	}
}

void tat(vector<int>  &completion, vector<int> &arrival, vector<int> &turn) {
	for(int i=0; i<arrival.size(); i++) {
		turn.push_back(completion[i] - arrival[i]);
	}
}

void wtime(vector<int> &wait, vector<int> &turn, vector<int> &burst) {
	for(int i=0;  i < burst.size(); i++) {
		wait.push_back(turn[i] - burst[i]);
	}
}

int main() {
	int n;
	cout<<"Enter the number of processors :  ";
	cin>>n;

	vector<string> processors;
	vector<int> arrival, burst;
	cout<<endl<<"Enter arrival and Burst Timings of Processors :  "<<endl<<endl;
	int a,b;

	for(int i=0; i<n; i++) {
		cout<<"Enter Processor P"<<i+1<<" Arrival and Burst timings : ";
		cin>>a>>b;
		processors.push_back("P" + to_string(i+1));
		arrival.push_back(a);
		burst.push_back(b);
	}

	bubSort(arrival, burst, processors);

	vector<int> completion;

	completion.push_back(arrival[0]+burst[0]);

	completeTime(completion, arrival, burst);

	vector<int> turn;
	tat(completion, arrival, turn);

	vector<int> wait;
	wtime(wait, turn, burst);

	cout<<endl<<endl<<"Processors"<<"    Arrival time "<<"    Burst Time"<<" Completion Time"<<"  Turn Around Time "<<" Wait Time "<<endl;
	for(int i=0; i<n; i++) {
		cout<<processors[i]<<"		"<<arrival[i]<<"		"<<burst[i]<<"  		"<<completion[i]<<" 		"<<turn[i]<<" 		"<<wait[i]<<endl;
	}

	cout<<endl<<"Gauntt Chart : "<<endl;

	if(arrival[0] > 0)
		cout<<"Ideal"<< "  ";

	for(int i=0; i<n; i++) {

		cout<<processors[i] <<" ";
	}

	cout<<endl<<"Average Turn Around Time : "<<(double)accumulate(turn.begin(), turn.end(),0)/turn.size()<<endl;
	cout<<"Average Wait Time : "<<(double)accumulate(wait.begin(), wait.end(), 0)/turn.size()<<endl<<endl;

}
