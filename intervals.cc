#pragma once

#include <vector>

/*
//This will merge overlapping intervals and
//This will return all NON OVERLAPPING intervals
//intervals are already sorted by their start
*/

using namespace std;

void mergeIntervals(vector<int> & a, vector<int> const & b)
{
    //technically this case will always be true because the intervals are pre-sorted
    //however, the rest of the logic is here for completion
    if (a[0] < b[0])
    {
        if (a[1] < b[1])
        {
            //case 2
            a[1] = b[1];
        }
        else
        {
            //case 3
            //always choose the bigger of the two intervals and set it equal to the a interval
            //in this case a is bigger, so set a = a
            //in other words: do nothing
            ;
        }
    }
    else
    {
        if (a[1] > b[1])
        {
            //case 4
            a[0] = b[0];
        }
        else
        {
            //case 5
            a = b;
        }
    }
}

void checkOverlap(vector<vector<int>> & aList, vector<int> const & b)
{
    /*
    **case 1: no overlap, but a then b
    //a2 < b1
    **case 2: a first, overlaps into b, b extends past a
    //a1 < b1 < a2 < b2
    **case 3: a completely encases b
    //a1 < b1 < b2 < a2
    **case 4: b first, overlaps into a, a extends past b
    //b1 < a1 < b2 < a2
    **case 5: b completely encases a
    //b1 < a1 < a2 < b2
    **case 6: no overlap but b then a
    //b2 < a1
    */

    //check against the interval at the back of the output list
    //this is because the input is pre-sorted
    if (aList.back()[1] < b[0] || b[1] < aList.back()[0])
    {
        //case 1 & 6
        //if there is no overlap, add this new interval to the end of the output
        aList.push_back(b);
    }
    else
    {
        mergeIntervals(aList.back(), b);
    }
}

vector<vector<int>> results(vector<vector<int>> const & v)
{
    vector<vector<int>> output;
    //add the interval at the beginning regardless
    //TODO: check if empty
    output.push_back(v.at(0));

    //start loop at the interval after the beginning one
    for (int i = 1; i < v.size(); i++)
    {
        checkOverlap(output, v.at(i));
    }
    return output;
}
