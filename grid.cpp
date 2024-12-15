#include <iostream>
#include <iomanip>
#include "grid.h"
using namespace std;

void display(ostream &os, Complex **grid, size_t fil, size_t col)
{
    os << setw(3) << "num";
    for (size_t i = 0; i < col; i++)
    {
        os << setw(20) << char('A' + i);
    }
    os << "\n";
    for (size_t i = 0; i < fil; i++)
    {
        os << setw(3) << i + 1;
        for (size_t j = 0; j < col; j++)
        {
            os << setw(20) << (grid[i][j]);
        }
        os << "\n";
    }
    os << "\n";
}
size_t find_noParenth(const std::string &str, const string &characters)
{
    size_t inception = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
            inception++;
        if (str.at(i) == ')')
            inception--;
        if (characters.find(str.at(i)) != std::string::npos && inception == 0)
        {
            return i;
        }
    }
    return std::string::npos;
}

bool correctParenth(const std::string &str)
{
    size_t inception = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
            inception++;
        if (str.at(i) == ')')
            inception--;
    }
    if (inception == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void deleteSpaces(std::string &str)
{
    size_t i = str.size() - 1;
    while (i > 0)
    {
        i--;
        if (str.at(i) == ' ')
        {
            str.erase(i, 1);
        }
    }
    return;
}

val *read(const std::string &input, Complex **grid)
{
    size_t found;
    string reduced = input;
    for (;;)
    {
        found = find_noParenth(reduced, "+-");
        if (found != std::string::npos)
        {
            if (reduced.at(found) == '+')
            {
                sum *s = nullptr;
                s = new sum;
                if (found == 0)
                {
                    s->sum1 = new num;
                }
                else
                {
                    s->sum1 = read(reduced.substr(0, found), grid);
                }
                if (found == input.size() - 1)
                {
                    s->sum2 = new num;
                }
                else
                {
                    s->sum2 = read(reduced.substr(found + 1, std::string::npos), grid);
                }
                return s;
            }
            else
            {
                dif *r = nullptr;
                r = new dif;
                if (found == 0)
                {
                    r->dif1 = new num;
                }
                else
                {
                    r->dif1 = read(reduced.substr(0, found), grid);
                }
                if (found == input.size() - 1)
                {
                    r->dif2 = new num;
                }
                else
                {
                    r->dif2 = read(reduced.substr(found + 1, std::string::npos), grid);
                }
                return r;
            }
        }
        found = find_noParenth(reduced, "*/");
        if (found != std::string::npos)
        {
            if (reduced.at(found) == '*')
            {
                mult *m = nullptr;
                m = new mult;
                m->mult1 = read(reduced.substr(0, found), grid);
                m->mult2 = read(reduced.substr(found + 1, std::string::npos), grid);
                return m;
            }
            else
            {
                frac *d = nullptr;
                d = new frac;
                d->frac1 = read(reduced.substr(0, found), grid);
                d->frac2 = read(reduced.substr(found + 1, std::string::npos), grid);
                return d;
            }
        }
        if (reduced.at(0) == '(' && reduced.at(reduced.size() - 1) == ')')
        {
            reduced = reduced.substr(1, reduced.size() - 2);
        }
        else
        {
            if (reduced.substr(0, 3) == "sin")
            {
                sine *si = nullptr;
                si = new sine;
                si->input = read(reduced.substr(3, string::npos), grid);
                return si;
            }
            if (reduced.substr(0, 3) == "cos")
            {
                cosine *co = nullptr;
                co = new cosine;
                co->input = read(reduced.substr(3, string::npos), grid);
                return co;
            }
            if (reduced.substr(0, 3) == "abs")
            {
                absolute *ab = nullptr;
                ab = new absolute;
                ab->input = read(reduced.substr(3, string::npos), grid);
                return ab;
            }
            if (reduced.substr(0, 2) == "ln")
            {
                loga *lo = nullptr;
                lo = new loga;
                lo->input = read(reduced.substr(2, string::npos), grid);
                return lo;
            }
            if (reduced.substr(0, 2) == "e^")
            {
                expo *ex = nullptr;
                ex = new expo;
                ex->input = read(reduced.substr(2, string::npos), grid);
                return ex;
            }
            num *n = nullptr;
            n = new num;
            if (reduced.size() != 1 && isalpha(reduced.at(0)) != 0)
            {
                n->num = grid[stoi(input.substr(1)) - 1][reduced.at(0) - 'A'];
            }
            else
            {
                if (reduced.at(0) == 'i')
                {
                    n->num = Complex{0, 1};
                }
                else
                {
                    n->num = Complex{stof(reduced), 0};
                }
            }
            return n;
        }
    }
}

void start()
{
    const size_t fil = 10;
    const size_t col = 9;
    Complex **grid;
    grid = new Complex *[fil];
    for (size_t i = 0; i < 10; i++)
    {
        grid[i] = new Complex[col];
    }
    val *nodes = nullptr;
    size_t targetC = 0;
    size_t targetN = 0;
    for (;;)
    {
        display(std::cout, grid, fil, col);
        string input;
        getline(cin, input);
        deleteSpaces(input);
        if (correctParenth(input))
        {
            if (input == "end")
            {
                break;
            }
            targetC = input.at(0) - 'A';
            targetN = stoi(input.substr(1, input.find("=") - 1)) - 1;
            nodes = read(input.substr(input.find("=") + 1, std::string::npos), grid);
            grid[targetN][targetC] = nodes->eval();
        }
        else
        {
            cout << "Input error" << endl;
        }
        delete nodes;
    }
    for (size_t i = 0; i < 10; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
    cout << "Finished" << endl;
    return;
}