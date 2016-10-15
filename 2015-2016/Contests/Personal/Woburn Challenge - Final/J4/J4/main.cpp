//
//  main.cpp
//  J4
//
//  Created by Bruno on 2016-05-06.
//  Copyright © 2016 Bruno Almeida. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cows [1000001];
int troughs[1000001];
int taken[1000001];

int main(int argc, const char * argv[]) {
    //freopen("input.txt","r",stdin);
    
    int n,m,k;
    int ridx,lidx,toTake,mini,lowest;
    
    
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; i++)
        scanf("%d",&cows[i]);
    
    for (int i = 0; i < m; i++)
        scanf("%d", &troughs[i]);
    
    sort(cows,cows+n);
    sort(troughs,troughs+m);
    
    for (int i = n-1; i >= 0; i--) {
        
        lowest = cows[i]-k;
        if (lowest < 0)
            lowest = 0;
        ridx = lower_bound(troughs, troughs+m, cows[i]) - troughs - 1;
        lidx = upper_bound(troughs, troughs+m, lowest) - troughs;
        
        if (lowest > 0 && troughs[lidx-1] == lowest)
            lidx--;
        
        //cout << lidx << " " << ridx << endl;
        if (lidx > ridx) {
            cout << -1;
            goto nope;
        }
        mini = *min_element(taken+lidx, taken+ridx);
        for (int j = ridx; j >= lidx; j--) {
            if (taken[j] == mini) {
                taken[j]++;
                break;
            }
        }
    }
    cout << *max_element(taken, taken+m);
    nope:;
    cout << endl;
}
