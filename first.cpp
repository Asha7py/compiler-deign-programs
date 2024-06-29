#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void calcFirst(const string& nt, const unordered_map<string, vector<string>>& gram,
               unordered_map<string, unordered_set<char>>& first) {
    if (first.find(nt) != first.end()) {
         return;
    }

    for (const string& prod : gram.at(nt)) {
        char sym = prod[0];
        if (isupper(sym)) {
            calcFirst(string(1, sym), gram, first);
            for (char ch : first[string(1, sym)]) {
                first[nt].insert(ch);
            }
        } else {
            first[nt].insert(sym);
        }
    }
}

int main() {
   unordered_map<string, vector<string>> gram = {
        {"S", {"AB", "BC"}},
        {"A", {"a", "aA"}},
        {"B", {"b", "bB"}},
        {"C", {"c"}}
    };
 unordered_map<string, unordered_set<char>> first;

    
    for (const auto& nt : gram) {
        calcFirst(nt.first, gram, first);
    }

   
    cout << "First Sets:" << endl;
    for (const auto& entry : first) {
        cout << entry.first << ": { ";
        for (char ch : entry.second) {
            cout << ch << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

