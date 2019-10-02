/**
 * File: GraphFromImage.cpp
 * Authors: Olivier Cuisenaire
 * Modified by: Robin Demarta, Loïc Dessaules, Doran Kayoumi
 *
 * Created on 18. septembre 2014, 10:46
 * Description: Class to generate a Graph based on an Image
 */

#ifndef SYMBOLGRAPH_H
#define	SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

#include "Util.h"

template<typename GraphType>
class SymbolGraph
{
    typedef GraphType Graph; 
private:
    Graph* g;
    // A IMPLEMENTER: vos structures privées ici.
    std::map<std::string, int> symbols;
public:
    
    ~SymbolGraph()
    {
        delete g;
    }            

    /**
     * Creates the SymbolGraph with the .txt file
     * @param filename
     */
    SymbolGraph(const std::string& filename) {
        std::string line;
        std::ifstream s(filename);
        int idx = 0;
        while (std::getline(s, line))
        {
            auto names = split(line,'/');

            // Add all unique symbols inside a map
            for(auto name : names) {
                auto it = symbols.find(name);
                if(it == symbols.end()){
                    symbols[name] = idx++;
                }
            }

        }

        // Return to the beginning of the file
        s.clear();
        s.seekg(0, std::ios::beg);

        // Create a Graph with the good size
        g = new Graph(symbols.size());

        // Browse file again to populate the Graph
        while (std::getline(s, line))
        {
            auto names = split(line,'/');

            std::string movieName = names[0];
            auto itMovie = symbols.find(movieName);

            for(unsigned i = 1; i < names.size(); ++i) {
                auto itActor = symbols.find(names[i]);
                g->addEdge(itMovie->second, itActor->second);
            }

        }

        s.close();
    }

    /**
     * Checks if a symbol exists
     * O(log(n)) -> we decided to use a map to have this complexity instead of a vector or something else with worse complexity
     * @param name
     * @return true if the symbol exists and false otherwise
     */
    bool contains(const std::string& name) const {
        auto it = symbols.find(name);
        return it != symbols.end();
    }

    /**
     * Searches the index of the corresponding symbol
     * O(log(n)) -> we decided to use a map to have this complexity instead of a vector or something else with worst complexity
     * @param name
     * @return the index
     */
    int index(const std::string& name) const {
         auto it = symbols.find(name);
         return it->second;
    }

    /**
     * Gets the corresponding symbol
     * O(n)
     * @param idx
     * @return the symbol's string
     */
    std::string symbol(int idx) const {
        for (auto it = symbols.begin(); it != symbols.end(); ++it) {
            if (it->second == idx) {
                return it->first;
            }
        }
    }

    /**
     * Returns a list of all the adjacent symbols
     * O(n)
     * @param name
     * @return a list containing the adjacent symbols
     */
    std::vector<std::string> adjacent(const std::string& name) const {
        int idx = index(name);
        std::list<int> idxAdj = g->adjacent(idx);
        std::vector<std::string> adj(idxAdj.size());

        for(auto it = idxAdj.begin(); it != idxAdj.end(); ++it){
            adj.push_back(symbol(*it));
        }

        return adj;
    }
    
    const Graph& G() const {
        return *g; 
    }
    
};


#endif	/* SYMBOLGRAPH_H */
