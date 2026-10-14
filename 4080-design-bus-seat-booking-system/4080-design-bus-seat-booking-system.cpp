class BusBooking {
public:
    vector<vector<int>> grid;
    int tot = 0;
    int window = 0;
    int middle = 0;
    unordered_map<string, int> mp;
    BusBooking(int n) { grid.resize(4, vector<int>(n, 0)); }

    void toggle(string seat) {
        int row = seat[0] - 'A';
        int col = stoi(seat.substr(1)) - 1;
        if (grid[row][col] == 0) {
            if (row == 1 || row == 2) {
                tot += 1;
                mp[seat] = 1;
            } else if (row == 0 && grid[1][col] == 1) {
                tot += 3;
                mp[seat] = 3;
            } else if (row == 3 && grid[2][col] == 1) {
                tot += 3;
                mp[seat] = 3;
            } else {
                tot += 1;
                mp[seat] = 1;
            }

            if (row == 0 || row == 3) {
                window++;
            } else {
                middle++;
            }

        } else {
            if (row == 0 || row == 3) {
                window--;
            } else {
                middle--;
            }

            tot -= mp[seat];
        }

        grid[row][col] ^= 1;
    }

    int getTotalTime() { return tot; }

    int getMinTime() { return window + middle; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */