class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        sort(candidates.begin(), candidates.end());
        vecotr<int> vi;
        combinationsSum(candidates, target, 0, vi);
        return this->vvi;
    }
private:
    vector<vector<int> > vvi;
    void combinationSum(vecotr<int> & candidates, int target, int start, vector<int> & vi){
        if(target == 0){
            this->vvi.push_back(vi);
            return;
        }
        int length = candidates.size();
        for(int i = start; i < length; ++i){
            if(target < candidates[i]){
                return;
            }
            vi.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, vi);
            vi.pop_back();
        }
    }
};