## Graph DB?
- **Why?** We live in a connected world with most pieces connected and data is connected
- **Graph vs Relational DB**
| | Graph | Relational |
| --- | --- | --- |
| Computing relationships | stores connections alongside the data in the model | Using expensive JOIN operations |

### How Data is stored in Graph
- **Node** Entity of graph storing data.
  - **Data on Node**
    - ***Properties*** These are <key:value> pair stored on node. Node can hold any number of attributes.
    - ***Label*** Each node can have a label representing different role in domain.
    - ***Relationnship** Always directed. Provides connections between two nodes. (e.g. Employee WORKS_FOR Company).
      - Like nodes, relationships can also have properties(Eg: weights, costs, distances, ratings, time intervals, or strengths).
