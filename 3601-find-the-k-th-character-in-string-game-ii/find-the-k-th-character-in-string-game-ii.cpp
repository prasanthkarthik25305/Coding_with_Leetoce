class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
      if(k==1) return 'a';
      int base=__lg(k);
      if(k==(1L<<base)) base--;
      k-=(1L<<base);
      return (((kthCharacter(k,operations)-'a')+operations[base])%26+'a');
    }
};