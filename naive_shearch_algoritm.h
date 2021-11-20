#ifndef NAIVE_SHEARCH_ALGORITM_H_INCLUDED
#define NAIVE_SHEARCH_ALGORITM_H_INCLUDED

#include <vector>
#include <string>

std::vector<int> naive_search(std::string t, std::string p)
{
    std::vector<int> answ;
    /* Searching */
    for(int i = 0, j = t.size() - p.size(); i < j; i++)
    {
        bool flag = true;
        for(int m = 0, g = i, k = i + p.size(); g < k; g++, m++)
        {
            if(t[g] != p[m]) flag = false;
        }
        if(flag) answ.push_back(i);
    }
    return answ;
}

#endif // NAIVE_SHEARCH_ALGORITM_H_INCLUDED
