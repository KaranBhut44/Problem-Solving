class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        int n = words.size();
        string prev = words[0];
        unordered_map<char,vector<char>>m;
        unordered_map<char,int> char_indegree;
        for(auto word:words)
        {
            for(auto chr:word)
                char_indegree[chr] = 0;
        }
        for(int i=1;i<n;i++)
        {
            string current = words[i];
            int a = prev.size();
            int b = current.size();
            int temp = 0;
            while(temp != min(a,b))
            {
                if(prev[temp] == current[temp])
                    temp++;
                else
                {
                    m[prev[temp]].push_back(current[temp]);
                    break;
                }
            }
            if(temp == min(a,b) && a>b)
                return "";
            prev = current;
        }

        for(auto dep:m)
        {
            for(auto chr:dep.second)
                char_indegree[chr]++;
        }

        queue<char>q;
        string ans;
        int total_char = char_indegree.size();
        
        for(auto chr:char_indegree)
        {
            if(chr.second == 0)
            {
                q.push(chr.first);
            }
        }
        
        int count = 0;
        while(!q.empty())
        {
            set<char>s;
            while(!q.empty())
            {
                s.insert(q.front());
                q.pop();
            }
            for(auto i:s)
                q.push(i);
            char curr = q.front();
            q.pop();
            count++;
            ans += curr;
            vector<char>temp;
            for(auto chr:m[curr])
            {
                char_indegree[chr]--;
                if(char_indegree[chr] == 0)
                {
                    q.push(chr);
                }
            }
        }
        if(count != total_char)
            return "";
        return ans;
        
    }
};
