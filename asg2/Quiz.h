//
// contains declarations for Quiz class
//

#ifndef _QUIZ_
#define _QUIZ_

#include <string>

class Quiz{
    private:
        std::string question = "";
        std::string answer = "";
        static int score;

    public:
    Quiz() : question(""), answer("") {} // default constructor sets empty strings

    // input constructor uses input to set members and removes a space at the end 
    // of the string, if there is one
    Quiz(std::string q, std::string a) : question(q), answer(a) 
    {
        answer = a.substr(0, a.find_last_not_of(" \t\n\r\f\v") + 1);
        question = q.substr(0, q.find_last_not_of(" \t\n\r\f\v") + 1);
    } // remove unwanted characters from string

    // getters
    std::string getQuestion () {return question;}
    std::string getAnswer () {return answer;}
    static int getScore () {return score;}

    // will update the score by the value entered by main
    static void updateScore(int val) 
    {
        score += val; 
        if (score<0) score = 0;
    }

};

#endif
