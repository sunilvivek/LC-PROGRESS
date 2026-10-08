
class MyHashSet {
public:
    bool hash[1000001];

    MyHashSet() {
        for (int i = 0; i <= 1000000; i++) {
            hash[i] = false;
        }
    }

    void add(int key) {
        hash[key] = true;
    }

    void remove(int key) {
        hash[key] = false;
    }

    bool contains(int key) {
        return hash[key];
    }
};
