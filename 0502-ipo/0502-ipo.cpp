#define N ((int)(1e5 * 2))

pair<int, int> tree[N];

class Solution {
    int n;
    vector<pair<int, int>> projects;
public:

    void build() {
        for (int i = n - 1; i > 0; i--) {
            if (tree[i * 2].first >= tree[i * 2 + 1].first) {
                tree[i].first = tree[i * 2].first;
                tree[i].second = tree[i * 2].second;
            } else {
                tree[i].first = tree[i * 2 + 1].first;
                tree[i].second = tree[i * 2 + 1].second;
            }
        }
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> ans = {0, -1};
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (tree[l].first >= ans.first) {
                    ans = tree[l];
                }
                l++;
            }
            if (!(r & 1)) {
                if (tree[r].first >= ans.first) {
                    ans = tree[r];
                }
                r--;
            }
        }
        return ans;
    }

    void update(int i, int val) {
        i += n;
        tree[i].first = val;
        for (i >>= 1; i > 0; i >>= 1) {
            if (tree[i * 2].first >= tree[i * 2 + 1].first) {
                tree[i].first = tree[i * 2].first;
                tree[i].second = tree[i * 2].second;
            } else {
                tree[i].first = tree[i * 2 + 1].first;
                tree[i].second = tree[i * 2 + 1].second;
            }
        }
    }

    int binarySearch(int l, int r, int val) {
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (projects[mid].second <= val) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        projects.clear();
        n = profits.size();

        for (int i = 0; i < n; i++) {
            projects.push_back({profits[i], capital[i]});
        }
        
        sort(projects.begin(), projects.end(), [](pair<int, int> &a, pair<int, int> &b){
            if (a.second < b.second) return true;
            if (a.second == b.second) return a.first > b.first;
            return false;
        });

        for (int i = 0; i < n; i++) {
            tree[n + i].first = projects[i].first;
            tree[n + i].second = i;
        }

        build();

        for (int i = 0; i < k; i++) {
            int affordableProjectIdx = binarySearch(0, n - 1, w);
            pair<int, int> maxElement = query(0, affordableProjectIdx);
            w += maxElement.first;
            update(maxElement.second, 0);
        }

        return w;
    }
};