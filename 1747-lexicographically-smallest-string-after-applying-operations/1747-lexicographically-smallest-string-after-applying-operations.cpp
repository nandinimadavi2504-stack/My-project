class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        unordered_set<string> visited;
        queue<string> q;

        visited.insert(s);
        q.push(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Update answer if current string is lexicographically smaller
            if (curr < ans) ans = curr;

            // 1. Add operation on odd indices
            string added = curr;
            for (int i = 1; i < added.size(); i += 2) {
                int digit = (added[i] - '0' + a) % 10;
                added[i] = char(digit + '0');
            }
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            // 2. Rotate operation to the right by b
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};