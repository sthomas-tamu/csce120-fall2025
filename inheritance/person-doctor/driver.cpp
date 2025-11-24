#include "Doctor.h"

#include <iostream>

int main() {
   Person* p = new Person("George", 22);
   std::cout << "p: " << *p << std::endl;

   Doctor* d = new Doctor("Sam", 37, "surgeon");
   std::cout << "d: " << *d << std::endl;
   d->setAge(45);
   std::cout << "updated age for d: " << *d << std::endl;

   std::cout << std::endl;
 
   Person* w;
   std::cout << "setting w = p" << std::endl;
   w = p;
   std::cout << "w: " << *w << std::endl;

   std::cout << std::endl;

   std::cout << "setting w = d" << std::endl;
   w = d;
   std::cout << "w: " << *w << std::endl;

   delete p;
   delete d;
}
