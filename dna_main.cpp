#include "dna_list.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[]) {
  string userFile, userFirst, userLast, userId ;
  int decision = 1;
  while (decision==1) {
    cout<<"Please type in the name of your file that you want to read for DNA Analysis. *include .txt"<<endl;
    cin>>userFile;
    cout<<"What is your First Name"<<endl;
    cin>>userFirst;
    cout<<"What is your Last Name"<<endl;
    cin>>userLast;
    cout<<"What is your Id"<<endl;
    cin>>userId;
    dna_list object1(userFile,userFirst, userLast,userId);
    cout<<"Do you want to create another list? Type 1 for YES & 0 for NO"<<endl;
    cin>>decision;
  }

  return 0;
}
