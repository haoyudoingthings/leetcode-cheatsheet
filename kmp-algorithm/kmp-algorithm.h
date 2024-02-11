namespace N {
    std::vector<int> kmp_search(std::string& pat, std::string& txt) {
        std::vector<int> inds;
        int M = pat.size();
        int N = txt.size();

        std::vector<int> lps(M, 0);
        int j = 0;
        compute_lps_array(pat, M, lps);

        int i = 0;
        while (N - i >= M - j) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M) {
                inds.push_back(i-j);
                j = lps[j-1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        return inds;
    }
    void compute_lps_array(std::string& pat, int& M, std::vector<int>& lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
}