class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int left=0,right=0,len=0;
        Map<Character,Integer>mp=new HashMap<>();

        for(right=0;right<s.length();right++){
            while(mp.containsKey(s.charAt(right)) && left<right){
                char ch=s.charAt(left);
                mp.put(ch,mp.get(ch)-1);
                if(mp.get(ch)==0){
                    mp.remove(ch);
                }
                left++;
            }
            mp.put(s.charAt(right),mp.getOrDefault(s.charAt(right),0)+1);
            len=Math.max(len,right-left+1);
        }
         return len;

    }
}