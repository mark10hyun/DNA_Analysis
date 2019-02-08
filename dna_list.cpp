#include "dna_list.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <cstdlib>
using namespace std;
char  nucA= 'A', nucC='C', nucT='T', nucG='G';
string bigramAA= "AA", bigramAC= "AC", bigramAT="AT", bigramAG= "AG",
             bigramCA= "CA", bigramCC= "CC", bigramCT= "CT", bigramCG= "CG";

dna_list::dna_list(string file, string inputFirst, string inputLast, string inputId)
{

   filename = file;
   name=inputFirst+" "+inputLast;
   id=inputId;
   freqNucleotide();
   freqBigram();
   listMean();
   listVar();
   listStDev();
   toSummaryFile();
   readSummaryFile(); //change it to read the summaryfile LATER

}

dna_list::~dna_list()
{

}

void dna_list::freqNucleotide()
{
  string line;
  ifstream dnaFile (filename); //Reads the User's DNA File
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    lineSum++;
    for(int i = 0; i < line.size(); i++)
    {
      list_sum++;
      switch(toupper(line[i])) //used to count the frequencies of each nucleotide & adds to Counter
      {
        case 'A':countA++;
            break;
        case 'C': countC++;
                    break;
        case 'G': countG++;
                  break;
        case 'T': countT++;
                  break;
        default: cout<<"No similar nucleotides"<<endl;
                  break;
      }
    }
  }
  dnaFile.close();
}

else
{
  cout << "Unable to open file";
}
/*
cout<<"Count for A: "<<countA<<endl;
cout<<"Count for T: "<<countT<<endl;
cout<<"Count for C: "<<countC<<endl;
cout<<"Count for G: "<<countG<<endl;
*/

}

void dna_list:: freqBigram() //finds total occurence of each bigram
{
  string line;
  ifstream dnaFile (filename); //Reads the User's DNA File
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    for(int i = 0; i < line.size(); i++)
    {
      char nextchar= toupper(line[i+1]);
      if(toupper(line[i])== 'A' && nextchar=='A')
      {
          countAA++;
      }
      if(toupper(line[i])=='A' && nextchar=='C')
      {
        countAC++;
      }
      if(toupper(line[i])== 'A' && nextchar=='T')
      {
        countAT++;
      }
      if(toupper(line[i])=='A' && nextchar=='G')
      {
        countAG++;
      }
      if(toupper(line[i])=='C' && nextchar=='A')
      {
        countCA++;
      }
      if(toupper(line[i])=='C' && nextchar=='C')
      {
        countCC++;
      }
      if(toupper(line[i])=='C'&& nextchar=='T')
      {
        countCT++;
      }
      if(toupper(line[i])=='C' && nextchar=='G')
      {
        countCG++;
      }
    }
  }
  dnaFile.close();
}

else
{
  cout << "Unable to open file";
}
/*
cout<<"Count for AA: "<<countAA<<endl;
cout<<"Count for AC: "<<countAC<<endl;
cout<<"Count for AT: "<<countAT<<endl;
cout<<"Count for AG: "<<countAG<<endl;
cout<<"Count for CA: "<<countCA<<endl;
cout<<"Count for CC: "<<countCC<<endl;
cout<<"Count for CT: "<<countCT<<endl;
cout<<"Count for CG: "<<countCG<<endl;
*/
}
void dna_list:: listMean()
{
  list_mean = list_sum/lineSum;
 cout<<"list mean: "<< list_mean<<endl;

}
void dna_list:: listVar()
{
  list_variance = pow(list_sum-list_mean, 2)/list_sum;
  cout<<"list Variance: "<<list_variance<<endl;


}
void dna_list:: listStDev()
{
  list_standDev= sqrt(list_variance);
  cout<<"list Standard Deviation: "<<list_standDev<<endl;


}
void dna_list::probNucleotide()
{
   probA = countA/list_sum;
   probC = countC/list_sum;
   probT = countT/list_sum;
   probG= countG/list_sum;
}
void dna_list::probBigram()
{
  probAA= countAA/list_sum;
  probAC=countAC/list_sum;
  probAT=countAT/list_sum;
  probAG=countAG/list_sum;
  probCA=countCA/list_sum;
  probCC=countCC/list_sum;
  probCT= countCT/list_sum;
  probCG=countCG/list_sum;
}
void dna_list:: GaussianDist()
{
  totalGDLine=1000;
  srand(time(0));

}
void dna_list::toSummaryFile()
{
  ofstream summaryFile ("MarkHyun.txt");
  if (summaryFile.is_open())
  {
    summaryFile << name<<endl;
    summaryFile << id<<endl;
    summaryFile<<"Your DNA List Summary "<<endl;
    summaryFile<<endl;
    summaryFile<<endl;
    summaryFile<<"Sum of total nucleotides in your DNA List: "<<list_sum<<endl;
    summaryFile<<"Mean of your DNA List: "<<list_mean<<endl;
    summaryFile<<"Variance of your DNA List: "<< list_variance<<endl;
    summaryFile<<"Standard Deviation of you DNA List: "<<list_standDev<<endl;
    summaryFile.close();
  }
  else cout << "Unable to open file";
}
void dna_list::readSummaryFile()
{
  string line;
  ifstream dnaFile ("MarkHyun.txt"); //Reads the User's DNA File
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    cout << line << '\n';
  }
  dnaFile.close();
}

else
{
  cout << "Unable to open file";
}

}
