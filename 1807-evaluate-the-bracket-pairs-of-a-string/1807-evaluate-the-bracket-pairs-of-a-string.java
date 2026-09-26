class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        HashMap<String, String> mp = new HashMap<>();

        for (int i = 0; i < knowledge.size(); i++) {
            mp.put(knowledge.get(i).get(0), knowledge.get(i).get(1));
        }
        int i = 0; // iterator on main string
        int size = s.length();
        StringBuilder ans = new StringBuilder();
        while (i < size) {
            if (s.charAt(i) == '(') {
                // go till ')' and add it into ans
                int start = i + 1;
                while (s.charAt(i) != ')') {
                    i++;
                }
                String key = s.substring(start, i);
                ans.append(mp.getOrDefault(key, "?"));
                i++;
            } else {
                ans.append(s.charAt(i));
                i++;
            }

        }
        return ans.toString();
    }
}