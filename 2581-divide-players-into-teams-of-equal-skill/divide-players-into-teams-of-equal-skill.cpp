class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long sum=0,i=0,j=skill.size()-1;
        set<int>s;
        while(i<j){
           sum+=skill[i]*skill[j];
           s.insert(skill[i]+skill[j]);
           cout<<sum<<' ';
           i++;
           j--;
        }
        
        if(s.size()==1) return sum;
        return -1;
    }
};