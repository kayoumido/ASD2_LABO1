/* 
 * File:   SymbolGraph.h
 * Author: Olivier Cuisenaire
 * Modified: Valentin Minder (2018), Raphaël Racine (2018), Antoine Rochat (2019)
 *
 * Created on 26. septembre 2014, 15:08
 */

#ifndef SYMBOLGRAPH_H
#define	SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Util.h"

template<typename GraphType>
class SymbolGraph
{
    typedef GraphType Graph; 
private:
    Graph* g;
    // A IMPLEMENTER: vos structures privées ici.
    std::vector<std::pair<std::string, std::vector<std::string>>>vertexes;
public:
    
    ~SymbolGraph()
    {
        //delete g;
    }            
    
    //creation du SymbolGraph a partir du fichier movies.txt
    SymbolGraph(const std::string& filename) {
        /* A IMPLEMENTER */
        // Indication: nous autorisons une double lecture du fichier.

        // exemple de lecture du fichier, ligne par ligne puis element par element (separe par des /)

        std::string line;
        std::ifstream s(filename);
        while (std::getline(s, line))
        {
            auto names = split(line,'/');

            unsigned first = true;
            std::string movieName;
            std::vector<std::string> actors;
            std::pair<std::string, std::vector<std::string>> vertex;

            for( const auto& name : names ) {
                if(first){
                    movieName = name;
                    first = false;
                }else{
                    actors.push_back(name);
                }
            }

            vertex = std::make_pair(movieName, actors);
            vertexes.push_back(vertex);

        }
        s.close();
    }
    
    //verifie la presence d'un symbole
    bool contains(const std::string& name) const {
        /* A IMPLEMENTER */
    }
    
    //index du sommet correspondant au symbole
    int index(const std::string& name) const {
         /* A IMPLEMENTER */
    }
    
    //symbole correspondant au sommet
    std::string symbol(int idx) const {
        /* A IMPLEMENTER */
    }

    //symboles adjacents a un symbole
    std::vector<std::string> adjacent(const std::string& name) const {
        // If a movie name is given, return the actors vector
        auto it = std::find(vertexes.begin(), vertexes.end(), name);
        if(it != vertexes.end()){
            return *it;
        }
        // If an actor is given, return all it's movie
        else{

        }
    }
    
    const Graph& G() const {
        return *g; 
    }
    
};


#endif	/* SYMBOLGRAPH_H */
