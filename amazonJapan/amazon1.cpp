// find the minimum x to make height equal or greater, you can add a amount to a subarray at once.
// eg. 1 4 1 6 2 answer: 7 walk through: add 3 to the subarray from begining to last add 4 to last.

#include<vector>
using namespace std;

int func(vector<int> a){
    int ans =0;

    for(int i =0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            ans += (a[i+1]-a[i]);
        }
    }   
    return ans;
}

// given a cartesian plan and some robots answer how many robots will remain idle. a robot will remain idle if it has 
// a robot up down left and right of it. given x and y array of cordinates.

int func(vector<int>x,vector<int>y){

    unordered_map<int,int>lowestX;
    unordered_map<int,int>lowestY;
    unordered_map<int,int>highestY;
    unordered_map<int,int>highestX;

    for(int i =0;i<x.length();){
        if(lowestX.find(y[i])==lowestX.end()){
            lowestX[y[i]] = x[i];
        }
        else{
            lowestX[y[i]] = min(lowestX[y[i]],x[i]);
        }
        if(highestX.find(y[i])==highestX.end()){
            lowestX[y[i]] = x[i];
        }
        else{
            highestX[y[i]] = max(highestX[y[i]],x[i]);
        }
        if(lowestY.find(x[i])==lowestY.end()){
            lowestY[x[i]] = y[i];
        }
        else{
            lowestY[x[i]] = min(lowestY[x[i]],y[i]);
        }
        if(highestY.find(x[i])==highestY.end()){
            lowestY[x[i]] = y[i];
        }
        else{
            highestY[x[i]] = max(highestY[x[i]],y[i]);
        }
    }

    int ans =0;

    for(int i =0;i<x.length();i++){
        if(lowestX[y[i]]<x[i] and highestX[y[i]]>x[i] and lowestY[x[i]]<y[i] and highestY[x[i]]>y[i]){
            ans++;
        }
    }

}