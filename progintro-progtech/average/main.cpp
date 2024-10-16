#include <iostream>
#include <cstdio>

using namespace std;
int N, M; double a[100][100];

double aver_gram(int x) {
    double aver, sum;
    sum = 0;
    for(int o=0; o<M; o++) sum = sum + a[x][o];
    aver = sum/M;
    return aver;
}

double aver_stil(int x) {
    double aver, sum;
    sum = 0;
    for(int i=0; i<N; i++) sum = sum + a[i][x];
    aver = sum/N;
    return aver;
}



int main() {
    cin >> N; cin >> M;
    for(int i=0; i<N; i++){
        for(int o=0; o<M; o++) {
            cin >> a[i][o];
    }}
    double b; 
    b=aver_gram(0);
     for(int i=1; i<N; i++) b=b+aver_gram(i);
     double aver_gram2 = b/(N*1.0);
     printf("%0.3lf\n", aver_gram2);
     
     b=aver_stil(0);
     for(int o=1; o<M; o++) b=b+aver_stil(o);
     double aver_stil2 = b/(M*1.0);
     printf("%0.3lf\n", aver_stil2);
    
    return 0;
}