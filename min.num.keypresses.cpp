#include<iostream> 
#include<vector> 
#include<unordered_map> 
#include<queue> 

using namespace std; 

class Solution{
public: 
      int minimumKeypresses(string s) {
        unordered_map<char,int> freq; 
        priority_queue<int> maxHeap; 

        for(char c:s){
          ++freq[c];
        }
        for(auto [ch, count]: freq){
          maxHeap.push(count); 
        }
        int counter =0; 
        int round = 1; 
        while(!maxHeap.empty()){
          for (int i = 0; i <= 9 && !maxHeap.empty(); ++i) {
                counter += round * maxHeap.top();
                maxHeap.pop();
            }
          ++round; 
        }
        return counter; 
      }
};
int main(){
  string s = "abcdefghijk";
  Solution sol; 
  cout << sol.minimumKeypresses(s) <<endl; 
  return 0; 
}
