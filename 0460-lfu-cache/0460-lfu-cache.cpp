class LFUCache {
public:
    int capacity, minFreq=0;
    unordered_map<int,pair<int,int>> keyMap;
    unordered_map<int,list<int>> freqMap;
    unordered_map<int,list<int>::iterator> posMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!keyMap.count(key))return -1;
        freqMap[keyMap[key].second].erase(posMap[key]);
        keyMap[key].second++;
        freqMap[keyMap[key].second].push_back(key);
        posMap[key] = --freqMap[keyMap[key].second].end();
        if(freqMap[minFreq].empty())minFreq++;
        return keyMap[key].first;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyMap.count(key)){
            keyMap[key].first = value;
            get(key);
        }else {
            if(keyMap.size() == capacity){
                int oldkey = freqMap[minFreq].front();
                freqMap[minFreq].pop_front();
                keyMap.erase(oldkey);
                posMap.erase(oldkey);
            }
            keyMap[key] = pair{value, 1};
            freqMap[1].push_back(key);
            posMap[key] = --freqMap[1].end();
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */