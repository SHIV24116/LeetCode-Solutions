class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;  // starting indices
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        // we assign every litter a particular id to make them distinguishable
        int k = 0;

        // Locate S and assign an ID to every litter cell.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    litterId[i][j] = k++;
                }
            }
        }
        // k = total litters
        int fullMask = (1 << k) - 1;
        // all 1 bits... all litters collected  (no. of bits == no. of litters)

        // If there is no litter.
        if (k == 0) return 0;

        struct State {  // defining our BFS states
            int r, c, mask, en;
        };
        queue<State> q;

        /*
            CHANGE FROM PREVIOUS CODE:

            Earlier we used:
                visited[r][c][mask][energy]

            This creates too many states because every possible energy
            value is treated as a separate state.
            Instead, for every (r,c,mask), we only store the maximum
            energy with which we have reached that state.
                maxEnergy[r][c][mask]
            If we have already reached the same (r,c,mask) with MORE
            or EQUAL energy, then reaching it again with less energy
            can never be useful, so we skip that state.

            This removes the energy dimension from visited and greatly
            reduces the number of states.
        */

        // maxEnergy[r][c][mask] = maximum energy with which we have reached (r,c) after collecting the litter represented by mask.
        vector<vector<vector<int>>> maxEnergy(m,vector<vector<int>>(n,vector<int>(1 << k, -1)));
        q.push({sr, sc, 0, energy}); // initially no litter collected so all bits 0
        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                State cur = q.front();
                q.pop();
                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int en = cur.en;

                // All litter collected.
                if (mask == fullMask) return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    // Cannot make a move with zero energy.
                    if (en == 0) continue;

                    int newEnergy = en - 1;
                    int newMask = mask;
                    // Collect litter if we enter its cell.
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << litterId[nr][nc]);
                        // jo already collected hai wo 1 rahega hi...sath me abhi wala bhi 1 ho jayega
                    }
                    // Reset energy on R.
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        If we have already reached the same (nr,nc,newMask)
                        with greater or equal energy, then this new state
                        is useless.
                    */
                    if (maxEnergy[nr][nc][newMask] >= newEnergy) continue;

                    // This is a better state because we reached the same (r,c,mask) with more energy.
                    maxEnergy[nr][nc][newMask] = newEnergy;
                    q.push({nr, nc, newMask, newEnergy});
                }
            }
            moves++;
        }
        return -1;
    }
    // So the BFS structure guarantees: A state is processed only after all states requiring fewer moves have been processed.
};