## 设计与重构

### 现在的设计

- 类

  - **CDiceGame**

    - **private**：m_firstRes，m_secondRes
    - **protected**：
      - show_basic_info
      - show_info
      - initial_game
      - read_input
      - loop_game
      - roll_dice
      - cal_res

    - **public**:
      - CDiceGame
      - startGame: call initial_game, loop_game()

### 重构建议

- 类(可能有多个玩家或者骰子或者轮次)

  - Game
    - 其实步骤可分给一下几类。将show_info的switch case都拆开

  - player
    - private member: <vector>roll_dice_result, game_state...
    - 
  - dice
    - roll
    - display?
  - input_validation
    - get_valid_choice