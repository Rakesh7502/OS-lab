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

void completeTime(vector<int> &completion, vector<int> &arrival, vector<int> &burst, vector<string> &processors) {

	int miniBurst = burst[0], index = 0;
	int n = arrival.size();

	for(int i=1; i<n; i++) {
		if(arrival[i-1] == arrival[i]) {
			if(miniBurst > burst[i]) {
				index = i;
				miniBurst = burst[i];
			}
		}

		else break;
	}

	if(miniBurst != burst[0]) {
		swap(arrival[0], arrival[index]);
		swap(burst[0], burst[index]);
		swap(processors[0], processors[index]);
	}

	completion.push_back(arrival[0] + burst[0]);

	for(int i=1; i<n; i++) {
		if(arrival[i] <= completion.back()) {
			miniBurst = burst[i], index = i;
			for(int j = i; j<n; j++) {
				if(arrival[j] <= completion.back()) {
					if(miniBurst > burst[j]) {
						index = j;
						miniBurst = burst[j];
					}

					else if(miniBurst == burst[j]) {
						if(arrival[j] < arrival[index]) {
							miniBurst = burst[j];
							index = j;
						}
					}
				}

			}

			if(miniBurst != burst[i]) {
				swap(arrival[i], arrival[index]);
				swap(burst[i], burst[index]);
				swap(processors[i], processors[index]);
			}

			completion.push_back(completion.back() + burst[i]);

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
	vector<int> arrival;// = {5,2,4,1,3,1,2};
	vector<int> burst;// = {1, 1,3,10,4,8,6};
	cout<<endl<<"Enter arrival and Burst Timings of Processors :  "<<endl<<endl;
	int a,b;

	for(int i=0; i<n; i++) {
		processors.push_back("P" + to_string(i+1));
	}


	for(int i=0; i<n; i++) {
		cout<<"Enter Processor P"<<i+1<<" Arrival and Burst timings : ";
		cin>>a>>b;
		arrival.push_back(a);
		burst.push_back(b);
	}



	bubSort(arrival, burst, processors);


	vector<int> completion;

	completeTime(completion, arrival, burst, processors);

	vector<int> turn;
	tat(completion, arrival, turn);

	vector<int> wait;
	wtime(wait, turn, burst);

	cout<<endl<<endl<<"Processors"<<"    Arival time "<<"    Burst Time"<<" Completion Time"<<"  Turn Around Time "<<" Wait Time "<<endl;
	for(int i=0; i<n; i++) {
		cout<<processors[i]<<"		"<<arrival[i]<<"		"<<burst[i]<<"  		"<<completion[i]<<" 		"<<turn[i]<<" 		"<<wait[i]<<endl;
	}

	cout<<endl<<"Guntt Chart : "<<endl;

	if(arrival[0] > 0)
		cout<<"Ideal"<< "  ";

	for(int i=0; i<n; i++) {

		cout<<processors[i] <<" ";
	}

	cout<<endl<<"Average Turn Around Time : "<<accumulate(turn.begin(), turn.end(),0)/turn.size()<<endl;
	cout<<"Average Wait Time : "<<accumulate(wait.begin(), wait.end(), 0)/turn.size()<<endl<<endl;

}
