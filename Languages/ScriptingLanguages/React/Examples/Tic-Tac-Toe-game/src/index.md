### Rename this file to `index.js`

- **React Component Names**
|React-Component-Names|Purpose|
|---|---|
|a.Square(Child Component)|Renders a single `<button>`|  
|b.Board(Parent Component)|Renders 9 squares|
|c.Game|Renders a board with placeholder values|

- **Steps**
  - *1.* Pass a prop(called value) to Square Component. Board --prop--> Square
  - *2.* Display the value of prop passed by Board component. Square (Displays)

```js
class Square extends React.Component {
  render() {
    return (
      <button className="square">
        {this.props.value}                        //2. Display the value of prop passed by Board component
      </button>
    );
  }
}

class Board extends React.Component {
  renderSquare(i) {
    return <Square value={i} />;                  //1. Pass a prop(called value) to Square Component
  }
  render() {
    const status = 'Next player: X';
    return (
      <div>
        <div className="status">{status}</div>
        <div className="board-row">
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
        </div>
        <div className="board-row">
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
        </div>
        <div className="board-row">
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
      </div>
    );
  }
}

class Game extends React.Component {
  render() {
    return (
      <div className="game">
        <div className="game-board">
          <Board />
        </div>
        <div className="game-info">
          <div>{/* status */}</div>
          <ol>{/* TODO */}</ol>
        </div>
      </div>
    );
  }
}

ReactDOM.render(
  <Game />,
  document.getElementById('root')
);

```
