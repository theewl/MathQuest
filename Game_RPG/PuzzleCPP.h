#include "Puzzle.h"

Puzzle::Puzzle(string fileName)
{
    this->correctAnswer = 0;
    
    
    ifstream in(fileName);
    
    int numOfAns = 0;
    string ans = "";
    int correctAns = 0;
    
    if(in.is_open())
    {
        getline(in, this->question);
        in >> numOfAns;
        in.ignore();
        
        for ( size_t i = 0 ; i < numOfAns; i++)
        {
            getline(in, ans);
            this->answers.push_back(ans);
        }
        in >> correctAns;
        this->correctAnswer = correctAns;
        in.ignore();
    }
    else
        throw("Couldn't open puzzle...");
    in.close();
}

Puzzle::~Puzzle()
{
    
}

string Puzzle::getAsString()
{
    string answers = "";
    for( size_t i = 0 ; i < this->answers.size();i++)
    {
        answers += to_string(i) + ": " + this->answers[i] + "\n";
    }
    
    //return this->question + "\n" + "\n" + answers + "\n" + to_string(this->correctAnswer) + "\n";
    
    return this->question + "\n" + "\n" + answers + "\n";
}
