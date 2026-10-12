class RandomizedSet {
public:
    unordered_map<int, int> mp; // val ->idx ;
    vector<int> arr;
    RandomizedSet() {}

    bool insert(int val) {
        int n = arr.size();

        if (!mp.count(val)) {
            arr.push_back(val);
            mp[val] = n;
            return true;
        }

        return false;
    }

    bool remove(int val) {
        int n = arr.size();
        if (mp.count(val)) {
            int idx = mp[val];
            arr[idx] = arr.back();

            mp[arr.back()] = idx;
            mp.erase(val);
            arr.pop_back();
            return true;
        }

        return false;
    }

    int getRandom() { return arr[rand() % arr.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */