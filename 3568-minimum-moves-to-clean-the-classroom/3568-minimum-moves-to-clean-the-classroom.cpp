class Solution {
public:
    using vb = vector<bool>;
    using vvb = vector<vb>;
    using vvvb = vector<vvb>;
    using vvvvb = vector<vvvb>;

    struct State {
        int r, c, energy, mask;
    };

    int minMoves(vector<string>& room, int energy) {
        int n = room.size();
        int m = room[0].size();
        int maxe = energy;
        int litterBit[20][20];
        int littercnt = 0;
        int startR = 0, startC = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                litterBit[i][j] = -1;

                if (room[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (room[i][j] == 'L') {
                    litterBit[i][j] = littercnt;
                    littercnt++;
                }
            }
        }

        int allcollected = (1 << littercnt) - 1;
        if (littercnt == 0)
            return 0;

        queue<State> q;
        q.push({startR, startC, maxe, 0});
        vvvvb visited(n, vvvb(m, vvb(maxe + 1, vb(1 << littercnt, false))));
        visited[startR][startC][maxe][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r, c = cur.c;
                int e = cur.energy, mask = cur.mask;

                if (mask == allcollected)
                    return moves;

                if (e == 0)
                    continue;


                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if (room[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (room[nr][nc] == 'R')
                        ne = maxe;

                    if (room[nr][nc] == 'L') {
                        int bit = litterBit[nr][nc];
                        nmask |= (1 << bit);
                    }

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};