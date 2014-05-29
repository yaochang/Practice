class Solution {
public:
struct coordinate{
	int x;
	int y;
	bool operator < (const coordinate& t) const{
		return t.x < x;
	}
};


bool eligible(int x,int y, int xsize, int ysize){
	if(x>=0 && x<xsize && y>=0 && y<ysize){
		return true;
	}
	return false;
}
void solve(vector<vector<char> > &board){
	int xsize, ysize;
	xsize = board.size();
	if(xsize==0) return;
	ysize = board[0].size();
	if(ysize==0) return;
	
	int i,j;
	bool flag[xsize][ysize];
	coordinate t;
	set<coordinate> result;
	queue<coordinate> q;
	memset(flag,0,sizeof(flag));
	for(j=0;j<ysize;j++){
		if(board[0][j]=='O'){
			t.x = 0;
			t.y = j;
			flag[0][j] = true;
			result.insert(t);
			q.push(t);
		}
		if(board[xsize-1][j]=='O'){
			t.x = xsize - 1;
			t.y = j;
			flag[xsize-1][j] = true;
			result.insert(t);
			q.push(t);
		}
	}
	for(i=0;i<xsize;i++){
		if(board[i][0]=='O'){
			t.x = i;
			t.y = 0;
			flag[i][0] = true;
			result.insert(t);
			q.push(t);
		}
		if(board[i][ysize-1]=='O'){
			t.x = i;
			t.y = ysize-1;
			flag[i][ysize-1] = true;
			result.insert(t);
			q.push(t);
		}
	}
	while(!q.empty()){
		t = q.front();
		q.pop();
		i = t.x;
		j = t.y;
		if(eligible(i-1,j,xsize,ysize)){
			if(flag[i-1][j] == false && board[i-1][j] == 'O'){
				t.x = i-1;
				t.y = j;
				result.insert(t);
				q.push(t);
				flag[i-1][j] = true;
			}
		}
		if(eligible(i+1,j,xsize,ysize)){
			if(flag[i+1][j] == false && board[i+1][j] == 'O'){
				t.x = i+1;
				t.y = j;
				result.insert(t);
				q.push(t);
				flag[i+1][j] = true;
			}
		}
		if(eligible(i,j-1,xsize,ysize)){
			if(flag[i][j-1] == false && board[i][j-1] == 'O'){
				t.x = i;
				t.y = j-1;
				result.insert(t);
				q.push(t);
				flag[i][j-1] = true;
			}
		}
		if(eligible(i,j+1,xsize,ysize)){
			if(flag[i][j+1] == false && board[i][j+1] == 'O'){
				t.x = i;
				t.y = j+1;
				result.insert(t);
				q.push(t);
				flag[i][j+1] = true;
			}
		}
	}
	for(i=0;i<xsize;i++){
		for(j=0;j<ysize;j++){
			if(flag[i][j]==true){
			    board[i][j] = 'O';
			}else{
			    board[i][j] = 'X';
			}
		}
	}

} 
};