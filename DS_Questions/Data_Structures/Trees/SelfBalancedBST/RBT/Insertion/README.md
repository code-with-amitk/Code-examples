## Correcting Rule Voilation
- **Rules of Insertion**
  - *1.* If tree is empty add a black node.
  - *2.* Insert new leaf node as Red. 
  - Check Rules to be RBT
```c
    if (self_color == RED && self->parent_color == RED){
            if(self == right_child && self->parent == right_child){
                if(uncle == black){                                                                                   //2a
                    Recolor self->parent=black, grandparent=red. No change in self color
                    single_rotation,                                                                                    
                }else if(uncle == Red){
                    push blackness down from grandparent.                                                 //2b
                    Colorflip grandparent
                    if root becomes red, Recolor to Black
                }
```                
  - *3.* Color properties are satisfied, But tree is not Balanced. BF != 0,1,-1
```c
    Rotate on Root.
    if(root==Red) 
        Recolor root=Black
        Recolor children of Root to Red
        Recolor Grandchild/children to Black to adjust color property
```        
