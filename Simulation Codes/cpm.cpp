#include <bits/stdc++.h>
using namespace std;
struct Activity
{
    string name;
    int est,eet,lst,let,dur;
    vector<string> successors;
    vector<string> predecessors;
    Activity()
    {
        est = eet = lst = 0;
        let = INT_MAX;
        name = "";
    }
};
void fwd(const string& s, map<string, Activity*>& mp)
{
  //  cout<<s<<endl;
    auto ac = mp[s];
    ac->eet = ac->est + ac->dur;
    auto& successors = ac->successors;
    if(successors.size() == 0)
    {
        ac->let = ac->eet;
        ac->lst = ac->est;
    }
    for(auto& v:successors)
    {
      //  cout<<v<<endl;
        auto ptr = mp[v];
        if(ac->eet > ptr->est)
        {
            ptr->est = ac->eet;
            fwd(v, mp);
        }
    }
}
void bwd(const string& s, map<string, Activity*>& mp)
{
    auto ac = mp[s];
    ac->lst = ac->let - ac->dur;
    auto& predecessors = ac->predecessors;
    for(auto& v:predecessors)
    {
        auto ptr = mp[v];
        if(ptr->let > ac->lst)
        {
            ptr->let = ac->lst;
            bwd(v,mp);
        }

    }

}
void path(const string& s, map<string, Activity*>& mp)
{
    cout<<s<<"->";
    auto ac = mp[s];
    auto& successors = ac->successors;
    for(auto& v:successors)
    {
        auto ptr = mp[v];
        if(ptr->eet == ptr->let && ptr->est == ptr->lst)
        {
            path(v, mp);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    map<string, Activity*> mp;
    for(int i=1;i<=n;++i)
    {
        string name;
        cin>>name;
        int dur;
        cin>>dur;
        Activity* ac = NULL;

        if(mp.find(name) != mp.end())
        { 
            ac = mp[name];
        }
        else 
        {
            ac = new Activity();
            mp[name] = ac;
        }
        ac->name = name;
        ac->dur = dur;
        int x; //number of predecessors
        cin>>x;
        for(int j=0;j<x;++j)
        {
            string y;
            cin>>y;
            ac->predecessors.push_back(y);
            Activity* ptr = NULL;
            if(mp.find(y) != mp.end()) ptr = mp[y];
            else 
            {
                ptr = new Activity();
                ptr->name = y;
                mp[y] = ptr;
            }
            ptr->successors.push_back(name);
        }
    }
    string source,sink;
    for(auto pr:mp)
    {
        if(pr.second->successors.size() == 0) sink = pr.first;
        else if(pr.second->predecessors.size() == 0) source = pr.first;
    }


    fwd(source,mp);
    bwd(sink,mp);
    for(auto pr:mp)
    {
        cout<<pr.first<<" ";
        auto ptr = pr.second;
        cout<<ptr->est<<" "<<ptr->eet<<" "<<ptr->lst<<" "<<ptr->let<<endl;
    }
    cout<<"Criticial Path"<<endl;
    path(source,mp);

    
}

/* Input:
23
A 3 0 
B 4 1 A
C 2 1 A
E 5 1 A
G 3 1 A
H 7 3 C E G
J 8 2 H B
F 5 1 H
I 6 1 G
L 1 1 J
M 4 1 I
N 3 1 M
K 2 3 L F N
Z 4 1 L
P 11 1 O
O 2 1 K
Q 7 1 P
T 10 1 O
U 8 1 T
R 1 1 Q
S 2 2 R U
V 4 2 Z S
X 3 1 V
*/