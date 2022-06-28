int Solution::longestConsecutive(const vector<int> &A) {
    
    set<int> hashset;
    int n = A.size();
    
    for(auto x: A) {
        hashset.insert(x);
}

int long_streak = 0;

for(auto num: A) {
    if(!hashset.count(num-1)) {// here we check no. less than current no. is present or not
        int current_num = num;
        int current_streak = 1;
        
        
        while(hashset.count(current_num+1)) {
            current_num += 1;
            current_streak += 1;
        }
        long_streak = max(long_streak, current_streak);
    }
    
}
return long_streak;
    
}
