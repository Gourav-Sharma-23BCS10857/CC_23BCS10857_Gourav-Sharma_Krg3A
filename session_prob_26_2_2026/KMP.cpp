void KMPSearch(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps = buildLPS(pat);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  
        } 
        else if (i < n && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];  
            } else {
                i++;
            }
        }
    }
}