#include <fstream>
#include <iostream>
#include <string>

void    replace_data(std::string &new_content, const std::string &s1, const std::string &s2)
{
    unsigned int s1_lenght = s1.length();
    size_t i = 0;

    while (1)
    {
        i = new_content.find(s1, i);
        if (i == std::string::npos)
            break ;
        new_content.erase(i, s1_lenght);
        new_content.insert(i, s2);
    }
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (av[2][0] == '\0' || av[3][0] == '\0')
        {
            std::cout << " Error ! Please s1 or s2 can't be empty." << std::endl;
            return (1); 
        }
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string new_content;
        std::string file_replace;
        std::ifstream file(av[1]);
  
        file_replace += av[1];
        file_replace += ".replace";
        
        if (!file.is_open())
        {
            std::cout << " Error ! Cannot open file, please verify if " << av[1] << " is a valid file" << std::endl;
            return (1); 
        }
        else
        {
            std::string file_line;
            while (std::getline(file, file_line))
            {
                new_content += file_line;
                new_content += '\n';
            }
            replace_data(new_content, s1, s2);
            if (new_content[0] == '\0')
            {
                std::cout << "Error ! Empty file enter, no content copy available" << std::endl;
                return (1);
            }
                
        }
        std::ofstream _file(file_replace.c_str());
        _file << new_content;
        _file.close();
    }
    else
        std::cout << "Error ! Please respect the correct way to use : ./sed filename s1 s2" << std::endl;
    return (0);
}