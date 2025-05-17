class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Rook move: same row or column
        if (a == e) {
            bool blocked = false;
            for (int i = min(b, f) + 1; i < max(b, f); i++) {
                if (c == a && d == i) {
                    blocked = true;
                    break;
                }
            }
            if (!blocked) return 1;
        }
        if (b == f) {
            bool blocked = false;
            for (int i = min(a, e) + 1; i < max(a, e); i++) {
                if (c == i && d == b) {
                    blocked = true;
                    break;
                }
            }
            if (!blocked) return 1;
        }

        // Bishop move: diagonal (|x1 - x2| == |y1 - y2|)
        if (abs(c - e) == abs(d - f)) {
            int dx = (e - c) > 0 ? 1 : -1;
            int dy = (f - d) > 0 ? 1 : -1;
            int x = c + dx;
            int y = d + dy;

            while (x != e && y != f) {
                if (x == a && y == b) {
                    return 2; // blocked by rook
                }
                x += dx;
                y += dy;
            }
            return 1;
        }

        // No piece can directly capture queen
        return 2;
    }
};
