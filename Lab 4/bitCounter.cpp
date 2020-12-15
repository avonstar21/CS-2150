#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int binRep(int n){
  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else if(n%2 == 1){
    return 1 + binRep(n/2);
  }else{
    return binRep(n/2);
  }
}

int toBase10(string input, int base1){
  int output10 = 0;
  int power = input.length() - 1;
  while(input.length() > 1){
    char split = input[0];
    //
    if(split == '0'){
      output10 += 0;
    }else if(split == '1'){
      output10 += 1 * pow(base1,power);
    }else if(split == '2'){
      output10 += 2 * pow(base1,power);
    }else if(split == '3'){
      output10 += 3 * pow(base1,power);
    }else if(split == '4'){
      output10 += 4 * pow(base1,power);
    }else if(split == '5'){
      output10 += 5 * pow(base1,power);
    }else if(split == '6'){
      output10 += 6 * pow(base1,power);
    }else if(split == '7'){
      output10 += 7 * pow(base1, power);
    }else if(split == '8'){
      output10 += 8 * pow(base1,power);
    }else if(split == '9'){
      output10 += 9 * pow(base1,power);
    }else{
      int convert = split - 55;
  output10 += convert * pow(base1, power);
    }
   
    power--;
    input = input.substr(1);
  }
  char split = input[0];
  if(split == '0'){
      output10 += 0;
    }else if(split == '1'){
    output10 += 1; 
    }else if(split == '2'){
    output10 += 2;
    }else if(split == '3'){
      output10 += 3;
    }else if(split == '4'){
      output10 += 4;
    }else if(split == '5'){
      output10 += 5;
    }else if(split == '6'){
      output10 += 6;
    }else if(split == '7'){
      output10 += 7;
    }else if(split == '8'){
      output10 += 8;
    }else if(split == '9'){
      output10 += 9;
    }else{
      int convert = split - 55;
       output10 += convert;
    }
  //int convert = split - 55;
  //ouput10 += convert;
  return output10;
}

string toBaseEntered(int convert, int baseEnd){
  string ans = "";
  while(convert >= baseEnd){
    int checker = convert%baseEnd;
    if(checker == 0){
      ans = "0" + ans;
    }else if(checker == 1){
      ans = "1" + ans;
    }else if(checker == 2){
      ans = "2" + ans;
    }else if(checker == 3){
      ans = "3" + ans;
    }else if(checker == 4){
      ans = "4" + ans;
    }else if(checker == 5){
      ans = "5" + ans;
    }else if(checker == 6){
      ans = "6" + ans;
    }else if(checker == 7){
      ans = "7" + ans;
    }else if(checker == 8){
      ans = "8" + ans;
    }else if(checker == 9){
      ans = "9" + ans;
    }else{
      char c = checker + '0';
      ans = c + ans;
    }
    convert = convert/baseEnd;
  }
  if(convert == 0){
      ans = "0" + ans;
    }else if(convert == 1){
      ans = "1" + ans;
    }else if(convert == 2){
      ans = "2" + ans;
    }else if(convert == 3){
      ans = "3" + ans;
    }else if(convert == 4){
      ans = "4" + ans;
    }else if(convert == 5){
      ans = "5" + ans;
    }else if(convert == 6){
      ans = "6" + ans;
    }else if(convert == 7){
      ans = "7" + ans;
    }else if(convert == 8){
      ans = "8" + ans;
    }else if(convert == 9){
      ans = "9" + ans;
    }else{
      char c = convert + 7+  '0';
      ans = c + ans;
  }
  return ans;
}

int main(int argc, char **argv){
  //char params = argv;
  string x = argv[1];
  int xy = stoi(x);
  int an = binRep(xy);
  cout<< x << " has " << an << " bit(s)" << endl;
  string convert = argv[2];
  string base1Catch = argv[3];
  int baseStart =stoi(base1Catch);
  string base2Catch = argv[4];
  int baseEnd = stoi(base2Catch);

  int midstep = toBase10(convert,baseStart);
  //cout<< "Midstep: " << midstep << endl;
  string endStep = toBaseEntered(midstep, baseEnd);
  cout<< convert << " (base " << baseStart << ") = " << endStep << " (base " << baseEnd << ")" << endl;
  return 0;
}
