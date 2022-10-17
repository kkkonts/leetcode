//спасибо дэнчику, я случайно подсмотрела его решение :(
    
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st {};
        
        for (auto charc : sentence) 
            st.insert(charc);
        return st.size() == 26;
    }
};