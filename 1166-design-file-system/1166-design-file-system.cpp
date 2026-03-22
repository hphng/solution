class FileSystem {
public:
    unordered_map<string, int> mp;
    FileSystem() {
        mp[""] = -1;
    }
    
    bool createPath(string path, int value) {
        if(path.empty() || path == "/" || mp.find(path) != mp.end()){
            return false;
        }
        int lastIndex = 0;
        for(int i = path.length() - 1; i >= 0;i--){
            if(path[i] == '/'){
                lastIndex = i;
                break;
            }
        }

        string parent = path.substr(0, lastIndex);
        if(mp.find(parent) == mp.end()){
            return false;
        }

        mp[path] = value;
        return true;
    }
    
    int get(string path) {
        if(mp.find(path) == mp.end()){
            return -1;
        }

        return mp[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */