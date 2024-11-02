#include <stdio.h>
#include <math.h>
#include <iostream>

class Vetor
{
private:
    int _x; //coordenadas (_x, _y)
    int _y;
public:
 Vetor(int x = 0, int y = 0){
     _x = x;
     _y = y;
};
 friend Vetor operator+(const Vetor& a, const Vetor& b)
 {//soma ax+bx, ay+by
   int aux_x, aux_y;
   aux_x = a._x+b._x;
   aux_y = a._y+b._y;
   return Vetor(aux_x, aux_y);
 };
 friend Vetor operator-(const Vetor& a, const Vetor& b)
 {  
   int aux_x, aux_y;
   aux_x = a._x-b._x;
   aux_y = a._y-b._y;
   return Vetor(aux_x, aux_y);
 };
 friend int operator*(const Vetor& a, const Vetor& b) //produto esclar
 {
  
   int result = (a._x*b._x) + (a._y* b._y);
   
   return result;
 };
 friend double operator^(const Vetor& a, const Vetor& b)//produtor vetorial
 {
  
   return a._x*b._y - a._y*b._x;
 };
 friend double operator<(const Vetor& a, const Vetor& b)//angulo
 {
   
   double angulo;
   double prod_escalar = (a._x*b._x) +(a._y* b._y);
   double magnitude = sqrt(a._x*a._x+ a._y*a._y) * sqrt(b._x*b._x+ b._y*b._y);
   if( prod_escalar == 0 || magnitude == 0)
   {
      angulo = 0;
   }
   else
  { 
      angulo = acos(prod_escalar/magnitude);
   }
   angulo *= 57.2958;
   return angulo;
 };
 double abs()
 {
   double v;
   v  = double(sqrt(_x*_x+ _y*_y));
   return v;
 };
 friend std::ostream& operator<<(std::ostream  &out, const Vetor &a){

    out << "(" << a._x << "," << a._y << ")";
   return out;
 };

};

int main(){
Vetor v;
std::cout << v << std::endl;

v = v+Vetor(1, 2);
std::cout << v << std::endl;

v = v+Vetor(1, 2);
std::cout << v << std::endl;

v = v-Vetor(1, 6);
std::cout << v << std::endl;

v = v*Vetor(3, 2);
std::cout << v << std::endl;

v= v^Vetor(-4501, 9002);
std::cout << v << std::endl;

double c = v.abs();
std::cout << v.abs() << std::endl;

return 0;
}
