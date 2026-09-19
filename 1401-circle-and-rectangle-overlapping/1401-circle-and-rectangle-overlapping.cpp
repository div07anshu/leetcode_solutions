class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xi = clamp(xc, x1, x2);
        int yi = clamp(yc, y1, y2);

        return sqrt((xi - xc) * (xi - xc) + (yi - yc) * (yi - yc)) <= r;
    }
};