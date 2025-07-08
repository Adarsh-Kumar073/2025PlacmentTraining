class Solution {
public:
   
  void solve(string digits, int i, vector<string>& ans, string output, string map[]) {
        if (i >= digits.length()) {
            ans.push_back(output);
            return; 
        } 
        else {
            int num = digits[i] - '0';
            string dig = map[num];
            for (int j = 0; j < dig.length(); j++) {
                output.push_back(dig[j]);
                solve(digits, i + 1, ans, output, map);
                output.pop_back();  
            }
        }
   }
   
    vector<string> letterCombinations(string digits) {
        vector<string> ans ;
        if(digits.length()==0){
            return ans;
        }
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        int i=0;
        solve(digits, i, ans, output, map);
        return ans;
    }
};