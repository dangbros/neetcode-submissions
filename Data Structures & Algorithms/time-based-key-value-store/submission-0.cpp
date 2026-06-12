class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& entry = store[key];
        int l = 0, r = entry.size() - 1;
        string ans;

        while(l <= r){
            int mid = (l + r) / 2;
            if(entry[mid].first <= timestamp){
                ans = entry[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
