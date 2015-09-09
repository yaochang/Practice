bool isValidSudoku(vector<vector<char> > &board) {
        int expect[10];
	int tmp;
	for(int i=0;i<9;i++){
		memset(expect,0,sizeof(expect));
		for(int j=0;j<9;j++){
			if(board[i][j]=='.') continue;
			tmp = board[i][j] - '0';
			if(tmp > 9 || tmp < 1) return false;
			expect[tmp]++;
			if(expect[tmp]>1) return false;
		}
	}

	for(int j=0;j<9;j++){
		memset(expect,0,sizeof(expect));
		for(int i=0;i<9;i++){
			if(board[i][j]=='.') continue;
			tmp = board[i][j]-'0';
			if(tmp>9 || tmp<1) return false;
			expect[tmp]++;
			if(expect[tmp]>1) return false;
		}
	}

	for(int i=0;i<9;i=i+3){
		for(int j=0;j<9;j=j+3){
			memset(expect,0,sizeof(expect));
			for(int ii=0;ii<3;ii++){
				for(int jj=0;jj<3;jj++){
					if(board[i+ii][j+jj]=='.') continue;
					tmp = board[i+ii][j+jj]-'0';
					expect[tmp]++;
					if(expect[tmp]>1) return false;
				}
			}
		}
	}
	return true;
}
