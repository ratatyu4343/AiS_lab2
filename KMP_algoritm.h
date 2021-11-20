#ifndef KMP_ALGORITM_H_INCLUDED
#define KMP_ALGORITM_H_INCLUDED

#include <vector>
#include <string>

std::vector<int> kmp_search(std::string t, std::string p)
{
    std::vector<int> v;

    //creat prefix table
    int prefix_table[p.size()];
    prefix_table[0] = 0;
    int j = 0, i = 1;

    while(i < p.size())
    {
        if(p[j] == p[i])
        {
            prefix_table[i] = j+1;
            i++; j++;
        }
        else
        {
            if(j == 0)
            {
                prefix_table[i] = 0;
                i++;
            }
            else
            {
                j = prefix_table[j-1];
            }
        }
    }

    /* Searching */
    i = 0;
    j = 0;
    while(i < t.size())
    {
        if(t[i] == p[j])
        {
            i++;
            j++;
            if(j == p.size())
            {
                v.push_back(i - p.size());
                j = 0;
            }
        }
        else
        {
            if(j > 0)
                j = prefix_table[j-1];
            else
                i++;
        }
    }

    return v;
}

#endif // KMP_ALGORITM_H_INCLUDED
