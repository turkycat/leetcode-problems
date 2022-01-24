#include "pch.h"
#include "output-manager.h"

using namespace std;
using namespace util;
/*

---------------------------------------
Problem 921
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
---------------------------------------
Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:
   It is the empty string,
   It can be written as AB (A concatenated with B), where A and B are valid strings, or
   It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))"

Return the minimum number of moves required to make s valid.

---------------------------------------
Strategy
---------------------------------------
count the number of open parenthesis.

if current character is openp, add to count
if current character is closep
  if current open count is greater than zero, decrement open count
  else, add one to total moves (open parenth must be inserted)

at the end: open count is added to total moves and returned

*/
int minAddToMakeValid(string s) {
    size_t unresolved_right_parens = 0;
    size_t unresolved_left_parens = 0;

    for (const auto& c : s) {
        if (c == '(') {
            ++unresolved_left_parens;
        }
        else if (c == ')') {
            if (unresolved_left_parens > 0) {
                --unresolved_left_parens;
                continue;
            }
            else {
                ++unresolved_right_parens;
            }
        }
    }

    return static_cast<int>(unresolved_left_parens + unresolved_right_parens);
}

int main(int argc, char** argv){
    std::string parenth1 = "())";       //1
    std::string parenth2 = "(((";       //3
    std::string parenth3 = "()";        //0
    std::string parenth4 = "()))((";    //4

    opm.print_string(parenth1);
    opm.print_int(minAddToMakeValid(parenth1));
    opm.new_line();
    opm.print_string(parenth2);
    opm.print_int(minAddToMakeValid(parenth2));
    opm.new_line();
    opm.print_string(parenth3);
    opm.print_int(minAddToMakeValid(parenth3));
    opm.new_line();
    opm.print_string(parenth4);
    opm.print_int(minAddToMakeValid(parenth4));
    opm.new_line();

    return 0;
}
