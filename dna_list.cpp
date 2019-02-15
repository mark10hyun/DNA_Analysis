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

//overloaded constructor
dna_list::dna_list(string file, string inputFirst, string inputLast, string inputId)
{
  filename = file;
   name=inputFirst+" "+inputLast;
   id=inputId;

   //Counting the total occurence of each nucleotide in provided DNA list
   freqNucleotide();

   //Counting the total occurence of each nucleotide in provided DNA list
   freqBigram();

   //Calculating mean of provided DNA list
   listMean();

   //Calculating variance of provided DNA list
   listVar();

   //Calculating standard deviation of provided DNA list
   listStDev();

   //Finding the probaility of the occurence of each nucleotide
   probNucleotide();

   //Finding the probability of the occurence of each Bigram
   probBigram();

   /*
   Writing Summary with name and ID and stats of provided list to a newly created
   txt file called mark.txt
   */
   toSummaryFile();

   //Calculations to create 1000 randomly generated DNA strings.
   //Then appending to the end of mark.txt.
   GaussianDist();

   //Read summary file with 1000 randomly generated DNA Strings.
   readSummaryFile();
}

 //deconstructor
dna_list::~dna_list()
{
}

//Counts the number of occurences of each nucleotide [A,C,G,T]
void dna_list::freqNucleotide()
{
  //Reads the User's DNA File
  string line;
  ifstream dnaFile (filename);
  if (dnaFile.is_open())
  {
    while ( getline (dnaFile,line) )
    {
      //counts number of lines in file
      lineSum++;
      for(int i = 0; i < line.size(); i++)
      {
        //counts number of total nucleotides in file.
        list_sum++;
        //used to count the frequencies of each nucleotide & adds to Counter
        switch(toupper(line[i]))
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
}

//finds total occurence of each bigram [AA,AC,AT,AG,CA,CC,CT,CG]
void dna_list:: freqBigram()
{
  //Reads the User's DNA File
  string line;
  ifstream dnaFile (filename);
if (dnaFile.is_open())
{
  while ( getline (dnaFile,line) )
  {
    for(int i = 0; i < line.size(); i++)
    {
      // toupper() - making all nucleotides in file upper in order for easier comparison.
      char nextchar= toupper(line[i+1]);
      //if statements used to account for each nucleotide occurence
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
}

//finds the mean of entire file
void dna_list:: listMean()
{
  list_mean = list_sum/lineSum;
}
//finds the Variance of entire file
void dna_list:: listVar()
{
  list_variance = pow(list_sum-list_mean, 2)/list_sum;
}
//finds the standard deviation of entire file
void dna_list:: listStDev()
{
  list_standDev= sqrt(list_variance);
}
//Calculating probability of each nucleotide
void dna_list::probNucleotide()
{
   probA = countA/list_sum;
   probC = countC/list_sum;
   probT = countT/list_sum;
   probG= countG/list_sum;
}
//Calculating probability of each Bigram
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
//Calculating for generating 1000 Random DNA Strings
void dna_list:: GaussianDist()
{
  ofstream appendToFile;
  appendToFile.open("mark.txt",ios::app);
  appendToFile<<"|1000 Randomly generated DNA strings|"<<endl;
  appendToFile<<endl;
  //counts total # of random dna lines
  totalGDLine=0;
  //allows randon #'s to be distinct/unique
  srand(time(0));
  //setting the total amount of lines for Gaussian Distibrution
  while(totalGDLine<1000)
  {
    //generates random number from 0 to 1 inclusive
    rand_a = double(rand())/ double(RAND_MAX);
    rand_b = double(rand())/double(RAND_MAX);
    box_muller = sqrt(-2 *log(rand_a)) * cos(2*3.14* rand_b); //C
    rand_stringLength= list_standDev*box_muller+list_mean;//D
    rand_stringLength = (int) rand_stringLength;
    /*
     if-statement to count only randomly generated numbers that have a string size.
    So all 1000 randomly generated strings have a length/nucleotides.
    Will leave 0 empty DNA string when written to file.
    */
    if(rand_stringLength>0)
    {
      totalGDLine++;
      appendToFile<<"DNA String #"<<totalGDLine<<": ";
      //loop for generating random nucleotides withing the range of the random length generated.
     for(int i = 0; i <rand_stringLength; i ++)
     {
       //generates random number between 0 - 3
       rand_nucleotide= rand()%4+0;
       //switch assigns nucleotide to number. When random number is generated, the nucleotide associated with that number will be counted for and appended to mark.txt.
       switch (rand_nucleotide)
        {
         case 0:
                appendToFile <<"A";
                break;
         case 1:
                appendToFile <<"C";
                break;
         case 2:
                appendToFile <<"G";
                break;
         case 3:
                appendToFile <<"T";
                break;
        }
     }
   appendToFile<<endl;
    }
  }
  appendToFile<<endl;
    appendToFile.close();
}
//function creates a summary of the user's input dna file.
void dna_list::toSummaryFile()
{
  ofstream summaryFile ("mark.txt");
  if (summaryFile.is_open())
  {
    summaryFile<<endl;
    summaryFile <<"NAME: "<< name<<endl;
    summaryFile<<endl;
    summaryFile <<"STUDENT I.D: "<< id<<endl;
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
//Reads the New DNA File
void dna_list::readSummaryFile()
{
  string line;
  ifstream dnaFile ("mark.txt");
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
