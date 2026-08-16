#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cctype>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

template<typename T>
void    displayList(const T &param) {
    typename T::const_iterator it;

    for (it = param.begin(); it != param.end(); ++it)
        std::cout << *it << " ";
    return ;
}

template<typename T>
void    storeContainer(char **av, T &container) {
    int i;

    i = 1;
    while (av[i]) {
        long tmpNumbLong = std::atol(av[i]);
        container.push_back(static_cast<int>(tmpNumbLong));
        i++;
    }
    return ;
}

class PmergeMe {
   private:
        std::vector<int> _vect;
        std::deque<int> _deq;

   public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);

    void    run(int ac, char **av);
    bool    isValidParam(char **av);
    void    sortContainer(std::vector<int> &vect);
    void    sortContainer(std::deque<int> &deq);

    template<typename T>
    double  sortTimed(char **av, T &container) {
        clock_t start = clock();

        storeContainer(av, container);
        sortContainer(container);

        clock_t end = clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }
};

#endif