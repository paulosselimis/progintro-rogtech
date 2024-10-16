#include <iostream>  
  
using namespace std;  
  
int main() {  
  int a[150][150], N;  
  cin >> N;  
    for(int i=0; i<N; i++) {  
      for(int j=0; j<N; j++){  
        cin >> a[i][j];  
      }  
    }  
    for(int h=0; h<=(N*N-1); h++) {  
      for(int i=0; i<N; i++) {  
        for(int j=0; j<N; j++) {  
          if(a[i][j]==h) {  
            i=N;  
            j=N;  
          }  
          else if((a[i][j]!=h) && (i==N-1) && (j==N-1)) {  
            cout << "no" << endl;  
            return 0;  
          }  
            
        }  
      }  
      }  
    int a1=0; int a2=0;  
    for(int i=0; i<N; i++) {  
      a1=a1+a[i][i];  
    }  
    for(int i=0; i<N; i++) {  
      a2=a2+a[i][N-1-i];  
    }  
    if(a1==a2) {  
      for(int i=0; i<N; i++) {  
        int r=0;  
        for(int j=0; j<N; j++) {  
          r+=a[i][j];  
        }  
        if(r==a1) continue;
        else { cout << "no" << endl;  
            return 0;}
      }
          for(int i=0; i<N; i++) {  
            int q=0;  
            for(int j=0; j<N; j++) {  
              q+=a[j][i];  
            }
            if(q==a1) continue;
             else { cout << "no" << endl;  
            return 0;}
          }
          cout << "yes" << endl;
    }
             else cout << "no" << endl;  
   
  return 0;  
} 