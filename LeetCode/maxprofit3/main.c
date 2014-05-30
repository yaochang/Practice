class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0) return 0;
        int len = prices.size();
        int forwoardProfit[len];
        int backforward[len];
        int maxprofit = 0;
        int min=prices[0];
        for(int i=0;i<len;i++){
        	if(prices[i]-min > maxprofit){
        		maxprofit = prices[i] - min;
        	}
        	if(prices[i]<min){
        		min = prices[i];
        	}
        	forwoardProfit[i] = maxprofit;
        }
        maxprofit = 0;
        int max = prices[len-1];
        for(int i=len-1;i>=0;i--){
        	if(max - prices[i] > maxprofit){
        		maxprofit = max - prices[i];
        	}
        	if(prices[i] > max){
        		max = prices[i];
        	}
        	backforward[i] = maxprofit;
        }
        max = forwoardProfit[len-1];
        for(int i=0;i<len-1;i++){
        	if(forwoardProfit[i]+backforward[i+1]>max){
        		max = forwoardProfit[i]+backforward[i+1];
        	}
        }
        return max;
    }
};