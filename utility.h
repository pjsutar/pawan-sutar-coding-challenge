#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>



// Problem 1
/*!\brief Function to extract only the numerical characters from a string.
   \param inputString: input string containing possible numerical characters.
*/
std::string extractNumbersFromString(const std::string& inputString);


// Problem 2
/*!\brief Function to remove duplicates from a vector.
   \param inputVector: input vector containing the elements of certain type (mainly int or string).
*/
template <typename T>
std::vector<T> removeDuplicates(const std::vector<T>& inputVector)
{
    std::vector<T> result;
    std::unordered_set<T> visited;
    
    for (const T& element : inputVector) {
        if (visited.find(element) == visited.end()) {
            visited.insert(element);
            result.push_back(element);
        }
    }
    return result;
}


// Problem 3
/*!\brief Struct to store specialty info with id as real number and name as std::string.
*/
struct Specialty {
    int id;
    std::string name;
};


/*!\brief Function to find out the IDs and return corresponding specialty names.
   \param IDs: vector containing the IDs as strings (string IDs possibly contain numbers and special characters).
   \param specialties: vector containing the structs that represent specialties and their IDs.
*/
std::vector<std::string> getSpecialtyNames(const std::vector<std::string>& IDs, 
					const std::vector<Specialty>& specialties);