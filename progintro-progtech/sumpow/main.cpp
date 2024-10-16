#include <iostream>
#include <cmath>
using namespace std;
int main () {
int a[10], i, x, k, N, m, n;
cin>>N;
for(i=0; i<=9; i++)
a[i]=pow(i, N);
for(m=0; m<=99999999; m++){
n=m; k=0;

while(n>0){
x=n%10;
k=k+a[x];
n=n/10;}
if(m==k) cout << m << endl;


}
return 0;
}
