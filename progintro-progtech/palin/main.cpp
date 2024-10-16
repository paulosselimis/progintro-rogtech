#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
int k, i, m=0,l, f=1, sum=0;
char u, o;
char a[50];
double p, N;
cin>>N;
o=getchar();
for(k=0; k<N; k++){
f=1;
cin.getline(a,50);
m=strlen(a);
if(m==0){cout<<"empty"<<endl;f=2;}
if(m>20){
cout<<"error"<<endl;

}
else
{
for(l=0; l<m; l++){
if(a[l]!=a[m-l-1]){
f=0;
break;}
}
}
if(f==0) {
cout<<"no"<<endl;
}
else if(f==1)
{ sum++;
cout<<"yes"<<endl;}

}
p=(sum/N)*100;
printf("%0.3lf\n", p);
return 0;
}