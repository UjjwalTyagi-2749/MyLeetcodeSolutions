class trieNode{
    public :
    char data;
    trieNode*childern[26];
    bool isTerminal;
    int charactercount;

    trieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            childern[i]=NULL;
        }
        isTerminal=false;
        charactercount=0;
    }
};

class trie{
    public:
    trieNode *root;

    trie(){
        root=new trieNode('\0');
    }

    void insertutil(trieNode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }

        int index=word[0]-'a';
        trieNode*child;

        if(root->childern[index]!=nullptr){
            child=root->childern[index];
        }
        else{
            child =new trieNode(word[0]);
            root->charactercount++;
            root->childern[index]=child;
        }

        insertutil(child,word.substr(1));
    }

    void insertword(string word){
        insertutil(root,word);
    }

    void lcp(string s, string & ans){

    trieNode* curr = root;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(curr->isTerminal){
            break;
        }

        if(curr->charactercount == 1){
            ans.push_back(ch);
            int index=ch-'a';
            curr=curr->childern[index];
        }
        

        
        
    }

    }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       trie*t=new trie();

       for(int i=0;i<strs.size();i++){
        t->insertword(strs[i]);
       } 

       string ans="";
       t->lcp(strs[0],ans);
       return ans;

    }
};