## Studying Genes
- We can study Genes(for diseases) at 3 levels. DNA Level, RNA Level, Proteins
- At all levels we input cell's data and study gene's present and future behaviours, gene expression.
- **[Terms](Terms.md)**

## [Tool Design](https://bmcgenomics.biomedcentral.com/articles/10.1186/s12864-016-2389-8)
- **1. Front end Browser**
  - *a. 3D GUI Browser:* We will have a GUI for displaying mutation, gene expression, alternative splicing frequency simulteneously.
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

<img src="https://media.springernature.com/lw685/springer-static/image/art%3A10.1186%2Fs12864-016-2389-8/MediaObjects/12864_2016_2389_Fig2_HTML.gif?as=webp" width=500 />
  
- **2. DB backend**
  - *[a. MYSQL or NoSQL DB](/System-Design/Concepts/Databases):* Whole information is stored is on DB and can be customoized based on user input.


- **3. Using ML**
  - *[a. AI powered datasets](https://sites.google.com/site/amitinterviewpreparation/machine-learning):* Datasets will help tool to mature.
  - *[b. Will use multidimensional array from numpy](/Languages/ScriptingLanguages/Python/numpy)*
  - *[c. scikit-learn to process and study data from different sources](/Languages/ScriptingLanguages/Python/scikit-learn)*
  - *[d. Deep Learning using Neural Networks](https://sites.google.com/site/amitinterviewpreparation/machine-learning)* to study gene pattern.


- **4. Tool should be scalable and customizable**
