#ifndef READAUTOMATA_H
#define READAUTOMATA_H
#include <list>
#include <string>
#include <vector>
#include "threesome.h"
#include <queue>

using namespace std;

class ReadAutomata
{
public:
    ReadAutomata();
    list<string> states;
    list<string> finalstates;
    string initialState ;
    list<string> Alphabet;
    list<ThreeSome> transitions;
    void read(string fileName);
    vector<string> split(const string &s, char delim);
    void __trim(string &str,bool left, bool right);
    void trim(string &str);
    bool belong(queue<string> l, string s);
    bool belong(list<string> l, string s);
    //Fonction permettant de déterminiser un automate
    void determining();
};

#endif // READAUTOMATA_H
