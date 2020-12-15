#include <iostream>
#include "postfixCalculator.h"
#include "StackNode.h"
#include "Stack.h"
#include <string>
//#include <stack>

using namespace std;

int postfixCalculator::calculate(string x){
  //s = new Stack();
  if(x == "+"){
    int a = s.top();
    //cout<< a << endl;
    s.pop();
    int b = s.top();
    //cout<< b << endl;
    s.pop();
    s.push(a+b);
    //cout<< s.top() << endl;
    return 0;
  }
  else if(x == "-"){
    int a = s.top();
    //cout<<a<<endl;
    s.pop();
    int b = s.top();
    //cout<<b<<endl;
    s.pop();
    s.push(b-a);
    //cout << s.top() << endl;
    return 0;
  }
  else if(x == "*"){
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    s.push(b*a);
  }
  else if(x == "/"){
int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    s.push(b/a);
  }else if(x == "~"){
    int a = s.top();
    s.pop();
    s.push(-1*a);
  }
  else{
    int j = std::stoi(x);
    s.push(j);
  }
  return 0;
}

int postfixCalculator::getTop() const{
  //cout<< s.top() << endl;
  return s.top();
}
