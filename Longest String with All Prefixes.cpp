class Solution {
public:

    class TrieNode{
        public:

        char data;
        TrieNode* children[26];
        int childcount;
        bool isTerminal;

        TrieNode(char ch)
        {
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
            isTerminal=false;
            childcount=0;
        }
    };
    class Trie{
        public:
        
        TrieNode* root;
        Trie(char ch)
        {
            root=new TrieNode(ch);
        }
    
    void insertutil(string word,TrieNode* root)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
           
            root->childcount++;
            root->children[index]=child;
        }
        insertutil(word.substr(1),child);
    }
    void insert(string word)
    {
        insertutil(word,root);
    }
    
    void lps(string &ans,string &first)
    {
        for(int i=0;i<first.length();i++)
        {
            char ch=first[i];

            if(root->childcount==1)
            {
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
        
    }
 };
    string longestCommonPrefix(vector<string>& strs) {
       int n =strs.size();
        string ans=""; 
        Trie *t=new Trie('\0');
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i] == "")
                return "";
            t->insert(strs[i]);
        }
        string first=strs[0];
        t->lps(ans,first);
        return ans;
    }
};