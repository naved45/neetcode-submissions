class MyHashSet {
private:
    static const int SIZE = 1000; // number of buckets
    vector<list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int idx = hash(key);
        for (int val : buckets[idx]) {
            if (val == key) return; // already exists
        }
        buckets[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove(key);
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int val : buckets[idx]) {
            if (val == key) return true;
        }
        return false;
    }
};
