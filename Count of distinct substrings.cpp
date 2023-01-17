// unordered_map<string,int> mp;

//  void sub(string s,unordered_map<string,int> &mp)
//  {
//      string ans="";
//      for(int j=0;j<s.length();j++)
//      {
//          ans+=s[j];
//          mp[ans]++;
//      }
//  }
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int cnt;
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
         cnt=0;
    }
};
 class Trie{
     public:
     TrieNode* root;
     int cnt;
     Trie(char ch)
     {
         root=new TrieNode(ch);
         cnt=0;
     }
     void insertUtil(string s,TrieNode* root,int &cnt)
     {
         if(s.length()==0)
         {
             return;
         }
         int index=s[0]-'a';
         TrieNode* child;
         if(root->children[index]!=NULL)
         {
             child=root->children[index];
         }
         else
         {
             child=new TrieNode(s[0]);
             root->children[index]=child;
             cnt++;
         }
         insertUtil(s.substr(1),child,cnt);
     }
     void insert(string s,int &cnt)
     {
         insertUtil(s,root,cnt);
     }
    //  int count(int cnt,string)
 };
int countDistinctSubstring(string s)
{
    Trie *t=new Trie('\0');
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        t->insert(s.substr(i),cnt);
    }
    return cnt+1;
    // unordered_map<string,int> mp;
    // for(int i=0;i<s.length();i++)
    // {
    //     sub(s.substr(i),mp);
    // }
    // return mp.size()+1;
}