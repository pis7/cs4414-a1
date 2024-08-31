#include <fstream>  // std::ifstream (Input File Stream)
#include <iostream> // std::cout (Standard Output)
#include <string>   // std::string

int main(int argc, char **argv)
{
    // Confirm correct number of arguments
    if (argc < 3) {
        std::cout << "Insufficient program aruments!" << std::endl;
        return 0;
    }

    // Obtain input arguments
    std::ifstream csv(argv[1]);
    std::string thresh_arg(argv[2]);
    long unsigned int thresh = 0;
    
    // Confirm valid threshold argument
    try {
        thresh = std::stoi(thresh_arg);
    } catch(...) {
        std::cout << "Invalid threshold argument!" << std::endl;
        return 0;
    }

    // Temporary values from CSV
    std::string thisname;
    std::string thisnum;

    int sum = 0;

    if (csv.is_open()) {
        std::cout << "==========" << std::endl;
        while(std::getline(csv, thisname, ',')) {
            std::getline(csv, thisnum); // guaranteed to have number following name
            if (thisname.size() == thresh)
                std::cout << thisname << std::endl;
            if (thisname.size() >= thresh)
                sum += std::stoi(thisnum);
        }
        std::cout << sum << std::endl << "==========" << std::endl;
        csv.close();
    } else std::cout << "Unable to open supplied file!" << std::endl;

    return 0;
}