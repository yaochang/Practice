class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> upperLevel;
        vector<int> curLevel;
        int i,j;
        for(i=0;i<=numRows;i++){
        	for(j=0;j<i+1;j++){
        		if(j==0 || j==i){
        			curLevel.push_back(1);
        		}
        		else{
        			curLevel.push_back(upperLevel[j-1]+upperLevel[j]);
        		}
        	}
        	upperLevel = curLevel;
        	curLevel.clear();
        }
        return upperLevel;
    }
};