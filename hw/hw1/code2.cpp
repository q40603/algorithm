#include <iostream>
using namespace std;
long long cycle(long long m) {
    long long a = 0, b = 1, c = a + b;
    int i=0;
    for (i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) {
        	break;	
		}
    }
    return i+1;
}

long long fib(long long n, long long m) {
    long long r = n % cycle(m);
    long long a = 0;
    long long b = 1;
    long long ans = r;
    for (int i = 1; i < r; i++) {
        ans = (a + b) % m;
        a = b;
        b= ans;
    }
    return ans % m;
}

int main() {
	int times;
	cin>>times;
	while(times--){
    	long long a, m=29989;
    	cin >> a ;
    	cout << fib(a, m) << '\n';			
	}

}
