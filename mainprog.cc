/***
 * \file mainprog.cc
 * \brief driver for LCS solution
 * 
 * Gerald McGee - Gm748618@ohio,.edu
 * Description: This is the main program for this assignment. It is just a driver to get solution.
 * It contains the dynamic algo function which does the main work for computing the LCS of two DNA strands.
 * Date: 19 November 2021
**/

#include "geneseq.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Prototypes
vector<Geneseq> make_gnome(ifstream &inStream, int k);
/* 
 * Function: make_gnome
 * Purpose: The above function returns a collection of gene sequence objects.
 * The function thats the file stream and the size of each subsequence k.
 * We turn each subsequence into a gene seq object and return that collection stored in a vector.
 *  
 * Parameters:
 * @param inStream - the input file stream
 * @param k  - the group size for each gene
 * @return a vector of gene sequences
 * 
 * 
 * Space Complexity: O(n) - The vector is a linear space object 
 * Time Complexity: Linear Time - O(n)
 *
*/
int max_num(int n0, int n1);
/*
 * This function returns the max of the two integer arguments 
 * Time and Space complexity are both constant O(1)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * we are realling doing just one comparison no matter what.
 * 
 * Parameters:
 * @param n0 - a integer
 * @param n1  -  a integer
 * @return a- the bigger integer
*/

void dyn_algo(vector<Geneseq> gene_seq1, vector<Geneseq> gene_seq2, int length_one, int length_two);
/*
 * Dynamic programming solution to find the largest common subsequence of the DNA strands
 * Space complexity: O(m*n) space for matrix allocation
 * Time complexity: O(m*n) m*n dynamic prog solution
 * 
 * Parameters:
 * @param gene_seq1 - the first vector of gene sequences
 * @param gene_seq2 - the second vector of gene sequences
 * @param length_one - length of first gene sequence 
 * @param length_two - length of second gene sequence
 * 
 * @return - void
 * 
 */

// Main function that takes command-line arguments 
int main(int argc, char **argv) {
    ifstream inputf;
    int seq_size;                  

  ///< file error check 
  inputf.open(argv[1]);
  if(!inputf) {
    cout << "error opening file" << endl;
    exit(1);
  }

  inputf >> seq_size; 
  inputf.ignore();   

  vector<Geneseq> gene_seq1 = make_gnome(inputf, seq_size);  
  vector<Geneseq> gene_seq2 = make_gnome(inputf, seq_size);  
  
  inputf.close();  

  dyn_algo(gene_seq1, gene_seq2, gene_seq1.size(), gene_seq2.size());

  return 0;
}

vector<Geneseq> make_gnome(ifstream &inStream, int k){
    char character;
    vector<Geneseq> cons; 
    string fullseq = ""; 
    int occ = 0; 
    while(!inStream.eof()){
        inStream.get(character);
        if(character == '\n'){
            return cons;
        }

        fullseq += character; occ++;

        if(occ == k){
            cons.push_back(fullseq);
            fullseq = ""; occ = 0;
        }

    }
    return cons;
}

void dyn_algo(vector<Geneseq> gene_seq1, vector<Geneseq> gene_seq2, int length_one, int length_two){
    int solutionT[length_one+1][length_two+1];
    for(int i = 0; i <= length_one; i++){
        for(int j = 0; j <= length_two; j++){
            if(i == 0 || j == 0){
                solutionT[i][j] = 0;
            } else if (gene_seq1[i-1] == gene_seq2[j-1]){
                solutionT[i][j] = solutionT[i-1][j-1] + 1;
            }
            else{
                solutionT[i][j] = max_num(solutionT[i-1][j], solutionT[i][j-1]);
            }
        }
    }

    vector<string> oput;
    int i = length_one; 
    int j = length_two; 

    while ((i > 0) && (j > 0)) { 
        if (gene_seq1[i-1] == gene_seq2[j-1]) {     
            oput.push_back(gene_seq1[i-1].seq_getter());
            i--; j--;
        } 
        else if(solutionT[i-1][j] > solutionT[i][j-1]){
            i--;
        }else{
            j--;
        }
    } 

    cout << solutionT[length_one][length_two] << endl;
    if(!oput.empty()){
        for(int i = oput.size(); i >= 0; i--){
            cout << oput[i];
        }
        cout << endl;
    }
}


int max_num(int n0, int n1){
    return (n0 > n1)? n0:n1;
}