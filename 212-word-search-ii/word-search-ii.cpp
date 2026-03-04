class Solution {
public:
    vector<string> result;
    int m, n;

    struct trieNode {
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->word = "";

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void findTrieWords(vector<vector<char>>& board, int i, int j,
                       trieNode* root) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        char ch = board[i][j];
        int idx = ch - 'a';

        if (board[i][j] == '$' || root->children[idx] == NULL)
            return;

        root = root->children[idx];
        if (root->endOfWord == true) {
            result.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];
        board[i][j] = '$'; // mark to '$'

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            findTrieWords(board, new_i, new_j, root);
        }
        board[i][j] = temp; // unmark from '$'
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // create root
        trieNode* root = getNode();
        // insert word in trie
        for (string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                int idx = ch - 'a';

                if (root->children[idx] != NULL) {
                    findTrieWords(board, i, j, root);
                }
            }
        }
        return result;
    }
};