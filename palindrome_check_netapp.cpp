#include <string>
#include <iostream>

using namespace std;

/**
 * Determines if a given string is a palindrome. Runs in O(n) time and uses
 * O(1) extra space.
 *
 * @param inputStr  A string that may contain any printable ASCII character.
 *
 * @return          True if the input string is a palindrome, false otherwise.
 */

bool ignore(char ch){

    if ((ch == '!') || (ch == ' '))
        return true;
    
    return false;
}

bool isPalindrome(const std::string& input) {
 
    /**
     * Your code here.
    */

//    int start_pointer = 0;    // start_index pointer 
//    int end_pointer = input.size()-1; // end_index pointer

    auto start_pointer = input.begin();
    auto end_pointer = input.end()-1;

   while(start_pointer < end_pointer ){ 


        while (ignore(*start_pointer) && start_pointer < end_pointer){
            start_pointer++;
        }

        while(ignore(*end_pointer) && start_pointer < end_pointer)
        if(*start_pointer != *end_pointer)
            return false;
        
        start_pointer++;
        end_pointer--;

   } 


    return true;
 
}


// * Determines if a given string is a palindrome. Ignores capitalization,
//  * punctuation, and spaces. Runs in O(n) time and uses O(1) extra space.

//, . ? ! space

