#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ChessBoardArray {
 protected:
 
 
 int *data;
 unsigned b, s, m;
 unsigned int loc(int i, int j) const { 
      int di=i-b, dj=j-b;
     if(( di % 2 == 0 &&  dj % 2 != 0) || ( di % 2 != 0 &&  dj % 2 == 0)) throw out_of_range("");
     
     if (di < 0 || di >= s || dj < 0 || dj >= s) throw out_of_range("invalid index");
     return (di*s + dj)/2; 
 }
 
 class Row {
 public:
 Row(ChessBoardArray &a, int i) : cba(a), row(i) {}
 int & operator [] (int i) const { return cba.select(row, i); }
 private:
 ChessBoardArray &cba;
 int row;
 };

 class ConstRow {
 public:
 ConstRow(const ChessBoardArray &a, int i) : cba(a), row(i) {}
 const int & operator [] (int i) const { return cba.select(row, i); }
 private:
 const ChessBoardArray &cba;
 int row;
 };

 public:
 ChessBoardArray(unsigned size = 0, unsigned base = 0) :  b(base), s(size) {if(size%2==0) { data=new int[(size*size)/2]; m=(size*size)/2;}
  else { data=new int[(size*size)/2+1]; m=(size*size)/2+1; }
}
 ChessBoardArray(const ChessBoardArray &a) : data(new int[a.m]), b(a.b), s(a.s), m(a.m) {
     for(unsigned i=0; i<m; ++i) data[i]=a.data[i]; 
 }
 ~ChessBoardArray() { delete [] data; }

 ChessBoardArray & operator = (const ChessBoardArray &a) {
     delete [] data;
     b=a.b;
     s=a.s; m=a.m;
     data = new int[m];
     for(unsigned i=0; i<m; ++i) data[i]=a.data[i];
     return *this;
 }

 int & select(int i, int j) { return data[loc(i, j)]; }
 const int & select(int i, int j) const { return data[loc(i, j)]; }
 
 const Row operator [] (int i) { return Row(*this, i); }
 const ConstRow operator [] (int i) const { return ConstRow(*this, i); }

 friend ostream & operator << (ostream &out, const ChessBoardArray &a) {
  for(int i=a.b; i<a.s+a.b; ++i) {
      for(int j=a.b; j<a.s+a.b; ++j) {
          if((i+j)%2==0) out << setw(4) << a.data[a.loc(i, j)];
          else out << setw(4) << "0";
          if(j==a.s+a.b-1) out << endl;
      }
  }
     return out;
 }
  
};














