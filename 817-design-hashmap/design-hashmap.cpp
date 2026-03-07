class MyHashMap {
    
private:
    static const int size = 1000;
    vector<list<pair<int,int>>> table;

public:
    
    MyHashMap() {
        table.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }

    void put(int key, int value) {
        
        int index = hash(key);

        for(auto &p : table[index]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }

        table[index].push_back({key,value});
    }
    
    int get(int key) {
        
        int index = hash(key);

        for(auto &p : table[index]) {
            if(p.first == key)
                return p.second;
        }

        return -1;
    }
    
    void remove(int key) {

        int index = hash(key);

        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};