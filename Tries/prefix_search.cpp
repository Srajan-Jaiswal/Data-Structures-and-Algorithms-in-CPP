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
