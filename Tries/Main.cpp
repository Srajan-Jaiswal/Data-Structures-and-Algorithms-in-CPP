#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, n) for (int i = a; i < n; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define case cout << "Case " << t++ << ": ";
class TrieNode{
    map<char,TrieNode*> children;
    bool endofword;
    TrieNode(){
        endofword=false;
    }
};
TrieNode *root=new TrieNode();
void insert(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node){
            node=new TrieNode();
            current->children[ch]=node;
        }
        current=node;
    }
    current->endofword=true;
}
bool prefixsearch(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return true;
}
bool wordsearch(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node){
            return false;
        }
        current=node;
    }
    return current->endofword;
}
void deletion(string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    current->endofword=false;
}
void recurse(char last_letter,string last_word,TrieNode *node){
    TrieNode *current=node;
    auto it=(current->children).begin();
    if(current->endofword==true)
        cout<<last_word+last_letter<<endl;
    while(it!=(current->children).end()){
        recurse(it->first,last_word+last_letter,it->second);
        it++;
    }
}
void suggestions(string word){
    if(!prefixsearch(word))
        return;
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    auto it=(current->children).begin();
    if((current->children).size()==0){
        cout<<word<<endl;
        return;
    }
    while(it!=(current->children).end()){
        recurse(it->first,word,it->second);
        it++;
    }
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
	int ma=0;
    string d;
    for(int i=0;i<100000;i++){
        string s;
        cin>>s;
        insert(s);
        int x=s.size();
        if(x>ma){
            ma=x;
            d=s;
        }
    }
    suggestions("you");
	}
}
