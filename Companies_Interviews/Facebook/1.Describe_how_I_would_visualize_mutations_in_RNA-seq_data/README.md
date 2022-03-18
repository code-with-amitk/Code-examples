## Studying Genes
- We can study Genes(for diseases) at 3 levels. DNA Level, RNA Level, Proteins
- At all levels we input cell's data and study gene's present and future behaviours, gene expression.
- **[Terms](Terms.md)**

## [Tool Design](https://bmcgenomics.biomedcentral.com/articles/10.1186/s12864-016-2389-8)
- **1. Front end Browser / GUI **
  - *a. 3D View* We will have a GUI for displaying gene mutation, gene data, alternative splicing frequency simulteneously.
  - *b. PHP scripts* allowing the user to submit requests to the database to be displayed in the browser
  - *c. Main page to sub pages:* Main page will display primary view of user data which is broken deeper onto pathways that are either predefined or added by users. 
  - *Others:*
    - Main page is sub-divided into a plotting canvas where the genes (nodes) and their connections (edges) are rendered. 
    - Gene names are shown above each node and gene expression values are represented as green vertical lines
    - Coloured rings will be shown around gene based on whether or not that gene has been alternate behaviour.
    - Search box for rapid browsing of RNA-seq data
    - Zoom in zoom out
    - Click and drag
    - Selection of different RNA-Seq data source.
    - GENE LIST & Selecting gene from list to display information.
      - Also capabilities of predicting Ansectors, Gene Families
  
- **2. DB backend**
  - *[a. MYSQL or NoSQL DB](/System-Design/Concepts/Databases):* Whole information is stored is on DB and can be customoized based on user input.

<img src=https://i.ibb.co/hmTQdw3/RNA-SEQ.jpg width=1200 />

- **3. Using ML**
  - *[a. AI powered datasets](https://sites.google.com/site/amitinterviewpreparation/machine-learning):* Datasets will help tool to mature.
  - *[b. Will use multidimensional array from numpy](/Languages/ScriptingLanguages/Python/numpy)*
  - *[c. scikit-learn to process and study data from different sources](/Languages/ScriptingLanguages/Python/scikit-learn)*
  - *[d. Deep Learning using Neural Networks](https://sites.google.com/site/amitinterviewpreparation/machine-learning)* to study gene pattern.
  - *[e. Tensors(vectors) and tensor flow for numerical computation and large-scale ML](https://sites.google.com/site/amitinterviewpreparation/machine-learning)
  - *[f. Opencv for image processing](/Languages/ScriptingLanguages/Python/machine_learning/tensor_flow/opencv)* Capability to click picture and study his genome

- **4. Tool should be scalable and customizable**
