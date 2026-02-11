#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);

            } else if (c == ')' || c == '}' || c == ']') {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && c != top + 1) || ((c == '}' || c == ']') && c != top + 2))
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;

    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";
    std::string s4 = "([])";
    std::string s5 = "([)]";

    std::cout << "Test 1 \n"
              << solution.isValid(s1) << "\n";
    std::cout << "Test 2 \n"
              << solution.isValid(s2) << "\n";
    std::cout << "Test 3 \n"
              << solution.isValid(s3) << "\n";
    std::cout << "Test 4 \n"
              << solution.isValid(s4) << "\n";
    std::cout << "Test 5 \n"
              << solution.isValid(s5) << "\n";

    return 0;
}
