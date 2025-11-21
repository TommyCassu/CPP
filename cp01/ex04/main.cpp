#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string new_content;
        std::string file_replace;
        std::ifstream file(av[1]);
  
        file_replace += av[1];
        file_replace += ".replace";
        
        if (!file.is_open())
        {
            std::cerr << " Error ! Cannot open file, please verify if " << av[1] << "is a valid file" << std::endl;
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
            unsigned int s1_lenght = s1.length();
            unsigned int s2_lenght = s2.length();
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
        

        std::ofstream _file(file_replace);
        _file << new_content;
        _file.close();
    }
    else
        std::cerr << "Error ! Please respect the correct way to use : ./sed filename s1 s2" << std::endl;
    return (0);
}