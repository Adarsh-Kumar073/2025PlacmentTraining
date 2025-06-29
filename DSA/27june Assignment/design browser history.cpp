struct Node{
    string url;
    Node *prev, *next;

    Node(string data): url(data), prev(NULL), next(nullptr) {}
};

class BrowserHistory {
private:
    void deleteFwdUrls(Node* node){
        while(node){
            Node* next = node->next;
            delete node;
            node = next;
        }
    }

public:
    Node *curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* temp = curr->next;
        if(temp) temp->prev = nullptr;
        deleteFwdUrls(temp);

        Node* node = new Node(url);
        node->prev = curr;
        curr = curr->next = node;
    }
    
    string back(int steps) {
        while(curr->prev && steps--)
            curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next && steps--)
            curr = curr->next;
        return curr->url;
    }
};
