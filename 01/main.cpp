#include <vector>
#include <iostream>
#include <fstream>

class Elf
{
private:
    std::vector<int> carrying;
public:
    Elf(std::vector<int> foods);
    int GetTotalFood();
};

Elf::Elf(std::vector<int> foods)
{
    for (int i = 0; i < foods.size(); i++)
    {
        Elf::carrying.push_back(foods[i]);
    }
};


int Elf::GetTotalFood()
{
    int sum = 0;
    for (int i = 0; i < Elf::carrying.size(); i++)
    {
        sum += Elf::carrying[i];
    }
    return sum;
};

void loadFile(std::string filename, std::vector<Elf>& elfs)
{
    std::ifstream inpFile(filename);

    std::string line;

    std::vector<int> vals;

    if(!inpFile.is_open()) { return; }

    while (getline (inpFile, line)) 
    {
        if(line == "")
        {
            elfs.push_back(Elf(vals));
            vals.clear();
        }
        else
        {
            vals.push_back(stoi(line));
        }
    }

    return;
}


int main()
{
    std::vector<Elf> elfs;

    loadFile("input", elfs);

    int max1 = 0;
    int max2 = 0;
    int max3 = 0;

    for (int i = 0; i < elfs.size(); i++)
    {
        if(elfs[i].GetTotalFood() > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = elfs[i].GetTotalFood();

            continue;
        }
        else if(elfs[i].GetTotalFood() > max2)
        {
            max3 = max2;
            max2 = elfs[i].GetTotalFood();
        }
        else if(elfs[i].GetTotalFood() > max3)
        {
            max3 = elfs[i].GetTotalFood();
        }
    }

    int tot = max1 + max2 + max3;
    std::cout << "Total is : " << tot;

    return 0;
}