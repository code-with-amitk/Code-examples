/*
1. Board()  //Control reaches default function first
  1a. boolean variable to track X or 0.
  1b. nine boxes to form board. 
  1c. Render empty Buttons forming a board
    - board-row is class defined in styles.css
2. On click of box control reaches function Button()
  - Button function takes 2 arguments:
    - {value} to be displayed in box
    - callback function where control should reach on click of button
  - button creates a button places {value} in it
  - On click of button control jumps to callback function cbHandleClick()=handleClick
3. On click of box control reaches handleClick(i)
  3a. if ele[i] has any value("X" or "O") returns preventing overwriting
    - Initially, ele is an array filled with null values using Array(9).fill(null)
    - null is false statement in javascript, hence it passes and code continues to next statement
  3b. Copy of ele array is made to temp
  3c. 1st time, x is true Hence goes in and places "X"
  3d. setEle() will write temp to ele
  3e. setX() will flip the boolean variable
4. findWinner()
  4a. Declare winner matrix, length=8
  4b. Find winner if exists yet
5. If winner is found, print winner else move to next player
*/

import { useState } from "react";

function Button({ value, cbHandleClick }) { //2
  return (
    <button className="square" onClick={cbHandleClick}>
      {value}
    </button>
  );
}

export default function Board() {  //1
  const [x, setX] = useState(true); //1a
  const [ele, setEle] = useState(Array(9).fill(null)); //1b

  function handleClick(i) { //3
    if (ele[i]) { //3a
      return;
    }
    const temp = ele.slice(); //3b
    if (x) {  //3c
      temp[i] = "X";
    } else {
      temp[i] = "O";
    }
    setEle(temp); //3d
    setX(!x);     //3e
  }

  const winner = findWinner(ele); //4
  let status;
  if (winner) { //5
    status = 'Winner: ' + winner;
  } else {
    status = 'Next player: ' + (x ? 'X' : 'O');
  }

  return (  //1c
    <>
      <div className="status">{status}</div>
      <div className="board-row">
        <Button value={ele[0]} cbHandleClick={() => handleClick(0)} />
        <Button value={ele[1]} cbHandleClick={() => handleClick(1)} />
        <Button value={ele[2]} cbHandleClick={() => handleClick(2)} />
      </div>
      <div className="board-row">
        <Button value={ele[3]} cbHandleClick={() => handleClick(3)} />
        <Button value={ele[4]} cbHandleClick={() => handleClick(4)} />
        <Button value={ele[5]} cbHandleClick={() => handleClick(5)} />
      </div>
      <div className="board-row">
        <Button value={ele[6]} cbHandleClick={() => handleClick(6)} />
        <Button value={ele[7]} cbHandleClick={() => handleClick(7)} />
        <Button value={ele[8]} cbHandleClick={() => handleClick(8)} />
      </div>
    </>
  );
}

function findWinner(squares) {  //4
  /*
    | 0 1 2 |
    | 3 4 5 |
    | 6 7 8 |
  */
  // 4a. Declare winner matrix, length=8
  const winnerLines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
  ];
  
  for (let i = 0; i < winnerLines.length; i++) {
    // Assign a,b,c with all 8 lines.
    // i=0(a=0,b=1,c=2), i=1(a=3,b=4,c=5) etc
    const [a, b, c] = winnerLines[i];

    // if square[0]=X and square[1]=X and square[2]=X. return X
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
}
