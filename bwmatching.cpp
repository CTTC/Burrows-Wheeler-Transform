#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using std::cin;
using std::istringstream;
using std::map;
using std::string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;
// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position
//       of this character in the sorted array of
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string& bwt,
                   map<char, int>& starts,
                   map<char, vector<int> >& occ_count_before) {
  // Implement this function yourself
//	string sorted = bwt;
//	sort(sorted.begin(),sorted.end());
//	cout<<"First: "<<sorted<<endl;
	int Acount = 0;
	int Ccount = 0;
	int Gcount = 0;
	int Tcount = 0;
	int Dcount = 0;
    occ_count_before['A'].push_back(0);
    occ_count_before['C'].push_back(0);
    occ_count_before['G'].push_back(0);
    occ_count_before['T'].push_back(0);
    occ_count_before['$'].push_back(0);
	for (int i = 0; i < bwt.size(); i++) {
		char symbol = bwt[i];
		if (symbol == 'A') {
			Acount++;

		} else if (symbol == 'C') {
			Ccount++;
		} else if (symbol == 'G') {
			Gcount++;
		} else if (symbol == 'T') {
			Tcount++;
		} else if (symbol == '$') {
			Dcount++;
		}
	      occ_count_before['A'].push_back(Acount);
	      occ_count_before['C'].push_back(Ccount);
	      occ_count_before['G'].push_back(Gcount);
	      occ_count_before['T'].push_back(Tcount);
	      occ_count_before['$'].push_back(Dcount);
	}
	starts['$'] = 0;
	starts['A'] = Dcount;
	starts['C'] = starts['A'] + Acount;
	starts['G'] = starts['C'] + Ccount;
	starts['T'] = starts['G'] + Gcount;

//
//  for (int i = 0; i <= bwt.size(); i++)
//  {
//    if (i == 0)
//    {
//      occ_count_before['A'].push_back(0);
//      occ_count_before['C'].push_back(0);
//      occ_count_before['G'].push_back(0);
//      occ_count_before['T'].push_back(0);
//      occ_count_before['$'].push_back(0);
//    }
//    else
//    {
//      char symbol = bwt[i - 1];
//      int isA = symbol == 'A';
//      int isC = symbol == 'C';
//      int isG = symbol == 'G';
//      int isT = symbol == 'T';
//      int isD = symbol == '$';
//      int previousACount = occ_count_before['A'][i - 1];
//      int previousCCount = occ_count_before['C'][i - 1];
//      int previousGCount = occ_count_before['G'][i - 1];
//      int previousTCount = occ_count_before['T'][i - 1];
//      int previousDCount = occ_count_before['$'][i - 1];
//      int Acount = isA + previousACount;
//      int Ccount = isC + previousCCount;
//      int Gcount = isG + previousGCount;
//      int Tcount = isT + previousTCount;
//      int Dcount = isD + previousDCount;
//      occ_count_before['A'].push_back(Acount);
//      occ_count_before['C'].push_back(Ccount);
//      occ_count_before['G'].push_back(Gcount);
//      occ_count_before['T'].push_back(Tcount);
//      occ_count_before['$'].push_back(Dcount);

//    }
//  }
//  cout<<endl;
//  cout<< "I: ";
//          for (int i = 0; i <= bwt.size(); i++)
//          {
//        	  cout<<std::setw(3)<< i <<"  ";
//          }
//    cout<<endl<< "A: ";
//    for (int i = 0; i <= bwt.size(); i++)
//    {
//  	  cout <<std::setw(3)<<occ_count_before['A'][i]<<"  ";
//    }
//    cout<<endl;
//    cout<< "C: ";
//    for (int i = 0; i <= bwt.size(); i++)
//    {
//  	  cout<<std::setw(3)<< occ_count_before['C'][i]<<"  ";
//    }
//    cout<<endl;
//    cout<< "G: ";
//    for (int i = 0; i <= bwt.size(); i++)
//    {
//  	  cout<< std::setw(3)<<occ_count_before['G'][i]<<"  ";
//    }
//    cout<<endl;
//    cout<< "T: ";
//    for (int i = 0; i <= bwt.size(); i++)
//    {
//  	  cout<< std::setw(3)<<occ_count_before['T'][i]<<"  ";
//    }
//    cout<<endl;
//
//    cout<< "$: ";
//    for (int i = 0; i <= bwt.size(); i++)
//    {
//  	  cout<<std::setw(3)<< occ_count_before['$'][i]<<"  ";
//    }
//    cout<<endl;
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern,
                     const string& bwt,
                     map<char, int>& starts,
                     map<char, vector<int> >& occ_count_before) {
  int top = 0;
  int bottom = bwt.size() - 1;
  string tempPattern = pattern;
  while (top <= bottom)
  {
//	  cout<<endl<<"top: "<<top<<endl;
//	  cout<<"bottom: "<<bottom<<endl;
    if (!tempPattern.empty())
    {
      char symbol = *(tempPattern.end() - 1);
//      cout<<"Symbol: "<<symbol<<endl;
      tempPattern.pop_back();
      if (occ_count_before[symbol][top + 1] < occ_count_before[symbol][bottom + 1] || occ_count_before[symbol][top] < occ_count_before[symbol][bottom + 1])
      {
//    	  cout<<"1========="<<endl;
        top = starts[symbol] + occ_count_before[symbol][top];
        bottom = starts[symbol] + occ_count_before[symbol][bottom + 1] - 1;
      }
      else
      {
//    	  cout<<"2========="<<endl;
        return 0;
      }
    }
    else
    {
//    	cout<<"3========="<<endl;
      return bottom - top + 1;
    }
  }

}


int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}

