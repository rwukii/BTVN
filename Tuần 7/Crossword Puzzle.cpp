#include <bits/stdc++.h>

using namespace std;

int checkworddoc(int length, vector<vector<char>> a, int n) {
    bool flag = true;
    for(int i = 0; i < 10; i++) {
        if(a[n][i] == '-') {
            for(int j = i; j < length + i; j++) {
                if(a[n][j] != '-') {
                    flag = false;
                    break;
                }      
            }
            if(flag) return i;
        }
        flag = true;
    }
    return 0;
}

int checkwordngang(int length, vector<vector<char>> a, int n) {
    bool flag = true;
    for(int i = 0; i < 10; i++) {
        if(a[i][n] == '-') {
            for(int j = i; j < length + i; j++) {
                if(a[j][n] != '-') {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        flag = true;
    }
    return 0;
}

void gangiatridoc(vector<vector<char>> a, vector <int> doc1, vector <string> word, vector <int> doc, vector <vector<vector<char>>> &res, int m, int wordnum) {
        auto tmp = a;
        for(int i = 0; i < wordnum; i++) {
            if(doc[m] == word[i].length()) {
                int n = doc1[m];
                int pos = checkworddoc(doc[m], a, n);
                for(int h = pos; h <= pos + doc[m] - 1; h++) {
                a[n][h] = word[i][h - pos];
                }
            if(m == doc1.size() - 1) res.push_back(a);
            else {
                vector <string> word1 = word;
                word1.erase(word1.begin() + i);
                gangiatridoc(a, doc1, word1, doc, res, m + 1, wordnum - 1);
            }
        } else continue;
        a = tmp;
        }
    }

void gangiatringang(vector<vector<char>> a, vector <int> ngang1, vector <string> word, vector <int> ngang, vector <vector<vector<char>>> &res1, int m, int wordnum) {
        auto tmp = a;
        for(int i = 0; i < wordnum; i++) {
            if(ngang[m] == word[i].length()) {
                int n = ngang1[m];
                int pos = checkwordngang(ngang[m], a, n);
                for(int h = pos; h <= pos + ngang[m] - 1; h++) {
                a[h][n] = word[i][h - pos];
                }
                 if(m == ngang1.size() - 1) res1.push_back(a);
            else {
                vector <string> word1 = word;
                word1.erase(word1.begin() + i);
                gangiatringang(a, ngang1, word1, ngang, res1, m + 1, wordnum - 1);
            }
        } else continue;
        a = tmp;
    }    
}

bool check(vector<vector<char>> a, vector<vector<char>> b) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(isalpha(a[i][j]) && isalpha(b[i][j]) && a[i][j] != b[i][j]) return false; 
        }
    }
    return true;
}

vector<vector<char>> hopnhat(vector<vector<char>> a, vector<vector<char>> b) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
             if(isalpha(b[i][j])) {
                a[i][j] = b[i][j];
            }
        }
    }
    return a;
}
int main() {
    vector <vector<vector<char>>> res;
    vector <vector<vector<char>>> res1;
    vector<vector<char>> a(10, vector<char>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }
    vector <string> word;
    string words, tmp = "";
    cin >> words;
    for(int i = 0; i < words.length(); i++) {
        if(words[i] != ';') tmp += words[i];
        if(words[i] == ';' || i == words.length() - 1) {
            word.push_back(tmp);
            tmp.clear();
        }
    }
    int wordnum = word.size();
    vector <int> wlen;
    for(int i = 0; i < wordnum; i++) {
        wlen.push_back(word[i].length());
    }
    int lmin = *min_element(wlen.begin(), wlen.end());
    vector <int> doc, ngang, doc1, ngang1;
    int cnt_ = 0;
    for(int i = 0; i < 10; i++) {
        cnt_ = 0;
        for(int j = 0; j < 10; j++) {
            if((j < 9 && a[i][j] == '-' && a[i][j+1] == '-') || (j > 0 && a[i][j] == '-' && a[i][j-1] == '-')) cnt_++;
        }
        if(cnt_ >= lmin) {
            doc.push_back(cnt_);
            doc1.push_back(i);
        }
    }  
    for(int j = 0; j < 10; j++) {
        cnt_ = 0;
        for(int i = 0; i < 10; i++) {
            if((i < 9 && a[i][j] == '-' && a[i+1][j] == '-') || (i > 0 && a[i][j] == '-' && a[i-1][j] == '-')) cnt_++;
        }
        if(cnt_ >= lmin) {
            ngang.push_back(cnt_);
            ngang1.push_back(j);
        }
    }  
    
    gangiatringang(a, ngang1, word, ngang, res1, 0, wordnum);
    gangiatridoc(a, doc1, word, doc, res, 0, wordnum);
    for(auto x : res) {
        for(auto y : res1) {
            if(check(x, y)) {
                vector<vector<char>> result = hopnhat(x, y);
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        cout << result[i][j];
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
