#ifndef BOYER_SEARCH_ALGORITM_H_INCLUDED
#define BOYER_SEARCH_ALGORITM_H_INCLUDED

#include <vector>
#include <string>

std::vector<int> boyer_search(std::string t, std::string p) {
    std::vector<int> v;
    int stop_symbol_table[256];
    int sufix_table[p.size() + 1];

    /* Preprocessing */

    //create sufix_table
    int suff[p.size()];
    suff[p.size()-1] = p.size();

    for(int i = p.size()-2, g = p.size()-1, f = 0; i >= 0; --i)
    {
        if(i > g && suff[i+p.size()-1-f] < i-g)
            suff[i] = suff[i+p.size()-1-f];
        else
        {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && p[g] == p[g+p.size()-1-f])
                --g;
            suff[i] = f - g;
        }
    }

    for(int i=0; i<p.size(); ++i)
        sufix_table[i] = p.size();

    for(int i = p.size() - 1; i >= 0; --i)
        if (suff[i] == i + 1)
            for (int j = 0; j < p.size()-1-i; ++j)
                if(sufix_table[j] == p.size())
                    sufix_table[j] = p.size()-1-i;

    for (int i = 0; i <= p.size() - 2; ++i)
        sufix_table[p.size()-1-suff[i]] = p.size()-1-i;

    //create stop_symbol_table
    for (int i = 0; i < 256; ++i)
        stop_symbol_table[i] = p.size();
    for (int i = 0; i < p.size(); ++i)
        stop_symbol_table[p[i]] = p.size()-i-1;

    /* Searching */
    int i, j = 0;
    while(j <= t.size() - p.size())
    {
        for (i = p.size() - 1; i >= 0 && p[i] == t[i + j]; --i);
        if (i < 0)
        {
            v.push_back(j);
            j += sufix_table[0];
        }
        else
        {
            //add max delta
            int d1 = sufix_table[i];
            int d2 = stop_symbol_table[t[i+j]]- p.size() + 1 + i;
            j += d1>d2 ? d1:d2;
        }
    }

    return v;
}
#endif // BOYER_SEARCH_ALGORITM_H_INCLUDED
