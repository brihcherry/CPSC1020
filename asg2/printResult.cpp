//
// contains definition of printResult
// this function will use a string stream to display
// some final results to the user, including the total
// number of questions, number right and wrong, and their 
// final score. 
// 

#include "printResult.h"
#include "Quiz.h"
#include <iostream>
#include <sstream>

std::string printResult(int total, int correct, int wrong)
{
    std::stringstream output;

    output << "Number of questions: " << total << std::endl
           << "Number correct answers: " << correct << std::endl
           << "Number wrong answers: " << wrong << std::endl
           << "Final score: " << Quiz::getScore() << std::endl;

    return output.str();
}