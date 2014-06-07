ass Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> h;
        stack<int> n;
        int len = height.size();
        if(len==0) return 0;
        h.push(0);
        n.push(0);
        int tmp;
        int number;
        int max = 0;
        for(int i=0;i<len;i++){
            tmp = height[i];
            number = 1;
            while(tmp <= h.top()){
                number = number + n.top();
                if(h.top()*(number-1) > max) max = h.top()*(number-1);
                n.pop();
                h.pop();
                if(h.empty()) break;
            }
            if(max < tmp * number ) max = tmp * number;
            h.push(tmp);
            n.push(number);
        }
        number = 0;
        while(!h.empty()){
            tmp = h.top();
            h.pop();
            number = number + n.top();
            n.pop();
            if(max < tmp * number) max = tmp * number;
        }
        return max;
    }
};
