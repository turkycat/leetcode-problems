#include "pch.h"
#include "output-manager.h"

using namespace std;
using namespace util;
/*

---------------------------------------
Problem 1464
---------------------------------------
Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1). 

Constraints:

    2 <= nums.length <= 500
    1 <= nums[i] <= 10^3


---------------------------------------
Strategy
---------------------------------------
store the max and 2nd max, scan through the array starting at [2], any time you find an element equal to or bigger than max, set 2nd max = max and set max = new number

*/

int maxProduct(vector<int>& nums) {
    int firstMax = 0;
    int secondMax = 0;

    for (auto num : nums) {
        if (num > firstMax) {
            secondMax = max(firstMax, secondMax);
            firstMax = num;
            continue;
        }

        secondMax = max(num, secondMax);
    }

    return (firstMax - 1) * (secondMax - 1);
}


int main(int argc, char** argv){

    std::vector<int> maxes1{ 3, 4, 5, 2};
    opm.print_vector(maxes1);
    opm.print_int(maxProduct(maxes1)); //12

    std::vector<int> maxes2{ 1, 5, 4, 5 };
    opm.print_vector(maxes2);
    opm.print_int(maxProduct(maxes2)); //16

    std::vector<int> maxes3{ 10, 2, 5, 2 };
    opm.print_vector(maxes3);
    opm.print_int(maxProduct(maxes3)); //36

    return 0;
}
