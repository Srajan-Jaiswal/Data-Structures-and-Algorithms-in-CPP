void suggestions(string word)
{
    if(!prefixsearch(word))
        return;
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
    }
    auto it=(current->children).begin();
    if((current->children).size()==0)
    {
        cout<<word<<endl;
        return;
    }
    while(it!=(current->children).end())
    {
        recurse(it->first,word,it->second);
        it++;
    }
}
