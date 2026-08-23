#include <iostream>
#include <vector>
using namespace std;

vector<int> brute(string s) {
    int n = s.size();
    vector<int> ans;
    
    for (int k = 1; k <= n; k++) {
        
        int eaten = k;
        vector<char> bag(s.begin(), s.begin() + k);
        
        int nxt = k;
        
        while (nxt < n) {
            
            bool found = false;
            
            for (int i = 0; i < bag.size(); i++) {
                if (bag[i] == 'o') {
                    bag.erase(bag.begin() + i);
                    found = true;
                    break;
                }
            }
            
            if (!found) break;
            
            bag.push_back(s[nxt]);
            eaten++;
            nxt++;
        }
        
        ans.push_back(eaten);
    }
    
    return ans;
}

int main() {
    
}