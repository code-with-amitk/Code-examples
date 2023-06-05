**Check If It Is a Straight Line**
- [Approach-1. Find Slope](#a1)
  - [Complexity](#com)
  - Code
    - [c++](#cpp)
    - [Rust](#rs)
    - [Go](#go)


### [1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
```
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

<a name=a1></a>
### Approach-1. Find Slope
- Find all x are same(if yes all points on straight line)
- Find all y are same(if yes all points on straight line)
- if not find slope

<a name=com></a>
#### Complexity 
- Time complexity: O(mn)
- Space complexity: O(1)

#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
    float x, y;
    float slope;
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Check slope
        x = coordinates[0][0] - coordinates[1][0];
        y = coordinates[0][1] - coordinates[1][1];
        slope = x/y;
        cout << "X=" << x <<", y=" << y << "\n";
        cout << "slope=" << slope << "\n";

        int x1=coordinates[0][0], y1=coordinates[0][1];
        bool stline = true;
        for (int i=1;i<coordinates.size();++i) {
            // if all x are same
            if (x1 != coordinates[i][0]) {
                stline = false;
                break;
            }
        }
        if (stline)
            return true;

        stline = true;
        for (int i=1;i<coordinates.size();++i) {
            // if all x are same
            if (y1 != coordinates[i][1]) {
                stline = false;
                break;
            }
        }
        if (stline)
            return true;

        //sort (coordinates.begin(), coordinates.end());
        for (int i=1;i<coordinates.size()-1;++i) {
            float a = coordinates[i][0] - coordinates[i+1][0];
            float b = coordinates[i][1] - coordinates[i+1][1];
            float s = a/b;
            if (s != slope)
                return false;
            cout << "a=" << a << ", b=" << b << ", s=" << s << "\n";
            //if ((coordinates[i][0] - coordinates[i+1][0]) != x)
            //    return false;
            //if ((coordinates[i][1] - coordinates[i+1][1]) != y)
            //    return false;
        }
        return true;
    }
};
```

<a name=rs></a>
**Rust**
```rs
impl Solution {
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
        let slope:f32 = (coordinates[0][0] as f32 - coordinates[1][0] as f32)/(coordinates[0][1] as f32 - coordinates[1][1] as f32);

        //if all points fall on same line
        let x1 = coordinates[0][0];
        let y1 = coordinates[0][1];
        let mut stline = true;
        for i in 1..coordinates.len() {
            if x1 != coordinates[i][0] {
                stline = false;
                break;
            }
        }
        if stline == true {
            return true;
        }
        stline = true;

        for i in 1..coordinates.len() {
            if y1 != coordinates[i][1] {
                stline = false;
                break;
            }
        }
        if stline == true {
            return true;
        }

        // Check slope
        for i in 1..coordinates.len()-1 {
            let mut s:f32 = (coordinates[i][0] as f32 - coordinates[i+1][0] as f32)/(coordinates[i][1] as f32 - coordinates[i+1][1] as f32);
            if s != slope {
                return false;
            }
        }
        return true;
    }
}
```

<a name=go></a>
**Go**
```go
func checkStraightLine(coordinates [][]int) bool {
    // Calculate the slope
    var slope = float64(coordinates[0][0] - coordinates[1][0])/float64(coordinates[0][1] - coordinates[1][1]);

    // Check if all points lie on straight line
    var x1 = (coordinates[0][0]);
    var y1 = (coordinates[0][1]);
    var stline = true;
    for i := 1; i< len(coordinates); i++ {
        if x1 != coordinates[i][0] {
            stline = false;
            break;
        }
    }
    if stline == true {
        return true;
    }
    stline=true;
    for i := 1; i< len(coordinates); i++ {
        if y1 != coordinates[i][1] {
            stline = false;
            break;
        }
    }
    if stline == true {
        return true;
    }

    // Check slope
    for i := 1; i< len(coordinates)-1; i++ {
        var s = float64(coordinates[i][0] - coordinates[i+1][0])/float64(coordinates[i][1] - coordinates[i+1][1]);
        if s != slope {
            return false;
        }
    }
    return true;
}
```
