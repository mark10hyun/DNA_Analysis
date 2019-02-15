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
  //will continue to until user decides to stop
  while (decision==1) {
    //file name for reading dna file.
    cout<<"Please type in the name of your file that you want to read for DNA Analysis. *include .txt"<<endl;
    cin>>userFile;
    //user's First name for writing to new txt file
    //split first and last name to avoid white space error in cin.
    cout<<"What is your First Name (*FIRST ONLY*)"<<endl;
    cin>>userFirst;
    //user's Last name for writing to new txt file
    cout<<"What is your Last Name (*LAST ONLY*)"<<endl;
    cin>>userLast;
    //user's I.D for writing to new txt file
    cout<<"What is your school I.D"<<endl;
    cin>>userId;
    dna_list object1(userFile,userFirst, userLast,userId);
    cout<<"Do you want to create another list? Type 1 for YES & 0 for NO"<<endl;
    //if decision is 0, program will exit
    cin>>decision;
    cout<<endl;
  }

  return 0;
}
