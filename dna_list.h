#include <string>
using std::string;

class dna_list{
public:
  double list_sum, list_mean, list_variance, list_standDev, lineSum;
  int totalGDLine;
  //variables for accounting for total nucleotides.
  int countA, countC,countT,countG;
  //variables for calculating probability of each nucleotide in provided dnalist.txt file
  double probA, probC, probT, probG;
  //variables for calculating probability of each Bigram in provided dnalist.txt file
  double probAA, probAC, probAT, probAG, probCA, probCC, probCT,probCG;
  //variables for Gaussian Distibrution
  double rand_a,rand_b;
  double box_muller;
  //variable for length of random dna string
  int rand_stringLength;
  //variable used for switch statement in order to detemine type of nucleotide
  int rand_nucleotide;
  int countAA, countAC, countAT, countAG, countCA, countCC, countCT, countCG;
  //variables for user input from main
  string filename, name, id;
  dna_list(string file, string inputFirst, string inputLast, string inputId);
  ~dna_list();
  void readSummaryFile();
  void toSummaryFile();
  void freqNucleotide();
  void freqBigram();
  void listMean();
  void listVar();
  void listStDev();
  void probNucleotide();
  void probBigram();
  void GaussianDist();
};
