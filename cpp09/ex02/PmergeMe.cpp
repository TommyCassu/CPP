#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_vect = src._vect;
        this->_deq = src._deq;
    }
    return *this;
}

bool    PmergeMe::isValidParam(char **av) {
    int i;
    int j;

    i = 1;
    while (av[i]) {
        if (av[i][0] == '\0')
            return false;
        j = 0;
        while (av[i][j]) {
            if (!(std::isdigit(static_cast<unsigned char>(av[i][j]))))
                return false;
            j++;
        }
        char *end;
        errno = 0;
        long tmpNumbLong = std::strtol(av[i], &end, 10);
        if (errno == ERANGE || *end != '\0'
            || tmpNumbLong > std::numeric_limits<int>::max())
            return false;
        i++;
    }
    return true;
}

static std::vector<size_t> jacobsthalOrder(size_t k) {
    std::vector<size_t> order;
    size_t prev = 1;
    size_t j0 = 1;
    size_t j1 = 1;

    if (k < 2)
        return order;
    while (prev < k) {
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
        size_t cur = (next < k) ? next : k;
        for (size_t x = cur; x > prev; x--)
            order.push_back(x);
        prev = cur;
    }
    return order;
}

void    PmergeMe::sortContainer(std::vector<int> &vect) {
    int     straggler;
    
    straggler = -1;
    
    if (vect.size() < 2)
        return ;

    if (vect.size() % 2 != 0) {
        straggler = vect.back();
        vect.pop_back();
    }
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vect.size(); i += 2) {
        int a = vect[i];
        int b = vect[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> larges;
    for (size_t i = 0; i < pairs.size(); i++)
        larges.push_back(pairs[i].second);
    sortContainer(larges);

    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> isAlreadyInput(pairs.size(), false);
    for (size_t i = 0; i < larges.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!isAlreadyInput[j] && pairs[j].second == larges[i]) {
                sortedPairs.push_back(pairs[j]);
                isAlreadyInput[j] = true;
                break ;
            }
        }
    }

    std::vector<int> mainChain = larges;
    mainChain.insert(mainChain.begin(), sortedPairs[0].first);

    std::vector<int> smalls;
    for (size_t i = 0; i < sortedPairs.size(); i++)
        smalls.push_back(sortedPairs[i].first);

    std::vector<size_t> order = jacobsthalOrder(smalls.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        int    small = smalls[idx - 1];
        int    partner = sortedPairs[idx - 1].second;

        std::vector<int>::iterator partnerPos =
            std::lower_bound(mainChain.begin(), mainChain.end(), partner);
        std::vector<int>::iterator insertPos =
            std::lower_bound(mainChain.begin(), partnerPos, small);
        mainChain.insert(insertPos, small);
    }

    if (straggler != -1) {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    vect = mainChain;
    return ;
}

void    PmergeMe::sortContainer(std::deque<int> &deq) {
    int     straggler;

    straggler = -1;

    if (deq.size() < 2)
        return ;

    if (deq.size() % 2 != 0) {
        straggler = deq.back();
        deq.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deq.size(); i += 2) {
        int a = deq[i];
        int b = deq[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> larges;
    for (size_t i = 0; i < pairs.size(); i++)
        larges.push_back(pairs[i].second);
    sortContainer(larges);

    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> isAlreadyInput(pairs.size(), false);
    for (size_t i = 0; i < larges.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!isAlreadyInput[j] && pairs[j].second == larges[i]) {
                sortedPairs.push_back(pairs[j]);
                isAlreadyInput[j] = true;
                break ;
            }
        }
    }

    std::deque<int> mainChain = larges;
    mainChain.insert(mainChain.begin(), sortedPairs[0].first);

    std::deque<int> smalls;
    for (size_t i = 0; i < sortedPairs.size(); i++)
        smalls.push_back(sortedPairs[i].first);

    std::vector<size_t> order = jacobsthalOrder(smalls.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        int    small = smalls[idx - 1];
        int    partner = sortedPairs[idx - 1].second;

        std::deque<int>::iterator partnerPos =
            std::lower_bound(mainChain.begin(), mainChain.end(), partner);
        std::deque<int>::iterator insertPos =
            std::lower_bound(mainChain.begin(), partnerPos, small);
        mainChain.insert(insertPos, small);
    }

    if (straggler != -1) {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    deq = mainChain;
    return ;
}

void    PmergeMe::run(int ac, char **av) {
    if (isValidParam(av) == false) {
        throw std::runtime_error("Error : Invalid params (only positive digit is valid)");
    }

    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    double vectTime = sortTimed(av, _vect);
    double deqTime  = sortTimed(av, _deq);

    std::cout << "After: ";
    displayList(_vect);
    std::cout << std::endl;

    std::cout << "Time to process " << _vect.size()
              << " elements with std::vector: " << vectTime << " us" << std::endl;
    std::cout << "Time to process " << _deq.size()
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}
