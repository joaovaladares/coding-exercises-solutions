class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        int l = 0, r = mp[key].size() - 1;
        string res = "";

        while(l <= r) {
            int m = l + (r - l) / 2;

            if (mp[key][m].second <= timestamp) {
                l = m + 1;
                res = mp[key][m].first;
            } else if (mp[key][m].second > timestamp) {
                r = m - 1;
            }
        } 
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */