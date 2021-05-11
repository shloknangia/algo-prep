// You are given a list dishes, where each element consists of a list of strings beginning with the name of the dish, followed by all the ingredients used in preparing it. You want to group the dishes by ingredients, so that for each ingredient you'll be able to find all the dishes that contain it (if there are at least 2 such dishes).

// Return an array where each element is a list beginning with the ingredient name, followed by the names of all the dishes that contain this ingredient. The dishes inside each list should be sorted lexicographically, and the result array should be sorted lexicographically by the names of the ingredients.

// Example

//     For

//       dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
//                 ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
//                 ["Quesadilla", "Chicken", "Cheese", "Sauce"],
//                 ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]

//     the output should be

//       groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
//                                 ["Salad", "Salad", "Sandwich"],
//                                 ["Sauce", "Pizza", "Quesadilla", "Salad"],
//                                 ["Tomato", "Pizza", "Salad", "Sandwich"]]

//     For

//       dishes = [["Pasta", "Tomato Sauce", "Onions", "Garlic"],
//                 ["Chicken Curry", "Chicken", "Curry Sauce"],
//                 ["Fried Rice", "Rice", "Onions", "Nuts"],
//                 ["Salad", "Spinach", "Nuts"],
//                 ["Sandwich", "Cheese", "Bread"],
//                 ["Quesadilla", "Chicken", "Cheese"]]

//     the output should be

//       groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
//                                 ["Chicken", "Chicken Curry", "Quesadilla"],
//                                 ["Nuts", "Fried Rice", "Salad"],
//                                 ["Onions", "Fried Rice", "Pasta"]]

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<string> v, vector<string> &ing){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\t";
        ing.push_back(v[i]);
    }
}

vector<vector<string>> groupingDishes(vector<vector<string>> dishes) {
    
    map<string, vector<string>> m;
    
    for(int i=0;i<dishes.size();i++){
        for(int j=1;j<dishes[i].size();j++){
            // m[dishes[i][0]].push_back(dishes[i][j]);
            m[dishes[i][j]].push_back(dishes[i][0]);
        }
    }
    vector<vector<string>> out;
    for(auto it= m.begin();it!=m.end();it++){
        if(it->second.size()>1){
            vector<string> ing;
            ing.push_back(it->first);
            sort(it->second.begin(), it->second.end());
            cout<<it->first<<"->";
            print(it->second, ing);
            out.push_back(ing);
            cout<<endl;
        }
    }
    
    return out;
}
