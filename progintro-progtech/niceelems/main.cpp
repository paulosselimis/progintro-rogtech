#include <iostream>
using namespace std;

int N, M, a[200][200];

bool palgram (int x) {
    for(int j=0; j<M; j++) {
        if(a[x][j]!=a[x][M-j-1]) return false;
    }
    return true;
}

bool palstil (int x) {
    for(int i=0; i<N; i++) {
        if(a[i][x]!=a[N-i-1][x]) return false;
    }
    return true;
}

int main () {
    cin >> N; cin >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> a[i][j];
            
        }
    }
    int vol=0, m=0;
    for(int i=0; i<N; i++) {
        if(palgram(i)) {m++; vol=vol+M; } 
    }
    
    for(int j=0; j<M; j++) {
        if(palstil(j)) vol=vol+N-m;
    }
    
    cout << vol << endl;
    
    
    
    
    
    return 0;
}