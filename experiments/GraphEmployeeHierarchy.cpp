#include<bits/stdc++.h>


/*
    Finding the common ancestor for the given elements of the graph
*/
using namespace std;


string lca(unordered_map<string, vector<string>> &g, const string &root, const string &a, const string &b) {
    if (root.empty() || root == a || root == b) return root;
    string r1, r2;
    for (const auto &c : g[root]) {
        auto r = lca(g, c, a, b);
        if (!r.empty()) {
            if (r1.empty()) {
                r1 = r;
            } else if (r2.empty()) {
                r2 = r;
                break;
            }
        }
    }
    if (!r1.empty() && !r2.empty()) return root;
    if (r1.empty()) return r2;
    if (r2.empty()) return r1;
    return "";
}

string solution1(const vector<vector<string>> &regions, const string &a, const string &b) {
    unordered_map<string, vector<string>> g;
    unordered_set<string> s;
    for (const auto &v : regions) {
        s.insert(v[0]);
    }
    for (const auto &v : regions) {
        g[v[0]] = vector<string>(begin(v) + 1, end(v));
        for (int i = 1; i < v.size(); ++i) {
            if (!g.count(v[i])) {
                g[v[i]] = {""};
            }
            s.erase(v[i]);
        }
    }
    return lca(g, *begin(s), a, b);
}

string solution2(const vector<vector<string>> &regions, const string &a, const string &b) {
    unordered_map<string, string> parent;
    for (const auto &v : regions) {
        if (!parent.count(v[0])) {
            parent[v[0]] = v[0];
        }
        for (int i = 1; i < v.size(); ++i) {
            parent[v[i]] = v[0];
        }
    }
    if (!parent.count(a) || !parent.count(b)) return "";
    unordered_set<string> sa;
    string x = a;
    while (x != parent[x]) {
        sa.insert(x);
        x = parent[x];
    }
    sa.insert(x);
    x = b;
    while (!sa.count(x) && x != parent[x]) {
        x = parent[x];
    }
    return x;
}

int main() {
    vector<vector<string>> regions = {{"Earth", "South America", "North America", "Asia", "Africa", "Pacific"},
                                      {"Asia", "China", "Korea", "Japan"},
                                      {"North America", "USA", "Canada"},
                                      {"South America", "Brazil", "Columbia"},
                                      {"Africa", "Algeria", "Lybia"},
                                      {"China", "Beijing", "Shanghai"},
                                      {"Japan", "Tokyo", "Kyoto"},
                                      {"Korea", "Seoul"}};
                                      
    vector<vector<string>> employee = {{"Scott", "Andrian", "Guo Li", "Susanthi Theng"},
                                      {"Guo Li", "Hari", "Shivaram Prasad", "Wei Liem", "Arun Kumar"},
                                      {"Susanthi Theng", "Lai Ti", "Sin Gee", "Rajesh", "Yingang Wang"},
                                      {"Sin Gee", "Dhoresh", "Leena", "Megha", "Gopal", "Venkata"},
                                      {"Andrian", "Neil", "Xiaotian", "", "Manju", "Lai Yee", "Malvin", "Imran", "Zhang yue", "Leong You"},
                                      {"Lai Yee", "Muk", "Kevin", "Puru", "Ginn chau"},
                                      {"Xiaotian", "Pavan", "Rahul sang", "Sathya", "Jianfeng Dong", "Trung"},
                                      {"Neil", "Ratikant", "Roshan", "Lew", "Amit"},
                                      {"Manju", "Kiran", "Deepak", "Rahul soni", "Grace"},
                                      {"Leong You", "Guangyang", "Choon Chwee", "Vengala", "Xia Zhang"}};
                                      
    cout<<solution2(regions, "Tokyo", "Kyoto")<<endl;
    cout<<solution1(regions, "Tokyo", "Kyoto")<<endl;
    cout<<solution2(regions, "Beijing", "Japan")<<endl;
    cout<<solution2(regions, "Seoul", "Africa")<<endl;
    
    cout << solution2(employee, "Kiran", "Puru");
    return 0;
}
