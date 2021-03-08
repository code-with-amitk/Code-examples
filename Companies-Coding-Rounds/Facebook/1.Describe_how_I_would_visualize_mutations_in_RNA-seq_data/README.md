## Studying Genes
- We can study Genes(for diseases) at 3 levels. DNA Level, RNA Level, Proteins
- At all levels we input cell's data and study gene's present and future behaviours, gene expression.

## Terms
- **RNA(Ribonucleic acid)?** This is a polymeric molecule essential in various biological roles in coding, decoding, regulation and expression of genes.
- **Polymeric?** Material consisting of very large molecules, or macromolecules, composed of many repeating subunits.
- **Coding/Genetic Code?** Set of rules used by living cells to translate information encoded within genetic material (DNA or mRNA sequences of nucleotide triplets, or codons) into proteins
- **[DNA](https://sites.google.com/site/pingalacademy1/general-studies/general-science/chemistry/dna-deoxyribonucleic-acid)**
- **DNA Sequencing?** Process of determining the nucleic acid sequence – the order of nucleotides in DNA.
- **Nucleotides?** are organic molecules consisting of a nucleoside and a phosphate.
- **RNA-Seq / RNA-Sequencing?** RNA-Seq is a sequencing technique which uses next-generation sequencing (NGS).
  - Steps
```c
  Input DNA --> Fragmentation --> Adaptor Litigation  --> Sequencing
```

## Visualizing data
- **1. Front end Browser**
  - *a. 3D GUI Browser:* We will have a GUI for displaying mutation, gene expression, alternative splicing frequency simulteneously.
  - *b. PHP scripts* allowing the user to submit requests to the database to be displayed in the browser
  - *c. Main page to sub pages:* 
    - Main page will display primary view of user data which is broken deeper onto pathways that are either predefined or added by users. 
    - Main page is sub-divided into a plotting canvas where the genes (nodes) and their connections (edges) are rendered. 
<img src=https://media.springernature.com/lw685/springer-static/image/art%3A10.1186%2Fs12864-016-2389-8/MediaObjects/12864_2016_2389_Fig2_HTML.gif?as=webp width=600 />
  
- **2. DB backend**
  - *[a. MYSQL or NoSQL DB](/System-Design/Concepts/Databases):* Whole information is stored is on DB and can be customoized based on user input.
- **3. Using ML**
  - *[a. AI powered datasets](https://sites.google.com/site/amitinterviewpreparation/machine-learning):* Datasets will help tool to mature.
  - *[b. Will use multidimensional array from numpy](/Languages/ScriptingLanguages/Python/numpy)*
  - *[c. scikit-learn to process and study data from different sources](/Languages/ScriptingLanguages/Python/scikit-learn)*
- **4. Tool should be scalable and customizable**
