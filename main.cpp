#include <QApplication>
#include <QQmlApplicationEngine>
#include "readautomata.h"
#include "threesome.h"
#include <QtWebEngine>
#include <iostream>
#include <string>
#include <fstream>


bool belong(list<string> l, string s){
    for(string ss: l){
        if(ss.compare(s)==0)
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    ReadAutomata ra = ReadAutomata();
    ra.read("/Users/papa/mon_automata_avec_sep_separes_1.txt");
    ra.determining();
    ofstream fiLe("/Users/papa/Automata/web/graph.js");
    if(fiLe){
        fiLe << "document.addEventListener('DOMContentLoaded', function(){ " << endl;
        fiLe << "var cy = cytoscape({" << endl;
             fiLe <<  " container: document.querySelector('#cy')," << endl;

             fiLe <<  "   boxSelectionEnabled: false," << endl;
              fiLe <<  "  autounselectify: true," << endl;

               fiLe <<  " style: cytoscape.stylesheet()" << endl;
                  fiLe <<  ".selector('node')" << endl;
                    fiLe <<  ".css({" << endl;
                     fiLe <<  " 'content': 'data(name)'," << endl;
                      fiLe <<  "'text-valign': 'center'," << endl;
                      fiLe <<  "'color': 'white'," << endl;
                      fiLe <<  "'text-outline-width': 2," << endl;
                      fiLe <<  "'background-color': '#999'," << endl;
                      fiLe <<  "'text-outline-color': '#999'" << endl;
                    fiLe <<  "})" << endl;
                  fiLe <<  ".selector('edge')" << endl;
                    fiLe <<  ".css({" << endl;
                      fiLe <<  "'label': 'data(label)'," << endl;
                      fiLe <<  "'curve-style': 'bezier'," << endl;
                      fiLe <<  "'target-arrow-shape': 'triangle'," << endl;
                      fiLe <<  "'target-arrow-color': '#E30657'," << endl;
                      fiLe <<  "'line-color': '#0D1B76'," << endl;
                      fiLe <<  "'width': 1" << endl;
                    fiLe <<  "})" << endl;
                  fiLe <<  ".selector(':selected')" << endl;
                    fiLe <<  ".css({" << endl;
                     fiLe <<  " 'background-color': 'black'," << endl;
                      fiLe <<  "'line-color': 'black'," << endl;
                      fiLe <<  "'target-arrow-color': 'black'," << endl;
                      fiLe <<  "'source-arrow-color': 'black'" << endl;
                    fiLe <<  "})" << endl;
                  fiLe <<  ".selector('.faded')" << endl;
                    fiLe <<  ".css({" << endl;
                      fiLe <<  "'opacity': 0.25," << endl;
                      fiLe <<  "'text-opacity': 0" << endl;
                    fiLe <<  "})," << endl;

                    fiLe << "elements: {" << endl;
                        fiLe << "    nodes: [" << endl;
                        long i = 0;
                        for(string s: ra.states){
                            if(belong(ra.finalstates, s) && s.compare(ra.initialState)==0)
                                fiLe << "{ data: { id: '"+s+"', name: '"+s+"_I_F' } }";
                            else if(belong(ra.finalstates, s))
                                    fiLe << "{ data: { id: '"+s+"', name: '"+s+"_F' } }";
                            else if(s.compare(ra.initialState)==0)
                                    fiLe << "{ data: { id: '"+s+"', name: '"+s+"_I' } }";
                            else
                                fiLe << "{ data: { id: '"+s+"', name: '"+s+"' } }";
                            if(i < ra.states.size()-1)
                                fiLe << "," << endl;
                            i++;
                        }
                        fiLe << "]," << endl;

                            fiLe << "edges: [" << endl;
                            long j = 0;
                            for(ThreeSome s : ra.transitions){
                                fiLe << "{ data: { source: '"+s.first+"', target: '"+s.third+"' , label: '"+s.second+"'} }";
                                //if(j < ra.states.size()-1)
                                    fiLe << "," << endl;
                                j++;
                            }
                            fiLe << "]" << endl;
                            fiLe << "}," << endl;

                          fiLe << "layout: {" << endl;
                            fiLe << " name: 'grid'," << endl;
                            fiLe << "padding: 10" << endl;
                          fiLe << "}" << endl;
                        fiLe << "});" << endl;

                        fiLe << "cy.on('tap', 'node', function(e){" << endl;
                          fiLe << "var node = e.cyTarget;" << endl;
                          fiLe << "var neighborhood = node.neighborhood().add(node);" << endl;

                          fiLe << "cy.elements().addClass('faded');" << endl;
                          fiLe << "neighborhood.removeClass('faded');" << endl;
                        fiLe << "});" << endl;

                       fiLe << " cy.on('tap', function(e){" << endl;
                          fiLe << "if( e.cyTarget === cy ){" << endl;
                            fiLe << "cy.elements().removeClass('faded');" << endl;
                          fiLe << "}" << endl;
                       fiLe << " });" << endl;

                       fiLe << " });" << endl;
    }else
           cout << "Can't write the file" << endl;



    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QtWebEngine::initialize();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/automata.qml")));

    return app.exec();
}
