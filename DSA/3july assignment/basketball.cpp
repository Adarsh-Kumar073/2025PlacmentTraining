class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0; i< operations.size();i++){
            if(operations[i]=="+"){
                int a= st.top();
                st.pop();
                int b= st.top();
                st.push(a);
                int c= a+b;
                st.push(c);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int a= st.top();
                st.push(2*a);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        return ans;
    }
};