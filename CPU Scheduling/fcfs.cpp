#include<bits/stdc++.h>
using namespace std;

#define N 3

struct process {
	int id, at, bt, ct, tat, wt;
};

bool comp(process &p1, process &p2) {
	return p1.at < p2.at;
}

int main() {
	vector<process> p(N);
	for(int i=0;i<N;i++) {
		cin >> p[i].id >> p[i].at >> p[i].bt;
	}

	sort(p.begin(), p.end(), comp);

	p[0].ct = p[0].bt;
	p[0].tat = p[0].bt;
	p[0].wt = 0;

	for(int i=1;i<N;i++) {
		p[i].ct = p[i - 1].ct + p[i].bt;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}

	int tatAvg = 0, wtAvg = 0;

	cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
	for(int i=0;i<N;i++) {
		cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
		tatAvg += p[i].tat;
		wtAvg += p[i].wt;
	}

	tatAvg /= N;
	wtAvg /= N;

	cout << "Average TAT: " << tatAvg << "\n";
	cout << "Average WT: " << wtAvg << "\n";

	return 0;
}
