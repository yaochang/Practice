class Solution {
public:
    int maxProfit(vector<int> &prices) {
        bool buyORsell = true;// true for buy, fasle for sell
        int len = prices.size();
        int max = 0;
        int buy=1000000,sell=0;
        int index = 0;
        while(index < len){
            if(buyORsell){
                if(buy >= prices[index]){
                    buy = prices[index];
                }else{
                    buyORsell = false;
                    sell = prices[index];
                }
            }else{
                if(sell <= prices[index]){
                    sell = prices[index];
                }else{
                    max = max + sell - buy;
                    buy = prices[index];
                    buyORsell = true;
                }
            }
            index++;
        }
        if(buyORsell==false){
            max = max + sell - buy;
        }
        return max;
    }
};