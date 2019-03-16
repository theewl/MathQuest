#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Puzzle
{
public:
    Puzzle(string fileName);
    virtual ~Puzzle();
    string getAsString();
    
    inline const int& getCorrectAns()const { return this->correctAnswer; }
    
private:
    string question;
    vector<string> answers;
    int correctAnswer;
};
