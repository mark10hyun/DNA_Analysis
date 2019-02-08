#include <string>
using std::string;

class dna_list{
public:
  char  nucA, nucC, nucT, nucG;
  string  bigramAA, bigramAC, bigramAT, bigramAG,
              bigramCA, bigramCC, bigramCT, bigramCG;
  double list_sum, list_mean, list_variance, list_standDev, lineSum;

  int countA, countC,countT,countG;
  int countAA, countAC, countAT, countAG, countCA, countCC, countCT, countCG;
  string filename, name, id;

  dna_list(string file, string inputName, string inputId);
  ~dna_list();
  void readSummaryFile();
  void toSummaryFile();
  void freqNucleotide();
  void freqBigram();
  void listMean();
  void listVar();
  void listStDev();

};
