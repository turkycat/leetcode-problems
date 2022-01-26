#include "pch.h"
#include "output-manager.h"

using namespace std;
using namespace util;
/*

---------------------------------------
Problem 1018
---------------------------------------
Binary Prefix Divisible By 5

You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

    For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.

Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

1 <= nums.length <= 105
nums[i] is either 0 or 1

---------------------------------------
Strategy
---------------------------------------
Pretty simple. Read from left to right maintaining a running total. At each step, left shift total by 1 and add
the current index to get the total for that index. set true for that index if total % 5 == 0

*/

vector<bool> prefixesDivBy5(vector<int>& nums) {
    size_t total = 0;
    std::vector<bool> bools;
    for (int &num : nums) {
        total = ((total << 1) + static_cast<size_t>(num)) % 10;
        bools.push_back(total % 5 == 0);
    }
    return bools;
}


int main(int argc, char** argv){
    std::vector<int> example1{ 1, 0, 1 }; // false, false, true (5)
    std::vector<int> example2{ 1, 1, 1 }; // false, false, false
    std::vector<int> example3{ 0, 1, 0, 1 }; // true, false, false, true (5)
    std::vector<int> example4{ 1, 1, 1, 1, 1, 0, 1 }; // false, false, false, true (15), false, false, true (125)

    // observation, if we first encode '5' {1, 0, 1}, then every 0 after that will be 5 to the power of another 2
    // false, false, true indefinitely
    std::vector<int> example5{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; 

    opm.print_vector(example1);
    opm.print_vector(prefixesDivBy5(example1));
    opm.new_line();
    opm.print_vector(example2);
    opm.print_vector(prefixesDivBy5(example2));
    opm.new_line();
    opm.print_vector(example3);
    opm.print_vector(prefixesDivBy5(example3));
    opm.new_line();
    opm.print_vector(example4);
    opm.print_vector(prefixesDivBy5(example4));
    opm.new_line();
    opm.print_vector(example5);
    opm.print_vector(prefixesDivBy5(example5));
    opm.new_line();

    return 0;
}
