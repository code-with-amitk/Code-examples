## Studying Genes
- We can study Genes(for diseases) at 3 levels. DNA Level, RNA Level, Proteins
- At all levels we input cell's data and study gene's present and future behaviours, gene expression.
- **[Terms](Terms.md)**

## Tool Design
- **1. Front end Browser**
  - *a. 3D GUI Browser:* We will have a GUI for displaying mutation, gene expression, alternative splicing frequency simulteneously.
  - *b. PHP scripts* allowing the user to submit requests to the database to be displayed in the browser
  - *c. Main page to sub pages:* 
    - Main page will display primary view of user data which is broken deeper onto pathways that are either predefined or added by users. 
    - Main page is sub-divided into a plotting canvas where the genes (nodes) and their connections (edges) are rendered. 

<img src="https://media.springernature.com/lw685/springer-static/image/art%3A10.1186%2Fs12864-016-2389-8/MediaObjects/12864_2016_2389_Fig2_HTML.gif?as=webp" width=600 />
  
- **2. DB backend**
  - *[a. MYSQL or NoSQL DB](/System-Design/Concepts/Databases):* Whole information is stored is on DB and can be customoized based on user input.
- **3. Using ML**
  - *[a. AI powered datasets](https://sites.google.com/site/amitinterviewpreparation/machine-learning):* Datasets will help tool to mature.
  - *[b. Will use multidimensional array from numpy](/Languages/ScriptingLanguages/Python/numpy)*
  - *[c. scikit-learn to process and study data from different sources](/Languages/ScriptingLanguages/Python/scikit-learn)*
- **4. Tool should be scalable and customizable**
