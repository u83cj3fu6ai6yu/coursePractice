// branch&bound
// hw8 of algorithm
// 12/13/2016

#include <iostream>
#include <vector>
using namespace std;

//int mincost = 2147483647;
int cost[25] = {};
int pos[25] = {0, 1, 2, 3, 4, 5, 6, 4, 5, 6, 4, 5, 6, 7, 8, 9, 7, 8, 9, 7, 8, 9, 10, 10, 10};

struct ss {
    int vertex[4] = {2147483647, 2147483647, 2147483647, 2147483647};
    int weight[4] = {2147483647, 2147483647, 2147483647, 2147483647};
};
struct ss ans;

struct edge_cost {
    int edge, cost;
};

void sorting(struct edge_cost *visitorder) {
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            if(visitorder[j].cost > visitorder[j+1].cost)
                swap(visitorder[j], visitorder[j+1]);
}

void bb(vector<int> &path, vector<int> &costpath, int &totalcost, int stage) {
    struct edge_cost visitorder[3] = {};
    if(stage == 1) {
        for(int i=1; i<=3; i++) {
            visitorder[i-1].cost = cost[i];
            visitorder[i-1].edge = i;
        }
        // sort from min to max
        sorting(visitorder);
        // dfs
        for(int i=0; i<3; i++) {
            path.push_back(pos[visitorder[i].edge]);
            totalcost += visitorder[i].cost;
            costpath.push_back(totalcost);
            stage++;
            // here
            if(ans.weight[0] > totalcost) {
                ans.vertex[0] = path.back();
                ans.weight[0] = totalcost;
            }
            bb(path, costpath, totalcost, stage);
            path.pop_back();
            totalcost -= visitorder[i].cost;
            costpath.pop_back();
            stage--;
        }
    }
    else if(stage == 2) {
        int postemp = path.back();
        for(int i=1; i<=3; i++) {
            visitorder[i-1].cost = cost[postemp*3 + i];
            visitorder[i-1].edge = postemp*3 + i;
        }
        // sort from min to max
        sorting(visitorder);
        // dfs
        for(int i=0; i<3; i++) {
            path.push_back(pos[visitorder[i].edge]);
            totalcost += visitorder[i].cost;
            costpath.push_back(totalcost);
            stage++;
            // here
            if(ans.weight[1] > totalcost) {
                ans.vertex[1] = path.back();
                ans.weight[1] = totalcost;
            }
            bb(path, costpath, totalcost, stage);
            path.pop_back();
            totalcost -= visitorder[i].cost;
            costpath.pop_back();
            stage--;
        }
    }
    else if(stage == 3) {
        int postemp = path.back();
        for(int i=1; i<=3; i++) {
            visitorder[i-1].cost = cost[postemp*3 + i];
            visitorder[i-1].edge = postemp*3 + i;
        }
        // sort from min to max
        sorting(visitorder);
        // dfs
        for(int i=0; i<3; i++) {
            path.push_back(pos[visitorder[i].edge]);
            totalcost += visitorder[i].cost;
            costpath.push_back(totalcost);
            stage++;
            // here
            if(ans.weight[2] > totalcost) {
                ans.vertex[2] = path.back();
                ans.weight[2] = totalcost;
            }
            bb(path, costpath, totalcost, stage);
            path.pop_back();
            totalcost -= visitorder[i].cost;
            costpath.pop_back();
            stage--;
        }
    }
    else if(stage == 4) {
        int postemp = path.back(), temp;
        if(postemp == 7) {
            temp = 22;
        }
        else if(postemp == 8) {
            temp = 23;
        }
        else if(postemp == 9) {
            temp = 24;
        }
        // if is the optimal solution, record it
        totalcost += cost[temp];
        // here
        if(ans.weight[3] > totalcost) {
            ans.vertex[3] = 10;
            ans.weight[3] = totalcost;
        }
        totalcost -= cost[temp];
    }
}

int main() {
    for(int i=1; i<=24; i++)
        cin>>cost[i];

    vector<int> path, costpath;
    int totalcost = 0, stage = 1;
    bb(path, costpath, totalcost, stage);

    for(int i=0; i<4; i++) {
        cout<<ans.vertex[i]<<" "<<ans.weight[i]<<endl;
    }
    return 0;
}
