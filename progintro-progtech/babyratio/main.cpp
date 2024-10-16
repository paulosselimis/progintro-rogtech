#include <iostream>
#ifndef CONTEST
#include "babyratio.hpp"
#endif

 
 using namespace std;
 
 
  int rational::gcd(int a, int b)  {
   if (b == 0)
   return a;
   return gcd(b, a % b); }

 rational::rational (int n, int d) { 
     
     nom=n/gcd(n, d); den=d/gcd(n, d);
 }

 rational rational::add (rational r) {
     return rational((nom*r.den)+(r.nom*den), (den*r.den));
 }
 
 rational rational::sub (rational r) {
     return rational((nom*r.den)-(r.nom*den), (den*r.den));
 }
 
  rational rational::mul (rational r) {
     return rational(nom*r.nom, den*r.den);
 }
 
  rational rational::div (rational r) {
     return rational(nom*r.den, den*r.nom);
 }
 
 void rational::print() {
     if(nom>0 && den<0) cout << -nom << "/" << -den;
     else cout << nom << "/" << den;
 }
 
 int main () {
     return 0;
 }
 
 
 
