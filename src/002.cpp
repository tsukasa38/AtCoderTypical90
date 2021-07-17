#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> parentheses;

    for(int bit = 0; bit < (1 << N); ++bit) {
        int count = 0;
        bool is_correct_parentheses = true;

        for(int i = 0; i < N; ++i) {
            if(bit & (1 << i)) { ++count; }
            if(!(bit & (1 << i))) { --count; }
            if(count < 0) { is_correct_parentheses = false; }
        }

        if(count != 0) { is_correct_parentheses = false; }

        if(is_correct_parentheses) {
            string str = "";

            for(int i = 0; i < N; ++i) {
                if(bit & (1 << i)) { str += "("; }
                if(!(bit & (1 << i))) { str += ")"; }
            }

            parentheses.push_back(str);
        }
    }

    sort(parentheses.begin(), parentheses.end());

    for(string str: parentheses) { cout << str << endl; }

    return 0;
}
