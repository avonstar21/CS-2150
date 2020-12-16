#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <float.h>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/*
*@author : Avni Garg
*@par the process
* a min variable is set to FLT max is updated everytime a value less than it is found and so is a min vector. we print the route of this min vector.
*/

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    vector<string> minVec;
    sort(dests.begin() + 1,dests.end());
    // TODO: YOUR CODE HERE
    /*
    *for each permutation?
    * print out the route
    * print out the distance in that route
*/
    float min = FLT_MAX;
    do{
      string start = dests[0];
      float dis =computeDistance(me,start,dests);
      if(dis < min){
	min = dis;
	minVec = dests;
      }
      // cout<< "Distance: " <<  << endl;
      //printRoute(start,dests);
      //cout<<endl;
      
    }while(next_permutation(dests.begin()+1,dests.end()));
    cout << "Minimum path has distance " << min << ": ";
    string start = minVec[0];
    printRoute(start,minVec);
    cout << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  //MiddleEarth ans = me;
  float distance = 0.0;
  //distance += me.getDistance(start,dests[1]);
  for(int i = 0; i < dests.size() - 1; i++){
    distance += me.getDistance(dests[i],dests[i+1]);
  }
  distance += me.getDistance(dests[dests.size()-1],start);
  return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  //cout << start << " -> ";
  for(int i = 0; i < dests.size(); i++){
    cout << dests.at(i) << " -> ";
  }
  cout << start;
}
