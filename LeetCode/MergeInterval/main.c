	
   vector<Interval> merge(vector<Interval> &intervals) {
   	std::sort(intervals.begin(),intervals.end(),[](Interval const&a, Interval const&b){
		if(a.start < b.start) return true;
		if(a.start > b.start) return false;
		
		if(a.end < b.end) return true;
		if(a.end > b.end) return false;
		return false;
	});
	vector<Interval> result;
	int size = intervals.size();
	if(size==0) return result;
	int s=0,e=0,i;
	s = intervals[0].start;
	e = intervals[0].end;
	for(i=1;i<size;i++){
		if(intervals[i].start>e){
			result.push_back(Interval(s,e));
			s = intervals[i].start;
			e = intervals[i].end;
		}else{
			if(intervals[i].end > e){
				e = intervals[i].end;
			}
		}
	}
	result.push_back(Interval(s,e));
	return result;     
   }
