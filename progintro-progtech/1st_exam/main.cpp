#include <iostream>
using namespace std;

int dignum (int x) {
    int a=0;
    while (x>0) {
        x = x/10;
        a++;
    }
    
    return a;
}

int main () {
    int K, N[100], y, c, v, n;
    cin >> K;
    for(int i=0; i<K; i++) cin >> N[i];
    for(int i=0; i<K; i++) { y=dignum(N[i]);
    c=0; v=0;
    n=N[i];
    for(int o=0; o<y; o+=2) { c=c+ n%10; n=n/100; }
    for(int p=1; p<y; p+=2) { v=v+ (N[i]/10)%10; N[i]=N[i]/100; }
    if(c==v) cout << "yes" << endl;
    else cout << "no" << endl;
    
        
    }
    
    return 0;
}

