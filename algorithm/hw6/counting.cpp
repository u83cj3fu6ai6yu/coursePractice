// counting
// hw6 of algorithmics
// 11/22/2016

#include<iostream>
using namespace std;

int mapandtarget(int edge, int target) {
    int arr[edge][edge] = {};

    for(int c=1; c<=(edge+1)/2; c++){
        for(int l=c-1; l<=edge-c; l++)
            for(int u=c-1; u<=edge-c; u++)
                arr[l][u] = c;
    }

    int layer, numperlayer, key=1, i, j, n=0;
    for(layer=1; layer<=(2*edge-1); layer++) {
        if(layer <= edge) {
            for(i=layer-1; i>=0; i--) {
                j = (layer-1)-i;
                n++;
                if(n == target)
                    return arr[i][j];
            }
        }
        else {
            for(numperlayer=edge-1; numperlayer>=1; numperlayer--) {
                for(int k=0; k<numperlayer; k++) {
                    n++;
                    if(n == target)
                        return arr[edge-1-k][(layer-1)-(edge-1-k)];
                }
            }
        }
    }
}

int main() {
    int data;
    cin>>data;

    int ans[data] = {};
    int edge, target;
    for(int i=0; i<data; i++) {
        cin>>edge>>target;
        ans[i] = mapandtarget(edge, target);
    }

    for(int i=0; i<data; i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
