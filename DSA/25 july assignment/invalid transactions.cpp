struct info{
    string name;
    int price;
    int time;
    string city;
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        vector<info> tmod;
        string st = "";
        info temp;
        int count;
        for (int i = 0 ;i<transactions.size();i++){
            count = 0;
            for (int j = 0;j<transactions[i].size();j++){
                if (transactions[i][j]==','){
                    if (count==0)
                        temp.name = st;
                    if (count==1)
                        temp.time = stoi(st);
                    if (count==2)
                        temp.price = stoi(st);
                    count++;
                    st = "";
                    continue;
                }
                st+=transactions[i][j];
            }
            temp.city = st;
            tmod.push_back(temp);
            st = "";
        }
		
        vector<string> result;
        bool found = false;
        for (int i = 0;i<tmod.size();i++){
            found = false;
            if (tmod[i].price>=1000){
                result.push_back(transactions[i]);
                continue;
            }
            for (int j = 0;j<tmod.size();j++){   
                if (i == j) continue;
                if (tmod[i].name==tmod[j].name && (abs)(tmod[i].time-tmod[j].time)<=60 && tmod[i].city!=tmod[j].city){
                    found = true;
                    break;
                }
            }
            if (found){
                result.push_back(transactions[i]);
                found = false;
            }
        }
        return result;
    }
};