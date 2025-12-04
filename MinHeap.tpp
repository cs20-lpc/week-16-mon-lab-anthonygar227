template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0) {
        if (data[parent(i)] > data[i]) {
            swap(data[i], data[parent(i)]);
            i = parent(i);
        } else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int n = size();

    while(true) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < n) {
            if (data[l] < data[smallest]) {
                smallest = l;
            }
        }

        if (r < n) {
            if (data[r] < data[smallest]) {
                smallest = r;
            }
        }

        if (smallest == i) {
            break;
        }

        swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);

    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    if (empty()) {
        throw runtime_error("Heap is empty");
    }

    rootValue = data[0];
    data[0] = data.back();
    data.pop_back();

    if (!empty()) {
        siftDown(0);
    }

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    if (index < size()) {
        siftUp(index);
        siftDown(index);
    }
}
