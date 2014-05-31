class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> upperLevel;
        vector<int> curLevel;
        if(numRows==0) return result;
        int i,j;
        for(i=0;i<numRows;i++){
        	for(j=0;j<i+1;j++){
        		if(j==0 || j==i){
        			curLevel.push_back(1);
        		}
        		else{
        			curLevel.push_back(upperLevel[j-1]+upperLevel[j]);
        		}
        	}
        	result.push_back(curLevel);
        	upperLevel = curLevel;
        	curLevel.clear();
        }
        return result;
    }
};