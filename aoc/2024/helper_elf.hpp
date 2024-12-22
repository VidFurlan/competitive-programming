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

    std::vector<long long> readLongs() {
        std::vector<long long> a;
        int x;
        while ((*is) >> x) {
            a.push_back(x);
        }
        return a;
    }

    std::vector<std::vector<long long>> readLong2D() {
        std::vector<std::vector<long long>> a;
        std::string line;
        while (std::getline((*is), line)) {
            std::vector<long long> b;
            std::stringstream iss(line);
            long long x;
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

    std::vector<std::string> readLines() {
        std::vector<std::string> a;
        std::string x;
        while (std::getline(*is, x)) {
            a.push_back(x);
        }
        return a;
    }
};
