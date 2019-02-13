#include "dna_list.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
char  nucA= 'A', nucC='C', nucT='T', nucG='G';
string bigramAA= "AA", bigramAC= "AC", bigramAT="AT", bigramAG= "AG",
             bigramCA= "CA", bigramCC= "CC", bigramCT= "CT", bigramCG= "CG";
*/
dna_list::dna_list(string file, string inputFirst, string inputLast, string inputId) //overloaded constructor
{
   filename = file;
   name=inputFirst+" "+inputLast;
   id=inputId;

   freqNucleotide();//Counting the total occurence of each nucleotide in provided DNA list
   freqBigram();//Counting the total occurence of each nucleotide in provided DNA list
   listMean();//Calculating mean of provided DNA list
   listVar();//Calculating variance of provided DNA list
   listStDev();//Calculating standard deviation of provided DNA list
   probNucleotide(); //Finding the probaility of the occurence of each nucleotide
   probBigram(); //Finding the probability of the occurence of each Bigram
   toSummaryFile();//Writing the initial Summary with name and ID and stats of list provided
   GaussianDist();//Calculation to create 1000 randomly generated DNA strings.
   freqGDtoSummary();
   readSummaryFile(); //Read summary file with 1000 randomly generated DNA Strings.
}

dna_list::~dna_list() //deconstructor
{
}

void dna_list::freqNucleotide() //Counts the number of occurences of each nucleotide [A,C,G,T]
{
  string line;
  ifstream dnaFile (filename); //Reads the User's DNA File
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    lineSum++; //counts number of lines in file
    for(int i = 0; i < line.size(); i++)
    {
      list_sum++; //counts number of total nucleotides in file.
      switch(toupper(line[i])) //used to count the frequencies of each nucleotide & adds to Counter
      {
        case 'A':
                  countA++;
                  break;
        case 'C':
                  countC++;
                  break;
        case 'G':
                  countG++;
                  break;
        case 'T':
                  countT++;
                  break;
        default:
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

void dna_list:: freqBigram() //finds total occurence of each bigram [AA,AC,AT,AG,CA,CC,CT,CG]
{
  string line;
  ifstream dnaFile (filename); //Reads the User's DNA File
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    for(int i = 0; i < line.size(); i++)
    {
      char nextchar= toupper(line[i+1]); // toupper() - making all nucleotides in file upper in order for easier comparison.
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
void dna_list:: listMean()//finds the mean of entire file
{
  list_mean = list_sum/lineSum;
// cout<<"list mean: "<< list_mean<<endl;

}
void dna_list:: listVar()//finds the Variance of entire file
{
  list_variance = pow(list_sum-list_mean, 2)/list_sum;
//  cout<<"list Variance: "<<list_variance<<endl;


}
void dna_list:: listStDev() //finds the standard deviation of entire file
{
  list_standDev= sqrt(list_variance);
  //cout<<"list Standard Deviation: "<<list_standDev<<endl;


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
  freqA=0;
  freqC=0;
  freqG=0;
  freqT=0;
  ofstream appendToFile;
  appendToFile.open("MarkHyun.txt",ios::app);
  appendToFile<<"|1000 Randomly generated DNA strings|"<<endl;
  totalGDLine=0;
  srand(time(0));
  while(totalGDLine<1000) //setting the total amount of lines for Gaussian Distibrution
  {
    //cout<<totalGDLine<<endl;
    rand_a = double(rand())/ double(RAND_MAX); //generates random number from 0 to 1
  //  cout<<rand_a<<"  -rand a"<<endl;
    rand_b = double(rand())/double(RAND_MAX);
  //  cout<<rand_b<<"  -rand b"<<endl;
    box_muller = sqrt(-2 *log(rand_a)) * cos(2*3.14* rand_b); //C
  //  cout<<box_muller<<"  box_muller"<<endl;

    rand_stringLength= list_standDev*box_muller+list_mean;//D
    rand_stringLength = (int) rand_stringLength;
    if(rand_stringLength>0)//condition to count only randomly generated numbers that have a string size.
    {
      //cout<<rand_stringLength<<"  length"<<endl;
      totalGDLine++;

     for(int i = 0; i <rand_stringLength; i ++) //loop for generating random nucleotides.
     {
       rand_nucleotide= rand()%4+0;
       switch (rand_nucleotide)
        {
         case 0:
                appendToFile <<"A";
                freqA++;
                break;
         case 1:
                appendToFile <<"C";
                freqC++;
                break;
         case 2:
                appendToFile <<"G";
                freqG++;
                break;
         case 3:
                appendToFile <<"T";
                freqT++;
                break;
        }
     }
   appendToFile<<endl;
    }
  }
appendToFile.close();
}
void dna_list::freqGDtoSummary()
{
  string line;
  ofstream freqGDToFile;
  ifstream addingTosummaryFile;


  if (addingTosummaryFile.is_open())
  {
    while ( getline (addingTosummaryFile,line) )
    {
      summaryLineCount++;
      if(summaryLineCount==30)//this condition will print the stats for the Gaussian freq nucleotide after Original summary.
      {
        freqGDToFile.open("markhyun.txt",ios::app);
        freqGDToFile<<"Relative frequencies for the 1000 random DNA Strings"<<endl;
        freqGDToFile<<"  Relative frequency of nucleotide A: "<< freqA<<endl;
        freqGDToFile<<"  Relative frequency of nucleotide C: "<< freqC<<endl;
        freqGDToFile<<"  Relative frequency of nucleotide T: "<< freqT<<endl;
        freqGDToFile<<"  Relative frequency of nucleotide G: "<< freqG<<endl;
        freqGDToFile<<endl;
        freqGDToFile.close();
      }
    }
  }

}

void dna_list::toSummaryFile()
{
  ofstream summaryFile ("markhyun.txt");
  if (summaryFile.is_open())
  {
    summaryFile<<endl;
    summaryFile << name<<endl;
    summaryFile << id<<endl;
    summaryFile<<endl;
    summaryFile<<"  |Your DNA List Summary| "<<endl;
    summaryFile<<" -------------------------" <<endl;
    summaryFile<<"  Total nucleotides in your DNA List: "<<list_sum<<endl;
    summaryFile<<"  Mean of your DNA List: "<<list_mean<<endl;
    summaryFile<<"  Variance of your DNA List: "<< list_variance<<endl;
    summaryFile<<"  Standard Deviation of your DNA List: "<<list_standDev<<endl;
    summaryFile<<endl;
    summaryFile<<" |Probabilities of Nucleotides|"<<endl;
    summaryFile<<"--------------------------------"<<endl;
    summaryFile<<"  Probability of nucleotide A: "<< probA<<endl;
    summaryFile<<"  Probability of nucleotide C: "<< probC<<endl;
    summaryFile<<"  Probability of nucleotide T: "<< probT<<endl;
    summaryFile<<"  Probability of nucleotide G: "<< probG<<endl;
    summaryFile<<endl;
    summaryFile<<"  |Probability of Bigrams|"<<endl;
    summaryFile<<" --------------------------"<<endl;
    summaryFile<<"  Probability of Bigram AA: "<< probAA<<endl;
    summaryFile<<"  Probability of Bigram AC: "<< probAC<<endl;
    summaryFile<<"  Probability of Bigram AT: "<< probAT<<endl;
    summaryFile<<"  Probability of Bigram AG: "<< probAG<<endl;
    summaryFile<<"  Probability of Bigram CA: "<< probCA<<endl;
    summaryFile<<"  Probability of Bigram CC: "<< probCC<<endl;
    summaryFile<<"  Probability of Bigram CT: "<< probCT<<endl;
    summaryFile<<"  Probability of Bigram AA: "<< probCG<<endl;
    summaryFile<<endl;
    summaryFile<<endl;
    summaryFile<<endl;
    summaryFile.close();
  }
  else
  {
    cout << "Unable to open file";
  }
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
