class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        // Har ek litter ('L') ko unique numeric identifier code assign karne ke liye grid matrix
        int[][] id = new int[m][n];

        for (int r = 0; r < m; r++) {
            java.util.Arrays.fill(id[r], -1);
        }

        int k = 0; // Total litter cells count tracks counter
        int sr = 0, sc = 0; // Starting position ('S') storage points

        // Step 1: Grid trace karke initial configurations mapping establish karo
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r].charAt(c) == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r].charAt(c) == 'L') {
                    id[r][c] = k++; // Zero-indexed sequential sequence mapping (0, 1, 2...)
                }
            }
        }

        // Agar classroom me already koi kachra (litter) bacha hi nahi hai, toh 0 moves needed
        if (k == 0) return 0;

        // Bitmask target boundary set matrix: pure bits ko 1 set karne ka formula (e.g., 3 ke liye (1<<3)-1 = 7 i.e. binary 111)
        int totalMask = (1 << k) - 1;

        // Best state tracker matrix configuration: [row][col][bitmask] -> Stores max energy achieved till here
        int[][][] best = new int[m][n][1 << k];

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                java.util.Arrays.fill(best[r][c], -1);
            }
        }

        // BFS traversal state properties encapsulation blueprint
        class State {
            int r, c, mask, e, moves;

            State(int r, int c, int mask, int e, int moves) {
                this.r = r;
                this.c = c;
                this.mask = mask;
                this.e = e;
                this.moves = moves;
            }
        }

        java.util.ArrayDeque<State> queue = new java.util.ArrayDeque<>();

        // Starting state setup process injection: primary energy values initialize karo 
        best[sr][sc][0] = energy;
        queue.offer(new State(sr, sc, 0, energy, 0));

        // Basic 4 directions displacement matrices control vectors (Up, Down, Left, Right)
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        // Step 2: Running dynamic optimized BFS queue cycle
        while (!queue.isEmpty()) {
            State cur = queue.poll();

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                // Coordinate points boundary limit tracking evaluation checks
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Wall obstacle barrier processing rule: skip 'X' elements
                if (classroom[nr].charAt(nc) == 'X')
                    continue;

                // Move operational shift cost deduct parameter execution
                int ne = cur.e - 1;

                // Agar zero coordinate limits collapse out reach cross negative shift cross negative step error block trigger point
                if (ne < 0)
                    continue;

                int nmask = cur.mask;

                // Recharge station mechanism operation: instant full tank logic sequence code
                if (classroom[nr].charAt(nc) == 'R') {
                    ne = energy;
                }

                // Kachra cell detection and handling pipeline setup using targeted bit manipulation masks logic
                if (classroom[nr].charAt(nc) == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                // Win condition check: Jaise hi agla configuration bit pattern check total full target scale reach kar jaye, exit and return
                if (nmask == totalMask) {
                    return cur.moves + 1;
                }

                // Optimization Pruning Step: Agar is cell aur is mask ke saath hume pehle hi isse zyada (ya barabar) energy mil chuki hai, toh is path ko drop karo!
                if (ne <= best[nr][nc][nmask])
                    continue;

                // State tracker arrays register updates records parameters allocation tracking sequence points
                best[nr][nc][nmask] = ne;

                // Queue parameter stack structure execution next loop registration
                queue.offer(new State(nr, nc, nmask, ne, cur.moves + 1));
            }
        }

        // Classroom completely blocked paths edge validation exception failures output
        return -1;
    }
}
