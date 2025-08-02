#include <iostream>
#include <string.h>
using namespace std;

int main(int ac, char **av)
{
    int    i;
    int j;


    i = 0;
    j = 1;
    if (ac >= 2)
    {
        while (av[j])
        {
            i = 0;
            while (av[j][i])
            {
                av[j][i] = toupper(av[j][i]);
                cout << av[j][i];
                i++;
            }
            cout << " ";
            j++;
        }
        cout << endl;
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
}