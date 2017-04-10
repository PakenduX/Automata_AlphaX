#include "readautomata.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include "threesome.h"
#include <algorithm>
#include <queue>

/**
 * @author PakenduX
 * @date Monday 1st April 2017
 * @brief Programme de manipulation des automates (affichage, déterminisation, minimisation etc.)
 * @bug problème avec les états finaux après minimisation.
 */

using namespace std;

ReadAutomata::ReadAutomata()
{
    states = list<string>();
    finalstates = list<string>();
    transitions = list<ThreeSome>();
}

/* Cette méthode permet de lire un automate dans un fichier texte et
mettre en place les structures de données permettant la manipulation
Le fichier doit avoir le format suivant:
chaque ligne commence par Q, I, F, T ou V où
Q correspond à l'ensemble des états de l'automate
I correspond à l'état initial
T est l'ensemble des transitions
V est l'alphabet
suivi de ":" suivi de l'ensemble des valeurs séparées par une virgule
sauf pour la transition qui est séparée par point-virgule car ses éléments internes
sont séparés par des virgules.
Chaque ligne termine par une esperluette(&)
EXPLES: voici un fichier décrivant un automate
Q:0,1,2,3 &
I:0 &
T:(0,a,0);(0,a,1);(1,b,1);(1,b,2);(2,c,2);(2,c,3);(3,d,2);(3,d,0) &
F:2,3 &
V:a,b,c,d &

*/
void ReadAutomata::read(string fileName)
{

    ifstream fiLe(fileName);
    if(fiLe){
        string line;
        while(getline(fiLe, line)){
            while(line.find("&")==string::npos)
                getline(fiLe, line);
            line = line.substr(0, line.size()-1);
            vector<string> tabElements = split(line, ':');
            if(tabElements[0].compare("Q")==0){
                vector<string> stat = split(tabElements[1],',');
                for(string s: stat){
                    trim(s);
                    states.push_back(s);
                }
            }else if(tabElements[0].compare("I")==0)
                initialState = tabElements[1];
            else if(tabElements[0].compare("F")==0){
                vector<string> stat = split(tabElements[1],',');
                for(string s: stat)
                    finalstates.push_back(s);
            }else if(tabElements[0].compare("V")==0){
                vector<string> stat = split(tabElements[1],',');
                for(string s: stat)
                    Alphabet.push_back(s);
            }else{
                vector<string> trio = split(tabElements[1],';');
                for(string s : trio){
                    trim(s);
                    vector<string> sub = split(s.substr(1, s.size()-1),',');
                    sub[0].erase(
                            std::remove( sub[0].begin(), sub[0].end(), ')'),
                            sub[0].end() );
                    sub[0].erase(
                            std::remove( sub[0].begin(), sub[0].end(), '('),
                            sub[0].end() );
                    sub[1].erase(
                            std::remove( sub[1].begin(), sub[1].end(), ')'),
                            sub[1].end() );
                    sub[1].erase(
                            std::remove( sub[1].begin(), sub[1].end(), '('),
                            sub[1].end() );
                    sub[2].erase(
                            std::remove( sub[2].begin(), sub[2].end(), ')'),
                            sub[2].end() );
                    sub[2].erase(
                            std::remove( sub[2].begin(), sub[2].end(), '('),
                            sub[2].end() );
                    transitions.push_back(ThreeSome(sub[0], sub[1], sub[2]));
                }
            }
        }
        fiLe.close();
    }else
        cout << "Could not read the file!" << endl;

}
/*La fonction de terminisation d'un automate */
void ReadAutomata::determining(){
    queue<string> statesListes = queue<string>();
    queue<string> dejaVisites = queue<string>();
    statesListes.push("{"+initialState+"}");
    list<string> newStates = list<string>();
    list<string> newFinalstates = list<string>();
    list<ThreeSome> newTransitions = list<ThreeSome>();

    while (!statesListes.empty()){
        string state = statesListes.front();
        newStates.push_back(state);
        statesListes.pop();
        dejaVisites.push(state);
        // Les états sont de la forme {q0, q1, ...., qn}
        state.erase(
             std::remove( state.begin(), state.end(), '}'),
             state.end() ); 							// On enlève les accolades
        state.erase(
             std::remove( state.begin(), state.end(), '{'),
             state.end() );
        vector<string> tabElements = split(state, ','); // On split par rapport à , pour n'avoir que les états
        string qres = "{";
        string qresTmp = "";
        bool final = false;

/* Pour tous les alphabets on teste ......*/
        for(string a : Alphabet){
            for(string e: tabElements ){
                for(ThreeSome ts: transitions){
                    trim(e);
                    trim(ts.first);
                    trim(ts.second);
                    trim(a);
                    if(e.compare(ts.first)==0 && a.compare(ts.second)==0)
                        qresTmp +=ts.third+",";

                }
                qres +=qresTmp;
                qresTmp = "";
                if(belong(finalstates, e))
                    final = true;

                if(initialState.compare(e)==0)
                    initialState = "{"+e+"}";

            }
            qres = qres.substr(0, qres.size()-1);
            qres +="}";
            trim(qres);
            if(!belong(statesListes, qres) && !belong(dejaVisites, qres) && qres.compare("}")!=0 && qres.compare("{")!=0)
                statesListes.push(qres);
            if(qres.compare("}")!=0 && qres.compare("{")!=0)
                newTransitions.push_back(ThreeSome("{"+state+"}", a, qres));
            if(final && qres.compare("}")!=0 && qres.compare("{")!=0 && !belong(newFinalstates, qres))
                newFinalstates.push_back(qres);

            qres = "{";
            final = false;
        }
    }
    states = newStates;
    finalstates = newFinalstates;
    transitions = newTransitions;
    ofstream determiningFile("/Users/papa/determining_automata.txt");
    string res = "";
    determiningFile << "Q:";
    for(string s: states)
        res +=s+",";
    res = res.substr(0, res.size()-1);
        determiningFile << res+"&" << endl;

    determiningFile << "I:"+initialState+"&" << endl;

    res = "";
    determiningFile << "T:";
    for(ThreeSome s: transitions)
        res +="("+s.first+","+s.second+","+s.third+");";
    res = res.substr(0, res.size()-1);
        determiningFile << res+"&" << endl;

    res = "";
    determiningFile << "F:";
    for(string s: finalstates)
        res +=s+",";
    res = res.substr(0, res.size()-1);
        determiningFile << res+"&" << endl;

    res = "";
    determiningFile << "V:";
    for(string s: Alphabet)
        res +=s+",";
    res = res.substr(0, res.size()-1);
        determiningFile << res+"&" << endl;

    determiningFile.close();

}

bool ReadAutomata::belong(queue<string> l, string s){
    queue<string> tmp = l;
    while(!tmp.empty()){
        string ss = tmp.front();
        tmp.pop();
        trim(ss);
        if(ss.compare(s)==0)
            return true;
    }
    return false;
}
bool ReadAutomata::belong(list<string> l, string s){
    for(string ss: l){
        if(ss.compare(s)==0)
            return true;
    }
    return false;
}

vector<string> ReadAutomata::split(const string &s, char delim){
    stringstream ss(s);
    string item;
    vector<string> tokens = vector<string>();
    while (getline(ss, item, delim))
        tokens.push_back(item);
    return tokens;
}

void ReadAutomata::__trim(string &str, bool left, bool right)
{
    string::size_type begin=0;
    string::size_type end=str.size()-1;
    while(left && begin<=end && (str[begin]<=0x20 || str[begin]==0x7f))
        ++begin;
    while(right && end>begin && (str[end]<=0x20 || str[end]==0x7f))
      --end;
    str = str.substr(begin, end - begin + 1);
}
void ReadAutomata::trim(string &str)  { __trim(str,1,1); }
