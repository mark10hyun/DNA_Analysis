#include <string>
using std::string;

class dna_list{
public:
  char  nucA, nucC, nucT, nucG;
  string  bigramAA, bigramAC, bigramAT, bigramAG,
              bigramCA, bigramCC, bigramCT, bigramCG;
  double list_sum, list_mean, list_variance, list_standDev, lineSum;
  int totalGDLine;
  int countA, countC,countT,countG;
  double probA, probC, probT, probG;
  double probAA, probAC, probAT,probAG, probCA, probCC, probCT,probCG;
  double rand_a , rand_b;
  double box_muller;
  int rand_stringLength;
  int rand_nucleotide;

  int countAA, countAC, countAT, countAG, countCA, countCC, countCT, countCG;
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
