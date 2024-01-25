#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;

    int arr[n], correctPos[n], hash[100001] = {0};

    // process the elements
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = correctPos[i] = x;
        hash[x]++;
    }

    sort(correctPos, correctPos + n);
    
//     for(auto x:arr){
//       cout<<x<<" ";               
//     }

    //cout<<endl;

    /*----------- ALGORITHM PART -------------*/

    int pos = 0, j = 0, partition = 0;

    while (pos < n || j < n) {
        queue<int> q;

        // if the correct element is in the correct position
        if (correctPos[pos] == arr[pos]) {
            cout<<"Debug1"<<endl;
            cout << arr[j] << endl;
            partition++;
            hash[arr[j]]--;
            j++;
            pos = j;
        } else {   // now if the element is not in the correct position
            int minm = 1e9, maxm = -1e9;
            //cout<<"Debug2"<<endl;
            while (j < n && arr[j] != correctPos[pos]) {
              // cout<<"Debug3"<<endl;
               minm = min(minm, arr[j]);
               maxm = max(maxm, arr[j]);
               q.push(arr[j]);
               hash[arr[j]]--;
               j++;
           }
            
            minm = min(minm, arr[j]);
            maxm = max(maxm, arr[j]);
            q.push(arr[j]);
            hash[arr[j]]--;
            cout<<j<<" j"<<endl;
           
           // cout<<minm<<" min "<<maxm<<" maxm"<<endl;

            for (int ele = minm; ele <= maxm; ele++) {
               // cout<<"Debug4"<<endl;
                if (hash[ele]>0) {
                          //cout<<"Debug5"<<endl;
                    q.push(ele);
                    //maxm = max(maxm, ele); 
                    hash[ele]--;

                    while (j < n && arr[j] != ele) {
                       // cout<<"Debug5"<<endl;
                        j++;   // element will always be found since hash[ele] > 0
                    }
                }
            }
            
            cout<<j<<" j"<<endl;

             //now the printing of the partition
            while (!q.empty()) {
                //cout<<"Debug6"<<endl;
                cout << q.front() << " ";
                q.pop();
            }
            cout << endl;

            partition++;
            
            cout<<pos<<" pos"<<endl;
            if (j < n)
                j++;
            pos = j;
            
            cout<<j<<" j"<<endl;
            
        }
    }

    cout << partition << endl;

    return 0;
}
