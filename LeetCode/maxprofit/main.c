class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxprofit = 0;
        int tmpprofit;
        if(prices.size()==0) return 0;
        int min=prices[0];
        for(int i=0;i<prices.size();i++){
        	if(prices[i]-min > maxprofit){
        		maxprofit = prices[i] - min;
        	}
        	if(prices[i]<min){
        		min = prices[i];
        	}
        }
        return maxprofit;
    }
};