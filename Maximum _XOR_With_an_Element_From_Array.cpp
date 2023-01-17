// Maximum XOR With an Element From Array

class TrieNode{
    public:
    
    TrieNode* children[2];
    
    TrieNode()
    {
        this->children[0]=NULL;
        this->children[1]=NULL;
        
    }
};
class Solution {
public:
    TrieNode* root;

    void insert(int n)
    {
        TrieNode* t=root;
        bitset<32> bs(n);
        for(int i=31;i>=0;i--)
        {
            if(!t->children[bs[i]])
            {
                t->children[bs[i]]=new TrieNode();
            }
            t=t->children[bs[i]];
        }
    }
    int maxXOR(int n){
        TrieNode *t = root;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(t->children[!bs[j]])
            { ans += (1<<j);
            t = t->children[!bs[j]]; 
            }
            else 
            {
                t = t->children[bs[j]];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),-1);
        int mx=-1;
        root=new TrieNode();
        vector<pair<pair<int,int>,int>> q;
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({{queries[i][0],queries[i][1]},i});
        }
        sort(q.begin(),q.end(),[](pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b)
        {
            return a.first.second<b.first.second;
        });
        sort(a.begin(),a.end());
        int idx=0;
        for(int i=0;i<q.size();i++)
        {
            int comp=q[i].first.first;
            int limt=q[i].first.second;
            int ptr=q[i].second;
            while(idx<a.size() && a[idx]<=limt)
            {
                insert(a[idx++]);

            }
            if(idx>0)
            {
                ans[ptr]=maxXOR(comp);
            }
        }
        return ans;
    }
};