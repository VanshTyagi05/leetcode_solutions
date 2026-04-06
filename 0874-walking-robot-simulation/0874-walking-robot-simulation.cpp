class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int angle = 90; // iniially he is facing north

        unordered_map<int, char> angle_dir;
        angle_dir[90] = 'N';
        angle_dir[0] = 'E';
        angle_dir[180] = 'W';
        angle_dir[270] = 'S';
        set<pair<int, int>> s; // to check for obstacles
        for (int i = 0; i < obstacles.size(); i++) {
            int x1 = obstacles[i][0];
            int y1 = obstacles[i][1];
            s.insert({x1, y1});
        }
        int ans = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                angle = (angle - 90 + 360) % 360;
            } else if (commands[i] == -2) {
                angle = (angle + 90) % 360;
            } else {
                int k = commands[i];
                while (k--) {
                    // we will move each step one by one
                    char direction = angle_dir[angle];
                    if (direction == 'E') {
                        int newX = x + 1;
                        if (s.contains({newX, y}))
                            break;
                        else {
                            x = newX;
                        }
                    } else if (direction == 'W') {
                        int newX = x - 1;
                        if (s.contains({newX, y}))
                            break;
                        else {
                            x = newX;
                        }
                    } else if (direction == 'N') {
                        int newY = y + 1;
                        if (s.contains({x, newY}))
                            break;
                        else {
                            y = newY;
                        }
                    } else {
                        int newY = y - 1;
                        if (s.contains({x, newY}))
                            break;
                        else {
                            y = newY;
                        }
                    }
                }
            }

            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};