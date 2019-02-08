#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "dna_list.h"
using namespace std;


int main(int argc, char const *argv[]) {
  string userFile, userName, userId ;
  cout<<"Please type in the name of your file that you want to read for DNA Analysis. *include .txt"<<endl;
  cin>>userFile;
  cout<<"What is your Name"<<endl;
  cin>>userName;
  cout<<"What is your Id"<<endl;
  cin>>userId;
  dna_list object1(userFile,userName,userId);
  return 0;
}
