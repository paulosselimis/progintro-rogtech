#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

 
 using namespace std;
 
 
  int rational::gcd(int a, int b)  {
   if (b == 0)
   return a;
   return gcd(b, a % b); }

 rational::rational (int n, int d) { 
     
     nom=n/gcd(n, d); den=d/gcd(n, d);
 }
 
 rational operator + (const rational &x, const rational &y) {
  return rational((x.nom*y.den)+(y.nom*x.den), (x.den*y.den));
  
 }
 
 rational operator - (const rational &x, const rational &y) {
     return rational((x.nom*y.den)-(y.nom*x.den), (x.den*y.den));
 }
 
 rational operator * (const rational &x, const rational &y) {
     return rational(x.nom*y.nom, x.den*y.den);
 }
 
 rational operator / (const rational &x, const rational &y) {
     return rational(x.nom*y.den, x.den*y.nom);
 }
 
 std::ostream & operator << (std::ostream &out, const rational &x) {
     if(x.nom>0 && x.den<0) out << -x.nom << "/" << -x.den;
     else out << x.nom << "/" << x.den;
     return out;
 }
 
