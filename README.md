# DiceGame

## Stage 1

### 要求:

- 一个玩家，掷骰子两次，和为 7 则获胜，否则失败。

- 要求控制台介绍游戏规则，并提示操作方式，如Please input your command('s' to start, 'r' to roll the dice ,'q' to quit)。

- 要求打印每次操作后的提示、每次掷骰子的结果，和玩家的胜负        

### 运行结果：

- 输入 s, 开始游戏，打印：Let's start playing games!
- 输入 r, 扔骰子。扔一次打印点数，扔两次打印点数和输赢结果。
- 输入q, 直接结束游戏, 打印：BYE-BYE！

![image-20200407174023946](README.assets/image-20200407174023946.png)

![image-20200407174030527](README.assets/image-20200407174030527.png)

![image-20200407174018642](README.assets/image-20200407174018642.png)

### 构造设计

- 类
  - **CDiceGame**
    - members：
      1. a list of players
    - methods:
      1. startGame
  - **Player**
    - members:
      1. dices: player may have dices
      2. isFinished, isWon: indicating game results
      3. m_turn_round:  current No. of turns
      4. m_curCommand:  current command
    - methods:
      1. playGame: public interface
  - **Dice**
    - members:
      1. upVal: the number facing upwards
    - methods:
      1. rollDice
      2. showVal

