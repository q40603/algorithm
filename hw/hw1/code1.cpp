#include <iostream>
using namespace std;
#define m 29989

struct matrix {
    int a, b, c, d;
};

matrix origin{1, 1, 1, 0};

matrix mul(matrix A, matrix B) {
    matrix C;
    C.a = ((A.a%m)*B.a + (A.b%m)*B.c)%m;
    C.b = ((A.a%m)*B.b + (A.b%m)*B.d)%m;
    C.c = ((A.c%m)*B.a + (A.d%m)*B.c)%m;
    C.d = ((A.c%m)*B.b + (A.d%m)*B.d)%m;
    return C;
}

matrix pow(int x) {
    if(x <= 1)      return origin;
    if(x%2 == 1)    return mul(pow(x-1), origin);
    
    matrix tmp = pow(x/2);
    return mul(tmp, tmp);
}

int F(int n) {
    return pow(n).b;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << F(n) << endl;
    }
    
    return 0;
}
