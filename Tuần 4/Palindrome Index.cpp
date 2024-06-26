#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int palindromeIndex(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            if (s[i + 1] == s[j] && s[i + 2] == s[j - 1]) return i;
            if (s[i] == s[j - 1] && s[i + 1] == s[j - 2]) return j;
            return -1;
        }
        i++;
        j--;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
