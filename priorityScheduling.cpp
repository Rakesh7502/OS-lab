
#include<bits/stdc++.h>

using namespace std;

void completion(vector<vector<int>> &prior) {
    int n = prior.size();
    prior[0][4] = prior[0][0] + prior[0][3];
    prior[0][5] = prior[0][4] - prior[0][0];
    prior[0][6] = prior[0][5] - prior[0][3];

    for(int i=1; i<n; i++) {

        int index = i;
        int mini = prior[i][1];

        for(int j=index+1; j<n; j++) {
            if(prior[j][0] <= prior[i-1][4]) {
                if(prior[j][1] < mini) {
                    mini = prior[j][1];
                    index = j;
                }
            }
        }

        if(index != i) {
            swap(prior[index], prior[i]);
        }

        if(prior[i][0] <= prior[i-1][4]) {
            prior[i][4] = prior[i-1][4] + prior[i][3];
        } else {
            prior[i][4] = prior[i][0] + prior[i][3];
        }

        prior[i][5] = prior[i][4] - prior[i][0];
        prior[i][6] = prior[i][5] - prior[i][3];
    }
}

int main() {
	int n;
	cout<<"Enter the number of processors :  ";
	cin>>n;

	vector<vector<int>> prior(n, vector<int> (7, 0));
	cout<<endl<<"Enter arrival and Burst Timings of Processors :  "<<endl<<endl;
	int a,b;

	for(int i=0; i<n; i++) {
		cout<<"Enter Processor P"<<i+1<<" Arrival, Burst timing and Priority : ";
		cin>>prior[i][0]>>prior[i][3]>>prior[i][1];
        prior[i][2] = i;

	}

	sort(prior.begin(), prior.end());

    completion(prior);

    double atat = 0;
    double awt = 0;

    cout<<endl<<endl<<"Processors"<<"    Arrival time "<<"    Burst Time"<<" Priority "<<"  Completion Time "<<"  Turn Around Time "<<" Wait Time "<<endl;
	for(int i=0; i<n; i++) {
		cout<<"P"<<prior[i][2]+1<<"		"<<prior[i][0]<<"		"<<prior[i][3]<<"  		"<<prior[i][1]<<"    		"<<prior[i][4]<<" 	    	"<<prior[i][5]<<"    "<<prior[i][6]<<endl;
		atat += prior[i][5];
		awt += prior[i][6];
	}
    cout<<endl<<"Average Turn Around Time : "<<atat/n<<endl;
	cout<<"Average Wait Time : "<<awt/n<<endl<<endl;

}
