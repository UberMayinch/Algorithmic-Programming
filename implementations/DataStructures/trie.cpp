struct trieNode {
    trieNode* arr[26];
    bool isEnd;

    trieNode() {
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
        isEnd = false;
    }
};

class Trie {
    trieNode* Head;
public:
    Trie() {
        Head = new trieNode();
    }

    void insert(string word) {
        trieNode* head = Head;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (head->arr[index] == NULL)
                head->arr[index] = new trieNode();
            head = head->arr[index];
        }
        head->isEnd = true;
    }

    bool search(string word) {
        trieNode* head = Head;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (head->arr[index] == NULL)
                return false;
            head = head->arr[index];
        }
        return head->isEnd;
    }

    bool startsWith(string prefix) {
        trieNode* head = Head;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (head->arr[index] == NULL)
                return false;
            head = head->arr[index];
        }
        return true;
    }
};
