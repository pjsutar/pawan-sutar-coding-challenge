#include "utility.h"

// Problem 1
std::string extractNumbersFromString(const std::string& inputString)
{
    std::string result;
    for (char c : inputString) {
        if (std::isdigit(c)) {
            result += c;
        }
    }
    return result;
}


// Problem 3
std::vector<std::string> getSpecialtyNames(const std::vector<std::string>& IDs, const std::vector<Specialty>& specialties)
{
    std::vector<std::string> result;
    
    std::vector<std::string> stringIDs(IDs.size());
    std::vector<int> realIDs(IDs.size());

    for (int i = 0; i < stringIDs.size(); i++) {
        stringIDs[i] = extractNumbersFromString(IDs[i]);
        realIDs[i] = std::stoi(stringIDs[i]);
    }
    
    std::vector<int> uniqueRealIDs = removeDuplicates(realIDs);
    
    // Store Specialty Names by their IDs
    std::unordered_map<int, std::string> idToNameMap;
    
    for (const Specialty& specialty : specialties) {
        idToNameMap[specialty.id] = specialty.name;
    }
    
    for (int id : uniqueRealIDs) {
        result.push_back(idToNameMap[id]);
    }
    
    return result;
}
