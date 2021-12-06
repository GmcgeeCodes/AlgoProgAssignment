/***
 * \file geneseq.cc
 * \brief  Implementation for geneseq class functions 
 * 
 * Name: Gerald McGee - Gm748618@ohio.edu
 * Description: Implementation for geneseq class. It contains the 
 * constructor for making a geneseq object and the equality operator 
 * to compare gene sequences.
 * Date: 19 November 2021
*/

#include "geneseq.h"
using namespace std;
/*********
 * Constructor to create new geneseq objects 
 * Takes a subsequence of the string from input and stores the subsequence 
 * as well as the full gene that subsequence is a member of.
 *
 * @param sub_seq - this is a subsequence of the strand passed in the input. It stored as the class object.
 * 
 * Space Complexity: O(1) : no arrays or extra memory needed
 * Time Complexity: O(n) : The complexity is based on the input
 *
*/

Geneseq::Geneseq(const std::string sub_seq){
    full_seq = sub_seq;
// for every character in the string update other priv variable for each ASCII VAL
    for(const char& character: sub_seq){
        freq[int(character)]++;
    }
}

/*******
 * Overloaded equality operator to check for equality for geneseq objects.
 * @param passedgene - the gene seq object passed into the function for comparison
 * @return boolean value - based on equality between the two geneseq objects
 * Time Complexity: O(n) Linear time - this function depends on how big the two genes are
 * Space Complexity: O(1) - no extra space needed
 * 
*/
bool Geneseq::operator==(const Geneseq& passedgene) const{
    for(int i = 0; i < ASCII_R; i++){
        if(freq[i] != passedgene.freq[i]){
            return false;
        }
    }
    return true;
}

