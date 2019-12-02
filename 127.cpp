class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int M = beginWord.size();
        
        // Map intermediate words to their adjudicate words (e.g. d*g -> [dog, dig])
        unordered_map<string, unordered_set<string>> mid = {};
        for (string word : wordList)
            for (int i = 0; i < M; ++i) {
                string generic = word;
                generic[i] = '*';
                mid[generic].insert(word);
            }
        
        // BFS on graph
        unordered_set<string> visited = {};
        queue<string> q;
        q.push(beginWord);
        int pathLen = 0;
        while (!q.empty()) {
            ++pathLen;
            for (int i = q.size(); i > 0; --i) {
                string word = q.front(); q.pop();
                if (word.compare(endWord) == 0) return pathLen;
                visited.insert(word);

                for (int i = 0; i < M; ++i) {
                    string generic = word;
                    generic[i] = '*';
                    for (string g: mid[generic])
                        if (visited.find(g) == visited.end())
                            q.push(g);
                }
            }
        }
        return 0;
    }
};
