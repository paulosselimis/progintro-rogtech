#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int N, a[50000], b[50000];
    int m=0;
    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];
    sort(a, a+N);
    sort(b, b+N);
    
    
     for(int i=0; i<N; i++) {
      if(a[i]!=b[i]) { cout << "no "; m++; break; }   
     }
     if(m==0) { cout << "yes" << endl; return 0; }
     else if(m==1)  {
         for(int i=0; i<N; i++) {
             if(a[i]==b[i]) continue;
             else if(a[i]<b[i]) { cout << a[i] << " "; break; }
             else if(a[i]>b[i]) { cout << b[i] << " "; break; }
         }
         for(int i=N-1; i>=0; i--) {
             if(a[i]==b[i]) continue;
             else if(a[i]<b[i]) { cout << b[i] << endl; break; }
             else if(a[i]>b[i]) {cout << a[i] << endl; break; }
             
         }
         
         
     }
         
    
    
    return 0;
}
