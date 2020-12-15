#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H


#include <iostream>
#include "Stack.h"
//#include <bits/stdc++.h>
//#include <stack>

using namespace std;

class postfixCalculator{

public:
  int calculate(string s);
  //postfixCalculator();
  int getTop() const;

private:
  Stack s;
};

#endif
