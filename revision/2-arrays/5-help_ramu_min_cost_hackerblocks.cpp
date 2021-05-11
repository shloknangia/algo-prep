#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Help Ramu in Min cost , hackerblock problem
    // public transport in city
    // Input
    // Cost
    // c1 = 1 rickshaw or 1 cab ---- 1 time
    // c2 = 1 rickshaw or 1 cab ---- infinite time
    // c3 = all rickshaw or all cab(either) ---- infinite time
    // c4 = all rickshaw and cab(both) ---- infinite time
    // n rickshaws  , m cabs ramu uses
    // ai<1000 - no of times ramu uses rickshaw i
    // bi<1000 - no of times ramu uses cab i
    /*
        1 3 7 19
        2 3 
        2 5
        4 4 4
    */
   // Output: min sum of rs ramu will have to spend on tickets
   // Output: 12



   // For Cabs
   // cost of first cab = min(4*c1, c2) - buy 4x 1ride or 1 for infinite ride
   // all cabs = [min(4*c1, c2) + min(4*c1, c2) + min(4*c1, c2)] - as 3 cabs 4 ,4 ,4 ----------------{1}
   // cost of all cabs = min({1},c3 )  -------{3}


   // For Rickshaw 
   // cost of 1 Rickshaw = min(2*c1, c2) - buy 2x 1ride or 1 for infinite ride
   // all Rickshaw = [min(2*c1, c2) + min(5*c1, c2) ] - as 3 cabs 2,5 ----------------{2}
   // cost of all Rickshaw = min({2},c3 ) ----------{4}

   // min cost of all = min(c4, {3} + {4})


   int c1,c2, c3, c4;
   cin>>c1>>c2>>c3>>c4;

   int n, m;
   cin>>n>>m;

   int rick[1000], cab[1000]; // usage
   for(int i=0;i<n;i++){
       cin>>rick[i];
   }
   for(int i=0;i<m;i++){
       cin>>cab[i];
   }

   int rickCost = 0; 
   for(int i=0;i<n;i++){
        rickCost += min(rick[i]*c1, c2);
   }
   rickCost = min(rickCost, c3);

   int cabCost = 0; 
   for(int i=0;i<m;i++){
        cabCost += min(cab[i]*c1, c2);
   }
   cabCost = min(cabCost, c3);
   cout<< "min cost:"<< min(rickCost+cabCost, c4);



	return 0;
}


