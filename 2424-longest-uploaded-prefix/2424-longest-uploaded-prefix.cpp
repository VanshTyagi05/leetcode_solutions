class LUPrefix {
public:
  vector<bool>uploaded;
  int pointer=0;//first video
    LUPrefix(int n) {
        uploaded.resize(n,0);
    }
    
    void upload(int video) {
        uploaded[video-1]=true;
    }
    
    int longest() {
        
        while(pointer < uploaded.size()&&uploaded[pointer]){
            pointer++;
        }
        return pointer;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */