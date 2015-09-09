class Solution {
public:
    bool legal(int i,int j, int m, int n,vector<vector<int> >&tag){
	if(i>=0 && i<m){
		if(j>=0 && j<n){
			if(tag[i][j]==0) return true;
		}
	}
	return false;
    }
    bool judge(vector<vector<char> >&board, vector<vector<int> >&tag,int i,int j,int curIndex,string word){
		if(curIndex == word.size()) return true;
		int m = board.size();
		int n = board[0].size();
		bool result = false;
		if(legal(i+1,j,m,n,tag)){
			if(board[i+1][j]==word[curIndex]){
				tag[i+1][j] = 1;
				result = judge(board,tag,i+1,j,curIndex+1,word);
				tag[i+1][j] = 0;
				if(result) return true;
			}
		}
		if(legal(i-1,j,m,n,tag)){
			if(board[i-1][j]==word[curIndex]){
				tag[i-1][j] = 1;
				result = judge(board,tag,i-1,j,curIndex+1,word);
				tag[i-1][j] = 0;
				if(result) return true;
			}
		}
		if(legal(i,j+1,m,n,tag)){
			if(board[i][j+1]==word[curIndex]){
				tag[i][j+1] = 1;
				result = judge(board,tag,i,j+1,curIndex+1,word);
				tag[i][j+1] = 0;
				if(result) return true;
			}
		}
		if(legal(i,j-1,m,n,tag)){
			if(board[i][j-1]==word[curIndex]){
				tag[i][j-1] = 1;
				result = judge(board,tag,i,j-1,curIndex+1,word);
				tag[i][j-1] = 0;
				if(result) return true;
			}
		}
		return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
  	int m = board.size();
	int n = board[0].size();
	if(word.size()==0) return true;
	if(m==0 || n==0) return false;
	vector<vector<int> > tag(m,vector<int>(n,0));
	bool result = false;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==word[0]){
				tag[i][j]=1;
				result = judge(board,tag,i,j,1,word);
				if(result) return true;
				tag[i][j]=0;
			}
		}
	}
	return false;      
    }
    
};
