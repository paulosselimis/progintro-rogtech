#include <iostream>

using namespace std;
int N, K, a[1000001];

int maxa(int x, int y) {
   if(x==y) return a[x];
   int max=a[x];
    for(int i=x; i<=y; i++) {
        if(max<a[i]) { max=a[i]; }
    }
    return max;
}

int main()
{
  cin >> N;
    cin >> K;
    for(int i=1; i<=N; i++) cin >> a[i];
    
    a[0]=0;
    int maxsum;
    maxsum=a[1] + maxa(K+1, N);
    if(maxsum<a[N]+maxa(1, N-K)) maxsum=a[N]+maxa(1, N-K);
    
    for(int i=2; i<N-K; i++) {
        
            if(maxa(1, i)+maxa(K+i, N)>maxsum) maxsum=maxa(1, i)+maxa(K+i, N);
            
        
    }
    cout << maxsum << endl;
    

   

    return 0;
}