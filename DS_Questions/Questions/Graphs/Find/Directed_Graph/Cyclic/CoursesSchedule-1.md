**Course Schedule**
- [Logic](#l)
  - [Approach-1(Find Cycle using DFS + Backtracking) => TLE]()
  - [Approach-2(Find cycle using Toplogical Sort) => Works](/DS_Questions/Data_Structures/Graphs/Toplogical_Sort/)

### [Course Schedule](https://leetcode.com/problems/course-schedule/)
- There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
- You are given an array prerequisites where `prerequisites[i] = [ai, bi]` indicates that you must take course bi first if you want to take course ai.
- For example, the pair `[0, 1]`, indicates that to take course 0 you have to first take course 1.
- Return true if you can finish all courses. Otherwise, return false.

<a name=l></a>
### Logic
- This is about finding cycle in the graph
- if cycle is present its not possible to finish the courses, else yes
- Courses will be represented as nodes in graph.
