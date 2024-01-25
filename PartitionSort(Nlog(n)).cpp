class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();

        int correctPos[n];

    // process the elements
    for(int i = 0; i < n; i++) {
        correctPos[i] = arr[i];
        //hash[arr[i]]++;
    }

    sort(correctPos, correctPos + n);

    /*----------- ALGORITHM PART -------------*/
   
    set<int>s1,s2;
    int partition =0;

    for(int i=0;i<n;i++){
        s1.insert(arr[i]);
        s2.insert(correctPos[i]);

        if(s1==s2)
        {
            partition++;
            s1.clear();
            s2.clear();
        }
    }
    return partition;
    }
};
