#include <iostream>
using namespace std;

int main() {
    int N, K, a[1000000];
    cin >> N; cin >> K;
    for(int j=0; j<N; j++) cin >> a[j];
    int i=0, x=0, k=0, o=0;
    while(i<N) { int sum=0;
    for(i; i<N; i++) { sum=sum+a[i];
    if(sum%K==0) x=i+1;
    }
    x=x-o;
    if(x>k) k=x;
    o++;
    if(k>=N-o) { cout << k << endl; return 0; }
    i=o;
    }
    
    cout << k << endl;
    
    
    return 0;
}

