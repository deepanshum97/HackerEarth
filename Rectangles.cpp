#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <memory.h>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <list>
#include <cassert>

using namespace std;
 
#define LL long long
#define U unsigned
#define pnt pair<int,int>
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) (((a)>=(0))?(a):(-(a)))
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define FI(i,b) FOR(i,0,b)
#define V(t) vector < t >
#define sz size()

struct Rect
{
    int left;
    int right;
    int top;
    int bottom;
};

 struct Range
{
    int less;
    int greater;

    Range(int l, int g)
    {
        less = (l < g) ? l : g;
        greater = (l + g) - less;
    }

    bool IsOverlapping(const Range& other)
    {
        return !(less > other.greater || other.less > greater);
    }

    void Merge(const Range& other)
    {
        if(IsOverlapping(other))
        {
            less = (less < other.less) ? less : other.less;
            greater = (greater > other.greater) ? greater : other.greater;
        }
    }
};

bool operator < (const Rect & rect1, const Rect & rect2)
{
    return (rect1.right < rect2.right);
}

void GetAllX(const vector<Rect> & rects, vector<int> & xes)
{
    vector<Rect>::const_iterator iter = rects.begin();
    for(; iter != rects.end(); ++ iter)
    {
        xes.push_back(iter->left);
        xes.push_back(iter->right);
    }
}

LL GetRectArea(const Range & rangeX, const list<Range> & rangesOfY)
{
    int width = rangeX.greater - rangeX.less;
   
    list<Range>::const_iterator iter = rangesOfY.begin();
    LL area = 0;
    for(; iter != rangesOfY.end(); ++ iter)
    {
        int height = iter->greater - iter->less;
        area += (LL)width * (LL)height;
    }

    return area;
}

void InsertRangeY(list<Range>& rangesOfY, Range & rangeY)
{
    list<Range>::iterator iter = rangesOfY.begin();
    while(iter != rangesOfY.end())
    {
        if(rangeY.IsOverlapping(*iter))
        {
            rangeY.Merge(*iter);

            list<Range>::iterator iterCopy = iter;
            ++ iter;
            rangesOfY.erase(iterCopy);
        }
        else
            ++ iter;
    }

    rangesOfY.push_back(rangeY);
}

void GetRangesOfY(const vector<Rect>& rects, vector<Rect>::const_iterator iterRect, const Range& rangeX, list<Range>& rangesOfY)
{
    for(; iterRect != rects.end(); ++ iterRect)
    {
        if(rangeX.less < iterRect->right && rangeX.greater > iterRect->left)
        {
            Range r = Range(iterRect->top, iterRect->bottom);           
            InsertRangeY(rangesOfY, r);
        }
    }
}

LL GetArea(vector<Rect>& rects)
{
    // sort rectangles according to x-value of right edges
    sort(rects.begin(), rects.end());

    vector<int> xes;
    GetAllX(rects, xes);
    sort(xes.begin(), xes.end());

    LL area = 0;
    vector<int>::iterator iterX1 = xes.begin();
    vector<Rect>::const_iterator iterRect = rects.begin();
    for(; iterX1 != xes.end() && iterX1 != xes.end() - 1; ++ iterX1)
    {
        vector<int>::iterator iterX2 = iterX1 + 1;

        // filter out duplicated X-es
        if(*iterX1 < *iterX2)
        {
            Range rangeX(*iterX1, *iterX2);

            while(iterRect->right < *iterX1)
                ++ iterRect;

            list<Range> rangesOfY;
            GetRangesOfY(rects, iterRect, rangeX, rangesOfY);
            area += GetRectArea(rangeX, rangesOfY);
        }
    }

    return area;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
       int n;
       scanf("%d", &n);
       vector<Rect> rects;
       for (int i=0 ; i<n ; i++)
       {
           Rect r;
           int x1, y1, x2, y2;
           scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
           r.left = MIN(x1, x2);        
           r.right = MAX(x1, x2);
           r.bottom = MIN(y2, y1);
           r.top = MAX(y2, y1);
           rects.pb(r);
       }
       
       printf("%lld\n",  GetArea(rects));
    }
    return 0;    
}
