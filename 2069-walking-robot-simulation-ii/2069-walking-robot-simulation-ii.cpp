class Robot {
private:
    int w, h;
    int perim;                 // perimeter length = 2*(w+h)-4
    int x, y;                  // current position
    int dir;                   // 0=East, 1=North, 2=West, 3=South
    vector<string> dirs = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perim = 2 * (w + h) - 4;
        x = 0;
        y = 0;
        dir = 0; // East
    }

    void step(int num) {
        // Reduce unnecessary full loops
        num %= perim;

        // Special rule:
        // If robot is at (0,0) and makes a full cycle (num == 0 after modulo),
        // it ends at (0,0) facing South.
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int can = (w - 1) - x;
                if (can >= num) {
                    x += num;
                    num = 0;
                } else {
                    x = w - 1;
                    num -= can;
                    dir = 1; // turn North
                }
            } 
            else if (dir == 1) { // North
                int can = (h - 1) - y;
                if (can >= num) {
                    y += num;
                    num = 0;
                } else {
                    y = h - 1;
                    num -= can;
                    dir = 2; // turn West
                }
            } 
            else if (dir == 2) { // West
                int can = x;
                if (can >= num) {
                    x -= num;
                    num = 0;
                } else {
                    x = 0;
                    num -= can;
                    dir = 3; // turn South
                }
            } 
            else { // South
                int can = y;
                if (can >= num) {
                    y -= num;
                    num = 0;
                } else {
                    y = 0;
                    num -= can;
                    dir = 0; // turn East
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};