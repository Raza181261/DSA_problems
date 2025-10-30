class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        unordered_set<string> points;

        for (auto &rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            area += (long long)(x2 - x1) * (y2 - y1);

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            string corners[4] = {to_string(x1)+" "+to_string(y1),
                                 to_string(x1)+" "+to_string(y2),
                                 to_string(x2)+" "+to_string(y1),
                                 to_string(x2)+" "+to_string(y2)};
            for (auto &c : corners) {
                if (points.count(c)) points.erase(c);
                else points.insert(c);
            }
        }

        if (area != (long long)(maxX - minX) * (maxY - minY)) return false;
        if (points.size() != 4) return false;

        string corners[4] = {to_string(minX)+" "+to_string(minY),
                             to_string(minX)+" "+to_string(maxY),
                             to_string(maxX)+" "+to_string(minY),
                             to_string(maxX)+" "+to_string(maxY)};
        for (auto &c : corners)
            if (!points.count(c)) return false;

        return true;
    }
};
