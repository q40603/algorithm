#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	long long int num = 0;
	long long int Co = 0;
	long long int Neday = 0;
};

int Partition(Node *A, int p, int r) {//r是pivot也是最後一個index
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (A[j].Neday*A[r].Co < A[r].Neday*A[j].Co) {
			i = i + 1;//把i擴充1個
			if(i!=j){
				Node temp;
				temp = A[j];
				A[j] = A[i]; //擴充1格之後交換
				A[i] = temp;			
			}

		}
	}
	Node temp;
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
};
void Quicksort(Node *A, int p, int r) {
	int q;
	if (p < r) {
		q = Partition(A, p, r);
		Quicksort(A, p, q - 1);
		Quicksort(A, q + 1, r);
	}
};

int main() {
	int times;
	cin >> times;
	for (int l = 0; l < times; l++) {
		int JobNum = 0, totalday=0;
		cin >> JobNum;
		Node *Cost=new Node[JobNum];
		for (int i = 0; i < JobNum; i++) {
			cin >> Cost[i].Neday;
			Cost[i].num = i+1;
		}
		for (int i = 0; i < JobNum; i++) {
			cin >> Cost[i].Co;
		}
		Quicksort(Cost, 0, JobNum - 1);
		long long int Total_cost = 0;
		for (int i = JobNum - 1; i >= 0; i--) {
			for(int j=i-1;j>=0;j--){
				Total_cost +=Cost[i].Co*Cost[j].Neday;
			}
		}
		cout << Total_cost << endl;
		for (int i =0; i<JobNum; i++) {
			cout << Cost[i].num << " ";
		}
		cout << endl;
	}
	return 0;
}
