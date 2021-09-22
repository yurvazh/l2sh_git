#include<bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define mp make_pair

using namespace std;

void change_file(){
    int a;
    cout << "Are you sure about changing the file?\n1 - yes, 0 - no.\n";
    cin >> a;
    if (a == 0)
        return;
    ofstream outf("questions.txt", ios::app);
    string s;
    cin >> s;
    outf << s << endl;
}

void print_results() {
    freopen("output.txt", "r", stdin);
    string fN, lN, book;
    vector<pair<pair<string, string>, string> > vec(0);
    set<string> books;
    int in;
    cin >> in;
    if (in == 1) {
        while (cin >> fN >> lN >> book) {
            vec.pb(mp(mp(fN, lN), book));
            books.insert(book);
        }
        sort(vec.begin(), vec.end());
        for (auto t : vec) {
            cout << t.ft.ft << " " << t.ft.sd << ": " << t.sd << endl;
        }
    } else if (in == 2) {
        while (cin >> fN >> lN >> book) {
            vec.pb(mp(mp(lN, fN), book));
            books.insert(book);
        }
        sort(vec.begin(), vec.end());
        for (auto t : vec) {
            cout << t.ft.sd << " " << t.ft.ft << ": " << t.sd << endl;
        }
    } else {
        while (cin >> fN >> lN >> book) {
            vec.pb(mp(mp(book, fN), lN));
            books.insert(book);
        }
        sort(vec.begin(), vec.end());
        for (auto t : vec) {
            cout << t.ft.sd << " " << t.sd << ": " << t.ft.ft << endl;
        }
    }
    cout << vec.size() << " " << books.size() << endl;
}

int main() {
    freopen("questions.txt", "r", stdin);
    string q1, q2, q3, q4;
    getline(cin, q1);
    getline(cin, q2);
    getline(cin, q3);
    getline(cin, q4);
    string fN, lN, book;
    cout << q1 << " ";
    int choice;
    cin >> choice;
    if (choice == 2) {
        print_results();
        return 0;
    } else if (choice == 3){
        change_file();
        return 0;
    }
    cout << endl << q2 << " ";
    cin >> fN;
    cout << endl << q3 << " ";
    cin >> lN;
    cout << endl << q4 << " ";
    cin >> book;
    freopen("output.txt", "w", stdout);
    cout << endl << fN << endl << lN << endl << book << endl;
}
