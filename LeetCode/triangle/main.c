class Solution {
public:
	int min(int a,int b){
		if(a<b) return a;
		else return b;
	}
    int minimumTotal(vector<vector<int> > &triangle) {
        int sum = 0;
        if(triangle.size()==0) return 0;
        int level = triangle.size();
        int size;
        int i,j;
        for(j=level-2;j>=0;j--){
        	size = triangle[j].size();
        	for(i=0;i<size;i++){
        		triangle[j][i] = triangle[j][i]+min(triangle[j+1][i],triangle[j+1][i+1]);
        	}
        }
        return triangle[0][0];
    }
};