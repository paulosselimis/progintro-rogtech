#include <iostream>

 using namespace std;

 template <typename T>
 class stack {
 public:
 stack (int size) { data = new T[size]; count = 0; q=size;  }
 stack (const stack &s) { data = new T[s.q]; count=s.count; for(int i=0; i<s.count; i++) data[i] = s.data[i]; }
 ~stack () { delete [] data; }
 const stack & operator = (const stack &s) {delete [] data; data = new T[s.q]; count=s.count; for(int i=0; i<s.count; i++) data[i] = s.data[i]; return *this; }

 bool empty () { return count == 0; }
 void push (const T &x) { data[count++] = x; }
 T pop () { return data[--count]; }
 int size () { return count; }

 friend ostream & operator << (ostream &out, const stack &s) {
     if(s.count==0) out << "[]";
     else if(s.count==1) out << "[" << s.data[0] << "]";
     else { out << "["; for(int i=0; i<s.count-1; i++) out << s.data[i] << ", ";
     out << s.data[s.count-1] << "]";
     }
     return out;
 }

 private:
    T *data;
	int count, q;
 };
 
#ifndef CONTEST
int main () {
stack<int> s(10);
 cout << "s is empty: " << s << endl;
 s.push(42);
 cout << "s has one element: " << s << endl;
 s.push(17);
 s.push(34);
 cout << "s has more elements: " << s << endl;
 cout << "How many? " << s.size() << endl;    
 stack<int> t(5);
 t.push(7);
 cout << "t: " << t << endl;
 t = s;
 cout << "popping from s: " << s.pop() << endl;

 s.push(8);
 stack<int> a(s);
 t.push(99);
 a.push(77);
 cout << "s: " << s << endl;
 cout << "t: " << t << endl;
 cout << "a: " << a << endl;
  // now with doubles...
 stack<double> c(4);
 c.push(3.14);
 c.push(1.414);
 cout << "c contains doubles " << c << endl;
 // and with characters...
 stack<char> k(4);
 k.push('$');
 cout << "k contains a character " << k << endl;

    
    
    
}
#endif


