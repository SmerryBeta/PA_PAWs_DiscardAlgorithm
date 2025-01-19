# 代码说明，本代码采用递归思想广度优先遍历所有解法！

## 一、关于函数 void path(vector<Card> cards, Card desktop, vector<Card> solution, int num) 

该函数在test.cpp文件中，使用时分别传入

1.已有卡牌cards

2.桌子上的卡牌desktop

3.存储解决方案的数组solution（直接建一个新的就好了）

4.还有个记录走了多少次次数的num，初始值应该为 0.

## 二、关于取结果

取结果的话直接从map<int, vector<Card>> DEEP_SOLUTION 中取出来最大的就好了，其实这个还有个问题就是都是九次的最优解会相互覆盖。


# 执行结果效果展示如下：
![image](https://github.com/SmerryBeta/PA_PAWs_DiscardAlgorithm/blob/main/%E5%B1%95%E7%A4%BA.png)

# 我想说的话
要是有哪个大佬能把卡牌识别做出来直接把这个代码拿去做出牌路线规划就好了，这样全自动刷猛兽派对PAW牌就不是梦了哈哈哈哈哈Q w Q~
真的我感觉刷这个小鱼干是真的无聊死了要是能做出来我就.............呜呜呜呜呜呜呜呜呜呜呜！！！！！！！
