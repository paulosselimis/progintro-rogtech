#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    char a[27], ab[26], u[20], q;
    q='a';
    for(int i=0; i<26; i++) { ab[i]=q; q++; }
    cin.getline(a, 27);
    for(int i=0; i<27; i++) {
        for(int j=0; j<27; j++){
         if(i==j) break;
         else if(a[i]==a[j]) {cout << "error" << endl; return 0;}
        }
    }
        for(int i=0; i<26; i++) {
            if(!(a[i]>='a' && a[i]<='z')) {cout << "error" << endl; return 0;}
        }
         cin.getline(u, 20);
        if(u[0]!='d') {
        
    
    while(true) {
        int m;
        int b=getchar();
        if(b==EOF) return 0;
        else if(b>='a' && b<='z') {
             m=b-'a';
            cout << a[m];
        }
        else if(b>='A' && b<='Z') {
             m=b-'A';
             char c = a[m]-'a'+'A';
             cout << c;
        }
        else putchar(b);
    }
        }
        else {
            while(true) {
        int m, n;
        int b=getchar();
        if(b==EOF) return 0;
        else if(b>='a' && b<='z') {
             for(int i=0; i<27; i++) { if(a[i]==b) { n=i; break; }}
            cout << ab[n];
        }
        else if(b>='A' && b<='Z') {
             b=b-'A'+'a';
             for(int i=0; i<27; i++) { if(a[i]==b)  { n=i; break; } }
             char c = ab[n] -'a'+'A';
             cout << c;
        }
        else putchar(b);
    }
            
        }
    
    return 0;
}