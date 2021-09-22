#include<bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define mp make_pair

using namespace std;


void print_results() {
    ifstream cinf;
    cinf.open("output.txt");
    vector<vector<string>> ans(0);
    string t;
    while (getline(cinf, t)) {
        ans.pb({""});
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ' ') {
                ans.back().pb("");
            } else {
                ans.back().back().pb(t[i]);
            }
        }
    }
    cinf.close();
    int n = ans.size();
    cout << "Выберите параметр сортировки: ";
    int choice; cin >> choice;
    vector<pair<string, vector<string>>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = mp(ans[i][choice - 1], ans[i]);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        for (auto s1 : vec[i].sd) {
            cout << s1 << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> q(0);
    string t;
    int n = 0;
    ifstream cinf;
    cinf.open("questions.txt");
    while (getline(cinf, t)) {
        q.pb(t);
        n++;
    }
    cinf.close();
    vector<string> ans(n);
    int choice = 0;
    for (int i = 0; i < n; i++) {
        cout << q[i];
        if (i == 0) {
            cin >> choice;
            if (choice == 2) {
                print_results();
                return 0;
            } 
        } else {
            getline(cin, ans[i]);
        }
    }
    ofstream coutf;
    coutf.open("output.txt", ios::app);
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
}