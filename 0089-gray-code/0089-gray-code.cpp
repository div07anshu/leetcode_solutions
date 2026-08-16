class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> gray(size);
        for (int i = 0; i < size; i++) {
            gray[i] = i ^ (i >> 1);
        }

        return gray ;
    }
};