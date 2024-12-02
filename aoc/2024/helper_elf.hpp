#include <iostream>
#include <sstream>
#include <vector>

class Elf {
private:
    std::istream *is;
public:
    Elf(std::istream &is) {
        this->is = &is;
    }

    std::vector<int> readInts() {
        std::vector<int> a;
        int x;
        while ((*is) >> x) {
            a.push_back(x);
        }
        return a;
    }

    std::vector<std::vector<int>> readInts2D() {
        std::vector<std::vector<int>> a;
        std::string line;
        while (std::getline((*is), line)) {
            std::vector<int> b;
            std::stringstream iss(line);
            int x;
            while (iss >> x) {
                b.push_back(x);
            }
            a.push_back(b);
        }
        return a;
    }

    std::vector<std::string> readStrings() {
        std::vector<std::string> a;
        std::string x;
        while ((*is) >> x) {
            a.push_back(x);
        }
        return a;
    }
};
