class Solution {
public:
    long long solve(long long t, vector<int> &time) {
        long long trips = 0;
        for(int i = 0; i < time.size(); i++) {
            trips += (t/time[i]*1LL);
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, h = 1e14, res = 0;
        while(l <= h) {
            long long m = l + (h-l)/2;
            if(solve(m, time) >= totalTrips) {
                res = m;
                h = m-1;
            }
            else l = m+1;
        }
        return res;
    }
};