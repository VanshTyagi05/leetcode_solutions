class Solution {
    public String lexPalindromicPermutation(String s, String target) {

        int n = s.length();

        // Frequency count
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // ---------------------------------------------------------
        // Palindrome possible hai ya nahi?
        // At most 1 odd frequency allowed.
        // ---------------------------------------------------------
        int odd = 0;
        int middle = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                middle = i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Half frequency
        int[] halfFreq = new int[26];

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        int halfLen = n / 2;

        String answer = null;

        // =========================================================
        // PART 1:
        // Try making first half exactly equal to target's first half.
        //
        // Example:
        // target = "abb..."
        // first half = "ab"
        // =========================================================

        int[] remaining = halfFreq.clone();
        StringBuilder equalHalf = new StringBuilder();

        boolean possible = true;

        for (int i = 0; i < halfLen; i++) {

            int c = target.charAt(i) - 'a';

            if (remaining[c] == 0) {
                possible = false;
                break;
            }

            equalHalf.append((char) ('a' + c));
            remaining[c]--;
        }

        if (possible) {

            String candidate = makePalindrome(
                equalHalf.toString(),
                middle,
                n
            );

            // Equal half hone ke baad bhi complete palindrome
            // target se greater ho sakta hai.
            if (candidate.compareTo(target) > 0) {
                answer = candidate;
            }
        }

        // =========================================================
        // PART 2:
        //
        // Har position ko first "greater" position maan kar try karo.
        //
        // Prefix = target ke equal
        // Current char = target char se smallest greater char
        // Remaining = sorted smallest
        // =========================================================

        for (int changePos = 0; changePos < halfLen; changePos++) {

            remaining = halfFreq.clone();

            StringBuilder firstHalf = new StringBuilder();

            possible = true;

            // -----------------------------------------------------
            // Prefix ko target ke equal rakho
            // -----------------------------------------------------
            for (int i = 0; i < changePos; i++) {

                int c = target.charAt(i) - 'a';

                if (remaining[c] == 0) {
                    possible = false;
                    break;
                }

                firstHalf.append((char) ('a' + c));
                remaining[c]--;
            }

            if (!possible) {
                continue;
            }

            // -----------------------------------------------------
            // Current position par target se bada smallest character
            // -----------------------------------------------------
            int targetChar = target.charAt(changePos) - 'a';

            int bigger = -1;

            for (int c = targetChar + 1; c < 26; c++) {

                if (remaining[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1) {
                continue;
            }

            firstHalf.append((char) ('a' + bigger));
            remaining[bigger]--;

            // -----------------------------------------------------
            // Baaki characters ko smallest order mein rakho
            // -----------------------------------------------------
            for (int c = 0; c < 26; c++) {

                while (remaining[c] > 0) {
                    firstHalf.append((char) ('a' + c));
                    remaining[c]--;
                }
            }

            // Complete palindrome
            String candidate = makePalindrome(
                firstHalf.toString(),
                middle,
                n
            );

            // Candidate valid hai?
            if (candidate.compareTo(target) > 0) {

                if (answer == null ||
                    candidate.compareTo(answer) < 0) {

                    answer = candidate;
                }
            }
        }

        return answer == null ? "" : answer;
    }


    // =============================================================
    // Helper function:
    // First half mil gaya -> complete palindrome banao
    // =============================================================
    private String makePalindrome(String firstHalf, int middle, int n) {

        StringBuilder result = new StringBuilder();

        // Left half
        result.append(firstHalf);

        // Odd length mein middle character
        if (n % 2 == 1) {
            result.append((char) ('a' + middle));
        }

        // Right half = reverse(left half)
        for (int i = firstHalf.length() - 1; i >= 0; i--) {
            result.append(firstHalf.charAt(i));
        }

        return result.toString();
    }
}

