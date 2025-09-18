template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node) {
    header->next  = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node) {
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    // TO DO: Implement the code for the append

   
    Node* last_node = trailer -> prev;
    Node* a = new Node();
    a-> value = elem;
    a-> next =  trailer;
    last_node -> next = a;
    trailer -> prev = a;
    a -> prev = last_node; 

    this->length++;



    // new Node* elem = last -> prev;

    // last_node= trailer;




}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* a = nullptr; header->next != trailer; ) {
        a = header->next->next;
        delete header->next;
        header->next = a;
    }

    trailer->prev = header;
    this->length  = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length   = copyObj.length;
    Node* myCurr   = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n      = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev      = myCurr;
        myCurr       = n;
        copyCurr     = copyCurr->next;
    }

    myCurr->next  = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    // TO DO: Implement code for getElement at position
    // Node* myCurr = header;
    // count = 0;
    // answer = 0;
    // if(position == count){
    //     return(myCurr(elem));
    // }

    if(position < 0 || position >= this->length) {
        throw out_of_range("Out of bounds, getElment");
    }

    Node* a = header->next;
    for(int i = 0; i < position; i++){
        a = a->next;
    }
    return a->value;


}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
  // TO DO: Implement code to insert an element to list

  if(position < 0 || position > this->length) {
        throw out_of_range("insert ran into Out of bounds");
    }

    Node* a = header;
    for(int i = 0; i < position; i++){
        a = a->next;
    }
   
    Node* n = new Node(elem, a->next, a);
    a->next->prev=n;
    a->next = n;

    this->length++;
}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length  == 0
        && header->next  == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {


    if(position < 0 || position >= this->length) {
        throw out_of_range("Out of bounds in remove");
    }
    
    Node* a = header->next;
    for(int i = 0; i < position; i++){
        a =a->next;
    }
    a->prev->next = a->next; 
    a->next->prev = a->prev;
    this->length--;

    
    delete a;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    // TO DO: Implement code to search for element

    Node* a = header->next;
    while(a != trailer){
        if(a->value == elem){
            return true;
        }
        a = a->next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    // TO DO: Add code for replace method
    if(position < 0 || position >= this->length) {
        throw out_of_range("Out of bounds in replace");
    }
    Node* a = header->next;
    for(int i = 0; i < position; i++){
        a = a->next;
    }
    a->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* a = myObj.header->next;
        while (a != myObj.trailer) {
            outStream << a->value;
            if (a->next != myObj.trailer) {
                outStream << " <--> ";
            }
            a = a->next;
        }
        outStream << endl;
    }

    return outStream;
}
