//
// BRIANNA CHERRY
// lab 6: quiz programming project
//
// this file contains main, which drives the program. It will take a txt file
// of the user's choosing by command line argument, open the file, and read
// the information in the file. It will store each question-answer pair in 
// a Quiz class object, and each object will be store in a vector of objects.
// Then, main will print each question in the txt file to the user, take the user's
// answer, and compare it with the answer taken from the .txt. The program
// will tell the user whether they enetered the correct answer and call approproate 
// functions to adjust their score and print the final result. 
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "printResult.h"
#include "Quiz.h"

using namespace std;

int main(int argc, char const *argv[]){

    // command line argument for file name
    string fileName = argv[1];

    // open file
    ifstream inputFile;
    inputFile.open(fileName);

    // if file doesn't open properly, print error message and quit program
    if (!inputFile)
        cout << "Error opening data file\n";
    else
    {
        string qtemp, atemp, // will store the A: and Q: at beginning of each line
               question, answer; // will store actual question or answer after A: and Q:
        bool is_question = true; // will store true if a line begins with Q:
        vector<Quiz> questions; // vector of Quiz objects

        while (inputFile >> qtemp)
        {
            if (qtemp == "Q:")
            {
                getline(inputFile >> ws, question);
                if (inputFile >> atemp && atemp == "A:")
                {
                    // ws wil remove whitespace at the beginning of the line (after A: or Q:)
                    getline(inputFile >> ws, answer);
                    // create quiz object with the current question answer pair and save to vector
                    Quiz newQuiz(question, answer);
                    questions.push_back(newQuiz);
                }
            }
        }
        inputFile.close();

        // shuffle the vector of questions into a random order
        srand(unsigned(time(0)));
        random_shuffle(questions.begin(), questions.end());

        string userAnswer;
        int totalCount   = 0, 
            correctCount = 0,
            wrongCount   = 0;

        for (int x = 0; x < questions.size(); x++)
        {
            // print question
            cout << questions[x].getQuestion() << endl;
            // take user input
            getline(cin, userAnswer);
            // compare input to the actual answer from .txt 
            if (userAnswer.compare(questions[x].getAnswer()) == 0)
            {
                Quiz::updateScore(1);
                cout << "Correct!" << endl 
                     << "Current score: " << Quiz::getScore() << endl;
                correctCount++;
            }
            else
            {
                Quiz::updateScore(-1);
                cout << "Wrong! Correct answer: " << questions[x].getAnswer() << endl 
                     << "Current score: " << Quiz::getScore() << endl;
                wrongCount++;
            }
            cout << endl;
            totalCount++;

        }

        // print the string stream created by printResult, contains final score 
        // and other information
        cout << printResult(totalCount, correctCount, wrongCount);

    }

    return 0;
}
