#include <iostream>
using namespace std;
int N, M, a[100][100];

int max_stil(int y) {
    int x = a[0][y];
    for(int i=1; i<N; i++){
        if(a[i][y]>x) x=a[i][y];
    }
    return x; }
    
    int min_gram(int y) {
    int x = a[y][0];
    for(int i=1; i<M; i++){
        if(a[y][i]<x) x=a[y][i];
    }
    return x;
         
}

int main() {
    int b;
    
    cin >> N; cin >> M;
    for(int i=0; i<N; i++){
        for(int o=0; o<M; o++) {
            cin >> a[i][o];
    }}
    b=max_stil(0);
    for(int o=1; o<M; o++) {
        if(max_stil(o)<b) b=max_stil(o);
    }
    cout << b << endl;
    
    b=min_gram(0);
    for(int i=1; i<N; i++) {
        if(min_gram(i)>b) b=max_stil(i);
    }
    cout << b << endl;
    
    
    return 0;
}