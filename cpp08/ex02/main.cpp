#include "MutantStack.hpp"
#include <list>
#include <string>

int main()
{
    try {
        std::cout << "  ### Subject test (std::stack) ###" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top : " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size : " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        std::stack<int> s(mstack);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };

    std::cout << std::endl;
    try {
        std::cout << "  ### Subject test (std::list) ###" << std::endl;
        MutantStack<int> mstack;
        std::list<int> lst;
        int vals[] = {5, 17, 3, 5, 737, 0};
        for (int i = 0; i < 6; i++) {
            mstack.push(vals[i]);
            lst.push_back(vals[i]);
        }
        MutantStack<int>::iterator it = mstack.begin();
        std::list<int>::iterator lit = lst.begin();
        std::cout << std::endl;
        std::cout << "stack : " << std::endl;
        while (it != mstack.end())
        {
            std::cout << *it <<  " ";
            ++it;
        }

        std::cout << std::endl;
        std::cout << "list : " << std::endl;
        while (lit != lst.end())
        {
            std::cout << *lit << " ";
            ++lit;
        }
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };

    std::cout << std::endl;
    try {
        std::cout << "   ### Copy Constructor ###" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        MutantStack<int> copy(mstack);
        std::cout << "Original (" << mstack.size() << ") : ";
        MutantStack<int>::iterator it = mstack.begin();
        while (it != mstack.end())
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
        std::cout << "Copy (" << copy.size() << ") : ";
        MutantStack<int>::iterator itc = copy.begin();
        while (itc != copy.end())
        {
            std::cout << *itc << " ";
            ++itc;
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };

    std::cout << std::endl;
    try {
        std::cout << "Test assignment operator :" << std::endl;
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        MutantStack<int> other;
        other.push(777);
        other = mstack;
        other.push(30);
        std::cout << "Original (" << mstack.size() << ") : ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Assigned (" << other.size() << ") : ";
        for (MutantStack<int>::iterator it = other.begin(); it != other.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << (mstack.size() == 2 && other.size() == 3 ? "Assigned is independent !" : "Error ! assigned is shared") << std::endl;
        mstack = mstack;
        std::cout << "After self assignment (" << mstack.size() << ") : ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };

    
    std::cout << std::endl;
    try {
        std::cout << "   ### Empty Stack ### :" << std::endl;
        MutantStack<int> mstack;
        std::cout << "empty() : " << mstack.empty() << std::endl;
        std::cout << "begin() == end() : " << (mstack.begin() == mstack.end() ? "YES" : "NO") << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    
    std::cout << std::endl;
    try {
        std::cout << "   ### String test ###" << std::endl;
        MutantStack<std::string> mstack;
        mstack.push("Toto");
        mstack.push("va");
        mstack.push("a");
        mstack.push("la");
        mstack.push("plage");
        mstack.push("!");
        std::cout << "Top : " << mstack.top() << std::endl;
        std::cout << "Content : ";
        for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    
    std::cout << std::endl;
    try {
        std::cout << "   ### Test const iteration ###" << std::endl;
        MutantStack<int> mstack;
        mstack.push(4);
        mstack.push(8);
        mstack.push(15);
        const MutantStack<int> &ref = mstack;
        std::cout << "Read through const ref : ";
        for (MutantStack<int>::const_iterator it = ref.begin(); it != ref.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    return 0;
}
