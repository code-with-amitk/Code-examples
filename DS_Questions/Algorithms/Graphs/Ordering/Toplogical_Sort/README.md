**Topological Sort / Topological Order**
- [What](#w)
- [Algorithm](DS_Questions/Algorithms/Graphs/Ordering/Toplogical_Sort/Kahn_Algo.md)
- [Question on Topological Sort](#q)

### Topological Sort / Topological Order
- In [DAG](DS_Questions/Data_Structures/Graphs/README.md#dag), Print/visit of directed graph such that for edge(ab) where a->b, a should be printed before b.
- Some events should happen before next. Example:
  - _1._ When selecting courses in college, some advanced courses have prerequisites that require you to take some introductory courses first.
```c
course-A ---> course-B ---> course-C	//Topological order would be A,B,C. ie to reach C, course-A should be completed
```

<a name=q></a>
#### Question on Topological Sort
- [CoursesSchedule I](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/CoursesSchedule-1_Detect_cycle_Directed_Graph.md)
- [Course Schedule II](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/CoursesSchedule-2_Topological_Sort.md)
- [Detect Cycle in Directed Graph](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/Detect_cycle_in_directed_graph.md)
- [Find All Possible Recipes from Given Supplies](DS_Questions/Questions/Graphs/Find/Directed_Graph/Acyclic/All_Possible_Recipes_From_Given_Supplies.md)
- [Find Minimum Height Tree](/DS_Questions/Questions/Graphs/Find/Undirected_Graph/Minimum_Height_Tree/)
- [Find Eventual Safe States](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Cyclic/Find_Eventual_Safe_States.md)
- [Order of alphabets in Alien Dictionary](/DS_Questions/Questions/Graphs/Find/Directed_Graph/Order_of_alphabets_in_Alien_Dictionary.md)
