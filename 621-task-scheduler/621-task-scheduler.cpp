class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> taskcount(26);
        for(int i=0;i<tasks.size();i++){
            taskcount[tasks[i]-'A']++;
        }
        
        sort(taskcount.begin(),taskcount.end());
        int f_max=taskcount[25];
        int idle=(f_max-1)*n;
        for(int i=taskcount.size()-2;i>=0&& idle>0;i--){
            idle-=min(f_max-1,taskcount[i]);
        }
        
        idle=max(0,idle);
        return idle+tasks.size();
        
    }
};