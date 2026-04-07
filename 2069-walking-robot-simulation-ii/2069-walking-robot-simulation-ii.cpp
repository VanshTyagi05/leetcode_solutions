class Robot {
public:
    int m, n;      // m = height, n = width
    int x, y;      // position
    int angle;     // 0: East, 90: North, 180: West, 270: South
    unordered_map<int, char> angle_dir;

    Robot(int width, int height) {
        n = width;
        m = height;
        x = 0;
        y = 0;
        angle = 0; // Starts facing East per your mapping
        angle_dir[0] = 'E';
        angle_dir[90] = 'N';
        angle_dir[180] = 'W';
        angle_dir[270] = 'S';
    }

    void step(int num) {
        // Optimization: Use modulo to avoid unnecessary laps
        int perimeter = 2 * (n + m - 2);
        if (num >= perimeter) num %= perimeter;
        
        // Special case: If we complete a full lap and end at (0,0), 
        // the robot faces South in the LeetCode version of this problem.
        if (num == 0 && x == 0 && y == 0) {
            angle = 270; 
        }

        while (num > 0) {
            char direction = angle_dir[angle];
            if (direction == 'E') {
                if (x + 1 < n) { x++; num--; }
                else angle = 90; // Turn North
            } else if (direction == 'N') {
                if (y + 1 < m) { y++; num--; }
                else angle = 180; // Turn West
            } else if (direction == 'W') {
                if (x - 1 >= 0) { x--; num--; }
                else angle = 270; // Turn South
            } else if (direction == 'S') {
                if (y - 1 >= 0) { y--; num--; }
                else angle = 0; // Turn East
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        char curr_dir = angle_dir[angle];
        if (curr_dir == 'E') return "East";
        if (curr_dir == 'W') return "West";
        if (curr_dir == 'N') return "North";
        return "South";
    }
};
