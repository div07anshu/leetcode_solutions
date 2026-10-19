class Bitset {
public:
    int cnt1 = 0;
    string str;
    bool fliped = false;
    Bitset(int size) { str.resize(size, '0'); }

    void fix(int idx) {
        char actual = fliped ? (str[idx] == '0' ? '1' : '0') : str[idx];

        if (actual == '0') {
            cnt1++;
            str[idx] = fliped ? '0' : '1';
        }
    }

    void unfix(int idx) {
        char actual = fliped ? (str[idx] == '0' ? '1' : '0') : str[idx];

        if (actual == '1') {
            cnt1--;
            str[idx] = fliped ? '1' : '0';
        }
    }

    void flip() {
        fliped = !fliped;
        cnt1 = str.size() - cnt1;
    }

    bool all() { return cnt1 == str.size(); }
    bool one() { return cnt1 > 0; }
    int count() { return cnt1; }

    string toString() {
        string ans = str;
        if (fliped) {
            for (int i = 0; i < ans.size(); i++) {
                ans[i] = (ans[i] == '0') ? '1' : '0';
            }
        }

        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */