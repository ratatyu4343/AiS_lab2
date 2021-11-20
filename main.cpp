#include <iostream>
#include <random>
#include <windows.h>
#include "naive_shearch_algoritm.h"
#include "boyer_search_algoritm.h"
#include "KMP_algoritm.h"

void print(std::string t, std::string p, std::vector<int> v);
std::string rand_str(int n);

int main()
{
    //naive algorithm
    std::string tb = rand_str(500);
    std::string pb = rand_str(5);
    std::vector<int> vb = naive_search(tb, pb);

    std::string t = "\nNaive pattern searching is the simplest method"
                    "among other pattern searching algorithms. It "
                    "checks for all character of the main string to the pattern."
                    "Naive algorithm is exact string matching"
                    "(means finding one or all exact occurrences"
                    "of a pattern in a text) algorithm. "
                    "This algorithm is helpful for smaller texts.\n";
    std::string p = "search";
    std::vector<int> v = naive_search(t, p);

    std::cout << "\n\nPattern: " << pb << "\n\n";
    print(tb, pb, vb);

    std::cout << "\nPattern: " << p << "\n";
    print(t, p, v);

    //boyer algorithm
    pb = "1101100";
    vb = boyer_search(tb, pb);

    p = "pattern";
    v = boyer_search(t, p);

    std::cout << "\n\nPattern: " << pb << "\n\n";
    print(tb, pb, vb);

    std::cout << "\nPattern: " << p << "\n";
    print(t, p, v);

    //kmp algorithm
    pb = "001101";
    vb = kmp_search(tb, pb);

    p = "Naive";
    v = kmp_search(t, p);

    std::cout << "\n\nPattern: " << pb << "\n\n";
    print(tb, pb, vb);

    std::cout << "\nPattern: " << p << "\n";
    print(t, p, v);
}

std::string rand_str(int n)
{
    srand(0);
    std::string s;
    for(int i = 0; i < n; i++)
    {
        if(rand()%2 == 0) s.push_back('1');
        else s.push_back('0');
    }
    return s;
}

void print(std::string t, std::string p, std::vector<int> v)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < t.size(); i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j] == i)
            {
                SetConsoleTextAttribute(hConsole, 4);
            }
        }
        std::cout << t[i];
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j] + p.size()-1 == i)
            {
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
    }
    std::cout << "\n";
}
