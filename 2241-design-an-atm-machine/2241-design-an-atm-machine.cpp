class ATM {
public:
    vector<int> cnt = vector<int>(5, 0);
    vector<int> notes = {20, 50, 100, 200, 500};
    ATM() {}

    void deposit(vector<int> deposit) {
        for (int i = 0; i < 5; i++) {
            cnt[i] += deposit[i];
        }
    }

    vector<int> withdraw(int amount) {
        int remm = amount;
        vector<int> take(5, 0);
        vector<int> ans;

        for (int i = 4; i >= 0; i--) {
            int req = remm / notes[i];
            take[i] = min(req, cnt[i]);
            remm -= take[i] * notes[i];
        }

        if (remm != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            cnt[i] -= take[i];
            ans.push_back(take[i]);
        }

        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */