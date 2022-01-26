#include <cstdio>
#include <iostream>

namespace util {

class OutputManager
{
public:
    void new_line()
    {
        std::cout << std::endl;
    }

    void print_vector(const std::vector<int>& vec)
    {
        std::cout << "[ ";
        for (const auto val : vec) {
            printf("%5d", val);
        }
        std::cout << " ]" << std::endl;
    }

    void print_vector(const std::vector<bool>& vec)
    {
        std::cout << "[ ";
        for (const auto val : vec) {
            printf("%s ", val ? "true" : "false");
        }
        std::cout << " ]" << std::endl;
    }

    void print_matrix(const std::vector<std::vector<int>>& mat)
    {
        for (const auto& vec : mat) {
            print_vector(vec);
        }
    }

    void print_bytes(int n) {
        unsigned char* words = reinterpret_cast<unsigned char*>(&n);
        size_t numWords = sizeof(int);

        for (size_t i = 0; i < numWords; ++i) {
            //std::cout << "0x";
            printf("%x ", words[i]);
        }
        std::cout << std::endl;
    }

    void print_string(std::string& str) {
        std::cout << str << std::endl;
    }

    void print_string(std::string&& str) {
        std::cout << str << std::endl;
    }

    void print_int(int number) {
        std::cout << number << std::endl;
    }
};

static OutputManager opm{};

} // namespace util
