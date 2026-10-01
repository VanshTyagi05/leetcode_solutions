class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                if (st.isEmpty())
                    return false;

                // 4. Fixed: Java Stack uses peek(), not top()
                if (c == ']' && st.peek() == '[')
                    st.pop();
                else if (c == ')' && st.peek() == '(')
                    st.pop();
                else if (c == '}' && st.peek() == '{')
                    st.pop();
                else
                    return false; // Mismatched closing bracket (e.g., '(]')
            }
        }
        return st.size() == 0 ? true : false;
    }
}