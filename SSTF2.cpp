#include <bits/stdc++.h>
using namespace std;
int main(){
	int len;
	cin>>len;
	vector <int> request_seq;
	for(int i=0;i<len;i++){
		int e;
		cin>>e;
		request_seq.push_back(e);
	}
	int head_pos;
	cin>>head_pos;
	sort(request_seq.begin(),request_seq.end());
	int seek_op = 0;
	int j = upper_bound(request_seq.begin(),request_seq.end(),head_pos)-request_seq.begin();
	int i = j-1,curr;
	if(abs(head_pos-request_seq[j])<abs(head_pos-request_seq[i])){
		cout<<request_seq[j]<< " ";
		seek_op+=abs(head_pos-request_seq[j]);
		curr = j;
		j++;
	}
	else{
		cout<<request_seq[i]<<" ";
		seek_op+=abs(head_pos-request_seq[i]);
		curr = i;
		i--;
	}
	while(i > -1 and j<len){
		int jcurr = abs(request_seq[curr]-request_seq[j]);
		int icurr = abs(request_seq[curr]-request_seq[i]);
		if(icurr<jcurr){
			cout<<request_seq[i]<<" ";
			seek_op+=abs(icurr);
			curr = i;
			i--;
		}
		else{
			cout<<request_seq[j]<<" ";
			seek_op+=abs(jcurr);
			curr = j;
			j++;
		}
	}
	while(i > -1){
		cout<<request_seq[i]<<" ";
		seek_op+=abs(request_seq[curr]-request_seq[i]);
		curr = i;
		i--;
	}
	while(j<len){
		cout<<request_seq[j]<<" ";
		seek_op+=abs(request_seq[curr]-request_seq[j]);
		curr = j;
		j++;
	}
	cout<<"\nTotal number of seek operations: "<<seek_op<<endl;
	return 0;
}
