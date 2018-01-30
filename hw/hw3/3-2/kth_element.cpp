#include<iostream>
#include<algorithm>
#define ull unsigned long long int
using namespace std;
ull cal(ull a[3],ull i){
	ull m=a[0]*i*i+a[1]*i+a[2];
	return m;
}
ull kth(ull *arr1,ull *arr2,ull m,ull n,ull k,
                         ull  st1 = 0,ull st2 = 0)
{
    if (st1 == m)
        return cal(arr2,st2 + k - 1);
    if (st2 == n)
        return cal(arr1,st1 + k - 1);
    if (k == 1)
        return (cal(arr1,st1) < cal(arr2,st2)) ?
            cal(arr1,st1) : cal(arr2,st2);
    int curr = k / 2;
    if (curr - 1 >= m - st1)
    {
        if (cal(arr1,m - 1) < cal(arr2,st2 + curr - 1))
            return cal(arr2,st2 + (k - (m - st1) - 1));
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }
    if (curr-1 >= n-st2)
    {
        if (cal(arr2,n-1) < cal(arr1,st1 + curr - 1))
            return cal(arr1,st1 + (k - (n - st2) - 1));
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
    }
    else
    {
        if (cal(arr1,curr + st1 - 1) < cal(arr2,curr + st2 - 1))
            return kth(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }
}
int main(){
	int times;
	cin>>times;
	while(times--){
		ull size;
		ull a[3],b[3];
		for(int i=0;i<3;i++){
			cin>>a[i];
		}
		for(int i=0;i<3;i++){
			cin>>b[i];
		}		
		cin>>size;
		cout<<kth(a,b,size,size,size)<<endl;
	}
	return 0;
}
