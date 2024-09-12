#include <vector>
#include <iostream>

/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        
        plusOne(digits, digits.size() - 1);
        return digits;       
    }

    void plusOne(std::vector<int>& digits, int i) {
        if (digits[i] == 9 ){
            digits[i] = 0;

            if (i > 0)
                plusOne(digits, i-1);
            else if (i == 0)
                digits.insert(digits.begin(), 1);
        
        } else {
            digits[i] = digits[i] + 1; 
        }
    }


};

void printVector(std::vector<int>& nums){
  std::cout << "Vector elements: ";
  for (int i: nums)
    std::cout << i << ',';
}

int main () {
  Solution solution;
  std::vector < int >test1 = { 1,2,3 };
  std::vector < int >test2 = { 4,3,2,1};
  std::vector < int >test3 = { 9 };
   
  std::cout << "Test 1" << "\n";
  printVector(test1);
  
  solution.plusOne(test1);

  printVector(test1);

  std::cout << "\n" << "Test 2" << "\n";
  printVector(test2);

  solution.plusOne(test2);

  printVector(test2);

  std::cout << "Test 3" << "\n";
  printVector(test3);
  
  solution.plusOne(test3);

  printVector(test3);

  return 0;
}