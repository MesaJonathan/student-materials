// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {

template <typename T>

class LinkedList{
    private: 
        struct Node{
            T data;
            Node* prev;
            Node* next;

            Node(T data, Node* prev, Node* next){
                this->data = data;
                this->prev = prev;
                this->next = next;
            }
        };

        Node* head;
        Node* tail;

    public:
        class Iterator{
            private:
                Node* curr;

            public:
                Iterator(Node* node){
                    curr = node;
                }

                T operator*() const{
                    return *curr.data;
                }

                Iterator& operator++(){
                    curr = curr->next;
                    return this;
                }

                bool operator== (Iterator const& rhs){
                    if(curr == rhs.curr){
                        return true;
                    }else{
                        return false;
                    }
                }

                bool operator!=(Iterator const& rhs){
                    if(curr != rhs.curr){
                        return true;
                    }else{
                        return false;
                    }
                }
        };

        LinkedList<T>(){
            head = nullptr;
            tail = nullptr;
        }

        Iterator begin() const{
            return Iterator(head);
        }

        Iterator end() const{
            return Iterator(tail->next);
        }

        bool isEmpty() const{
            if (head == nullptr){
                return true;
            }else{
                return false;
            }
        }

        T getFront() const{
            return head;
        }

        T getBack() const{
            return tail;
        }

        void enqueue(T element){
            //empty case
            if(head == nullptr && tail == nullptr){
                Node newNode = new Node(element, nullptr, nullptr);
                head = &newNode;
                tail = &newNode;
            }else{  //non-empty case
                // create new node with current tail as its prev val and nullptr as its next val
                Node newNode = new Node(element, tail, nullptr);

                //set new node as current tail's next
                tail->next = &newNode;

                //make new node the new tail 
                tail = &newNode;
            }
        }

        void dequeue(){
            Node* newHead = head->next;
            newHead->prev = nullptr;

            // delete the node stored in head
            delete head;
            
            head = newHead;
        }

        void pop(){
            Node* temp = tail;
            Node* newTail = tail->prev;
            newTail->next = nullptr;

            // delete the node stored in tail
            delete tail;
            
            tail = newTail;
        }

        void clear(){
            Node* it = head;
            while (it != nullptr){
                Node* n =  it->next;
                
                // here add the code that deletes the node it points too
                delete it;

                it = n;
            }
        }

        bool contains(T element) const{
            bool result = false;

            Node* it = head;
            while (it != nullptr){
                if (it->data == element){
                    result = true;
                    break;
                }
            }

            return result;
        }

        void remove(T element){
            Node* it = head;
            while (it != nullptr){
                if (it->data == element){
                    //here add the code to delete it
                    delete it;
                }
            }
        }
};

} }  // namespace ufl_cap4053::fundamentals
