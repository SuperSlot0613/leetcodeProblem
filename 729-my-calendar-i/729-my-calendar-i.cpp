class MyCalendar {
public:
     vector<pair<int,int>>vp;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(auto it:vp)
        {
            if((start<it.first && end>it.first)||(start>it.first && end<=it.second)||(start>=it.first &&                   start<=it.second))
                return false;
        }
        vp.push_back({start,end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */