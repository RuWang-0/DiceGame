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



## Stage 2

### 要求：

掷骰子游戏的基本规则是：每个玩家掷两次骰子，系统根据用户选择的计分方式给出得分，得分多的为赢家。



考虑这是个支持游戏大厅的应用，有很多玩家，可以预先注册，系统可以发起一盘掷骰子游戏（支持同时进行多盘游戏），等待两个玩家加入，用户加入游戏时需要选择计分方式，系统预置的计分方式有【加相后除以6的余数】和【相乘后除以6的余数】。一盘游戏可以支持多轮，即可分几次胜负，每轮需要给出胜负结果。一轮结束后询问第一个加入的用户是否开始下一轮还是结束游戏。如果选择开始下一轮，先打印出前面几轮的胜负结果，然后开始下一轮。选择结束游戏的话也是打印出前面几轮的胜负结果，然后结束游戏。



假设玩家已经注册好，就是说，在主程序中只需要固定写如下的代码，不需要通过交互的方式注册：



Player player1('A')

Player player2('B')



需要用OO的原则对这个应用恰当地进行抽象和封装



### 分析：

1. 游戏中轮与轮之间是不相关的，无状态的，但是需要保存结果
2. VS2019  C++单元测试：https://www.cnblogs.com/puddingcat/p/8620310.html

### 设计思考

1. 