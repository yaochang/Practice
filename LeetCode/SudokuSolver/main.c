bool search(vector<vector<char> > &board, int level){
	if(level==81) return true;
	int x = level / 9;
	int y = level % 9;
	if(board[x][y]!='.') return search(board,level+1);
	int candidate[10];
	int res = false;
	memset(candidate,0,sizeof(candidate));
	for(int j=0;j<9;j++){
		if(board[x][j]=='.') continue;
		candidate[board[x][j]-'0']++;
	}
	for(int i=0;i<9;i++){
		if(board[i][y]=='.') continue;
		candidate[board[i][y]-'0']++;
	}
	int baseX = x/3;
	int baseY = y/3;
	for(int i=baseX*3;i<baseX*3+3;i++){
		for(int j=baseY*3;j<baseY*3+3;j++){
			if(board[i][j]=='.') continue;
			candidate[board[i][j]-'0']++;
		}
	}
	for(int i=1;i<=9;i++){
		if(candidate[i]>0) continue;
		board[x][y] = i + '0';
		res = search(board,level+1);
		if(res==true) return true;
		board[x][y] = '.';
	}
	return false;
}




void solveSudoku(vector<vector<char> > &board) {
        search(board,0);
}

