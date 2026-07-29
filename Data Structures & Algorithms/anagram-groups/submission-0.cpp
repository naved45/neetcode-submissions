

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
            // Map to store the sorted string as key and its anagrams as values
                    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
                            
                                    for (const std::string& str : strs) {
                                                std::string sortedStr = str;
                                                            // Sorting the string brings anagrams to the identical base form
                                                                        std::sort(sortedStr.begin(), sortedStr.end());
                                                                                    
                                                                                                // Group the original string by its sorted representation
                                                                                                            anagramGroups[sortedStr].push_back(str);
                                                                                                                    }
                                                                                                                            
                                                                                                                                    // Collect all grouped anagrams into the final result vector
                                                                                                                                            std::vector<std::vector<std::string>> result;
                                                                                                                                                    for (auto& pair : anagramGroups) {
                                                                                                                                                                result.push_back(std::move(pair.second));
                                                                                                                                                                        }
                                                                                                                                                                                
                                                                                                                                                                                        return result;
                                                                                                                                                                                            }
                                                                                                                                                                                            };
                                                                                                                                                                                            