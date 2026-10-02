class Solution {

    // Helper function jo recursive backtracking ka use karke parenthesis generate karega
    private void parenth(int n, int left, int right, List<String> ans, StringBuilder temp) {
        
        // Base case: Jab left aur right brackets ka sum 2*n ke barabar ho jaye
        // Matlab ek valid string poori ban chuki hai
        if (left + right == 2 * n) {
            ans.add(temp.toString()); // StringBuilder ko String mein badal kar list mein add karo
            return;
        }

        // Left parenthesis add karne ki condition: jab tak left bracket 'n' se kam ho
        if (left < n) {
            temp.append('('); // String ke end mein '(' daalo
            parenth(n, left + 1, right, ans, temp); // Agla bracket check karne ke liye recursive call
            temp.deleteCharAt(temp.length() - 1); // Backtracking: last character hatao taaki doosra path check ho sake
        }

        // Right parenthesis add karne ki condition: jab right brackets count left se kam ho
        if (right < left) {
            temp.append(')'); // String ke end mein ')' daalo
            parenth(n, left, right + 1, ans, temp); // Recursive call right count badha kar
            temp.deleteCharAt(temp.length() - 1); // Backtracking: last character hatao
        }
    }

    // Main function jo LeetCode call karega
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>(); // Saare answers store karne ke liye list
        StringBuilder temp = new StringBuilder(); // String dynamically modify karne ke liye StringBuilder
        
        parenth(n, 0, 0, ans, temp); // Helper function ko initial values (0, 0) ke sath call kiya
        
        return ans; // Final list return kar di
    }
}
