ass Solution {
  public:
       int min(int a,int b){
           int m = 0;
           if(a>=b && b>=0) return b;
           if(b>=a && a>=0) return a;
           return 0;
       }
       int maxArea(vector<int> &height) {
          vector<int> index;
          vector<int> h;
          int len = height.size();
          if(len<2) return 0;
          int max = 0;
          int i,j;
          index.push_back(0);
          h.push_back(height[0]);
          int curh=height[0];
          int curi=0;
          for(i=1;i<len;i++){
                  if(height[i]>=curh){
                          if(curh*(i-curi)>max) max = curh*(i-curi);
                          index.push_back(i);
                          h.push_back(height[i]);
                          curh = height[i];
                          curi = i;
                  }else{  
                          for(j=0;j<h.size();j++){
                                  if(max < min(height[i],h[j])*(i-index[j])){
                                          max = min(height[i],h[j])*(i-index[j]);
                                  }
                          }
                  }
          }
          for(j=0;j<h.size();j++){
                  if(h[j]*(curi-index[j]) > max) max = h[j]*(curi-index[j]);
          }
          return max;
      }
  };
