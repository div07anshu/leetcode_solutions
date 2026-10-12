class FreqStack {
public:
    int maxf = 0;
    map<int, list<int>> freq_list;
    map<int, int> freq;

    FreqStack() {}

    void push(int val) {
        freq[val]++;
        freq_list[freq[val]].push_back(val);
        maxf = max(maxf, freq[val]);
    }

    int pop() {
        int value = freq_list[maxf].back();
        freq_list[maxf].pop_back();

        freq[value]--;

        if (freq_list[maxf].empty()) {
            maxf--;
        }

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */