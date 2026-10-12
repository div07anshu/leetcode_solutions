using pii = pair<int, int>;
class LRUCache {
public:
    list<pii> lis;
    unordered_map<int, list<pii>::iterator> mp;
    int limit;
    LRUCache(int capacity) { limit = capacity; }

    int get(int key) {
        if (mp.count(key)) {
            auto it = mp[key];
            int value = it->second;

            lis.erase(it);
            lis.push_back({key, value});
            mp[key] = prev(lis.end()); // lis.end() gives address of null
            return value;
        }

        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            auto it = mp[key];
            it->second = value;

            lis.erase(it);
            lis.push_back({key, value});
            mp[key] = prev(lis.end());
        } else {

            if (lis.size() == limit) {
                auto it = lis.begin();
                mp.erase(it->first);
                lis.erase(it);
            }

            lis.push_back({key, value});
            mp[key] = prev(lis.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */