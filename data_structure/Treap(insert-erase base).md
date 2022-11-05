# Treap
## 説明
乱択アルゴリズムを用いて平衡を保つ二分探索木。keyだけ見ると二分探索木、priorityだけ見るとヒープになっている。木内部の順序が壊れないようにデータをinsertした後、xorshift（任意の乱数生成方法に置き換えてください）によって得た乱数を用いてボトムアップ式にヒープを再構築する。
```cpp
Treap tp;
tp.insert(5);
tp.find(2);
tp.erase(4);
```
などのように使う。嘘です、使う未来が見えません。~~良い拡張方法をこっそり教えてください~~
## できること
### insert
あるkeyを持つNodeをTreapにinsertする。同じkeyのNodeが存在する時もinsertする。
### erase
あるkeyを持つNodeを1つTreapからeraseする。
### find
あるkeyを持つNodeがTreap内に存在するか調べ、存在すればTrueを返す。
### print_in
in-orderでTreapを探索し、keyとpriorityを一行ずつ出力する。
### print_pre
pre-orderでTreapを探索し、keyとpriorityを一行ずつ出力する。