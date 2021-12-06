/*****************
 * \file geneseq.h 
 *  \brief The gene sequence class object.
 * CS 4040, prog1hw 
 * Name: Gerald McGee
 * Date: 19 November 2021
 * Description: This file contains the gene seq class. 
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

/*****
 * The class object for each gene sequence. This is for
 * the gene subsequences we are using for comparison.
 * 
 * Purpose: The class object is for each subsequence of the input string. It cam be 
 * used for comparison
 * 
 * Functions:
 *         Constructors
 *              This constructor initializes a Gene sequence object.
 *                 Geneseq(const std::string sub_seq)
 *          end of constructors
 *          
 *          Geters
 *              The getter function allows us to retreive the full sequence for the DNA for
 *              the object.
 * 
 *           This functions allows us to compare dna subsequences.
 *           bool operator==(const Geneseq& passedgene)const 
 * 
*******/

// The range of the ASCII values
const int ASCII_R = 255;

class Geneseq{
    public:
        bool operator==(const Geneseq& passedgene)const;
        Geneseq(const std::string sub_seq);
        int freq[ASCII_R] = {0 }; // Table of frequencies
        std::string full_seq;
    
};