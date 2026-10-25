class BrowserHistory {
public:
    struct Node {
        string data;
        Node* next;
        Node* prev;

        Node(string s) {
            data = s;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* curr;

    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }

    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }

    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }

        return curr->data;
    }

    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }

        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */