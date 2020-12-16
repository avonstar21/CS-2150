#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <iterator>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
/**
 *@author : Avni Garg
 *@par general structure
 * read in the class list; create an adjacency matrix, enque on basis of lowest inDegree. print the queue.
*/
int main(int argc, char** argv){
  ifstream file(argv[1], ifstream::binary);
  map<string, int> classes;
  string g;
  int count = 0;
  while(getline(file,g)){
     // split into 2 strings, check if it is in the map, if not then add it in
    int pos = g.find(" ");
    string entry1 = g.substr(0,pos);
    string entry2 = g.substr(pos+1,pos);
    if(entry1 != "0" && entry2 != "0"){
    if(classes.count(entry1)>0 ){
      //cout<<entry1<<endl;
    }else{
      classes.insert({entry1,count});
      count++;
    }

    if(classes.count(entry2)>0){
      //cout<<entry2<<endl;
    }else{
      classes.insert({entry2,count});
      count++;
    }
    }else{
      break;
    }
  }
  //file.close();
  //printing list of classes

  /*map<string,int>::iterator out = classes.begin();
  while(out != classes.end()){
    cout << out->first << ": " << out->second << endl;
    out++;
    }*/

  
  int arrSize = classes.size();
  int adjacencyMatrix[arrSize][arrSize];
  for(int r = 0; r < arrSize; r++){
    for(int c = 0; c < arrSize; c++){
      adjacencyMatrix[r][c] = 0;
    }
  }
  file.close();
  //while not file end
  ifstream stardoc(argv[1],ifstream::binary);
  string line;
  while(getline(stardoc,line))
  {
    //read in 2 strings
    int pos = line.find(" ");
    string class1 = line.substr(0,pos);
    string class2 = line.substr(pos+1,pos);
    if(class1 != "0" && class2 != "0"){
      //cout << class1 << "---->" << class2 << endl;
    //get 'index' from map for both
    int x = classes[class1];
    // cout << x << endl;
    int y = classes[class2];
    //cout << y << endl;

    //store in int x and y

    //set adjacencyMatrix[x][y] = 1;
    adjacencyMatrix[x][y] = 1;
    //cout <<  adjacencyMatrix[x][y] << endl;
    }else{
      break;
    }
    //next
  }
  
  for(int r = 0; r < arrSize; r++){
    for(int c = 0; c < arrSize; c++){
      //cout<< adjacencyMatrix[r][c] << " ";
    }
    //cout << endl;
  }
  
  map<string,int>::iterator it = classes.begin();
  map<string, int> degreeCount;
  for(int check = 0; check < arrSize; check++){
    int deg = 0;
    for(int c = 0; c < arrSize; c++){
      if(adjacencyMatrix[c][check] == 1){
	deg++;
      }
    }
    string ins;
    while(it != classes.end()){
      if(check == classes[it->first]){
	ins = it->first;
	break;
      }
      it++;
    }
    degreeCount.insert({ins,deg});
    //cout << ins << ": " << deg << endl;
    it = classes.begin();
  }
  
  //sort degreeCount based on values first
  deque<string> q;
  map<string,int>::iterator topo = degreeCount.begin();
  map<string,int>::iterator finder = classes.begin();
  map<string,int>::iterator eraser;
  // cout << "doing topological sort" << endl;
  while(degreeCount.size() != 0){
    int min = degreeCount[topo->first];
    string enq = topo->first;
    topo++;
    //cout<< enq << endl;
    while(topo != degreeCount.end()){
      if(min > degreeCount[topo->first]){
	min = degreeCount[topo->first];
	enq = topo->first;
      }
      topo++;
    }
    topo = degreeCount.begin();
    //cout << topo->first << ": " << topo->second << endl;
    q.push_front(enq);
    sort(q.begin(),q.end());
    topo = degreeCount.begin();
    //cout << topo->first << ": " << topo->second << endl;
    //cout << q << endl;
    eraser  = degreeCount.find(enq);
    /* while(topo != degreeCount.end()){
      cout << topo->first << ": " << topo->second << endl;
      topo++;
      }*/
    // topo = degreeCount.begin();
    degreeCount.erase(eraser); //is not erasing
    topo = degreeCount.begin();
    /*cout<< "Eraser Check" << endl;
    while(topo != degreeCount.end()){
      cout << topo->first << ": " << topo->second << endl;
      topo++;
      }*/
    topo = degreeCount.begin();
    //cout << degreeCount.size() << endl;
    int dec = classes[enq];
    //cout << dec << endl;
    for(int m = 0; m < arrSize; m++){
      if(adjacencyMatrix[dec][m] == 1){
	while(finder != classes.end()){
	  if(m == classes[finder->first]){
	    degreeCount[finder->first]--;
	  }
	  finder++;
	}
      }
    }
  }
  // cout << "printing the queue" << endl;
  for(auto it = q.begin(); it != q.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
  /*
-go through degreeCount map
-find lowest indegree
-add to deque
-remove from degreeCount map
-traverse the adjacency list and update it
-find new indegree
-add the next lowest one, add , sort
-repeat until the degreeCount map is empty?

*/
}


