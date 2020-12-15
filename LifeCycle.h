#ifndef LifeCycle_H
#define LifeCycle_H

#include <iostream>
#include <string>
using namespace std;
class MyObject {
 public:
  static int numObjs;
  
   MyObject();
   MyObject(string n);
   MyObject(const MyObject& rhs);
   ~MyObject();

   string getName() const;
   void setName(const string& newName);

   friend ostream& operator<<(ostream& output, const MyObject&obj);
 private:
   string name;
   int id;
};

#endif 
