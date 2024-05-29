#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateStrings(const vector<char>& characters, int length, string currentString = "") {
    if (length == 0) {
        cout << currentString << endl;
        return;
    }
 
    for (char c : characters) {
        string newString = currentString + c;
        generateStrings(characters, length - 1, newString);
    }
}

int main() {
    vector<char> characters = {'a', 'b', 'c', 'd'};
    int length = 3;
    
    generateStrings(characters, length);

    return 0;
}
