#include <iostream>
#include <fstream>

int main()
{

    std::ifstream inpFile("input");
    std::string line;

    int occasions = 0;

    while(getline(inpFile, line))
    {
        std::string firstElf = line.substr(0, line.find(','));
        std::string secoundElf = line.substr(line.find(',') + 1, line.length());
    
        int feBegin = stoi(firstElf.substr(0, firstElf.find('-')));
        int feEnd = stoi(firstElf.substr(firstElf.find('-') + 1, firstElf.length()));

        int seBegin = stoi(secoundElf.substr(0, secoundElf.find('-')));
        int seEnd = stoi(secoundElf.substr(secoundElf.find('-') + 1, secoundElf.length()));

        if((feBegin >= seBegin && feBegin <= seEnd)
        or (feEnd >= seBegin && feEnd <= seEnd)
        or (seBegin >= feBegin && seBegin <= feEnd)
        or (seEnd >= feBegin && seEnd <= feEnd))
        {
            occasions += 1;
        }
    }
    std::cout << "Result : " << occasions << std::endl;

    return 0;
}