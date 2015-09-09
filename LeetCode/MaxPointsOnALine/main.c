int maxPoints(vector<Point> &points) {
	unordered_map<double,int> k;
	int repeat = 0;
	int vertical = 0;
	int size = points.size();
	int i,j;
	if(size == 0) return 0;
	int max = INT_MIN;
	int curX,curY,tmpX,tmpY;
	int tmpMax;
	double tmpK;
	for(i=0;i<size;i++){
		k.clear();
		repeat = 0;
		vertical = 0;
		curX = points[i].x;
		curY = points[i].y;
		tmpMax = INT_MIN;
		for(j=0;j<size;j++){
			tmpX = points[j].x;
			tmpY = points[j].y;
			if(tmpX == curX && tmpY == curY){
				repeat++;
				continue;
			}
			if(tmpX == curX){
				vertical++;
				continue;
			}
			tmpK = ((tmpY-curY)*1.0)/((tmpX-curX)*1.0);
			if(k.find(tmpK)==k.end()){
				k[tmpK] = 1;
			}else{
				k[tmpK]++;
			}
			if(tmpMax < k[tmpK]) tmpMax = k[tmpK];
		}
		if(vertical > tmpMax) tmpMax = vertical;
		if(tmpMax + repeat > max) max = tmpMax + repeat;
	}
	return max;        
}
