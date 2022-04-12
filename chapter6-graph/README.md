# 图

## 邻接矩阵

实现：[matrixgraph.c](matrixgraph.c)

- Prim 算法求最小生成树

- Kruskal 算法求最小生成树

  ![Kruskal 算法图](https://www.plantuml.com/plantuml/png/SoWkIImgAStDuG8pkAoURcXxsRJxMT_Iv_DNlfonzSNUDSzw5ptPiUl5lfqlPxSzcxhX-UuMQw2ozJkX8dsJdkxgj-OgpyZCITL0LlLanzeN-sSyczC95DJaKW22p3IDPpFMFzdHy6J7Ag2ofnCwD1LACbBp53Joye4geC3gwTwfJrkNFfyo_rd7X6SB9beZP80wdkxS1aJFvYy56W2HISqfJbNGg4mjreHmyr8oqxY09DX5G6_b5t0v0Bb0Fm80)
  
- Dijkstra 算法求单源最短路径

  ![](https://www.plantuml.com/plantuml/png/SoWkIImgAStDuG8pkAoUTinzkhpxQSyqXRJClCGS7OMKJA1CNdAgZa91Oac6mhEf6vxlRh7cAi_8p4dL0Ak1YZtPiVRPdCwqn9pYrASDUpIv51IidkvRzRnl_Sl6tgTzRSywzptjsA00qV5anou5i4eWQmhS2eLdSngURkX_Fglb-Ux9pvjsMYFCUB5kuVDrqr-iNmgH0Phqj7NRaztJ85oW3fWPx_VqF5tMz6pU7A11JpjcFfkz_rdl8ckkrBmKi8k1timlu780Se5-1W00)
  
- Floyd 求所有顶点对的最短路径


## 邻接表

实现：[adjlistgraph.c](adjlistgraph.c)

- DFS

- BFS

- BFS 求无权图单源最小路径

- 拓扑排序

  ```mermaid
  flowchart TD
  	Start--> B("初始化 in 数组，栈 S，")
  	B-->C(将 in 中为 0 的结点放入栈)
  	C-->E{"S 中还有结点？"}
  	E-- no -->D("全部加入拓扑排序？")
  	E-- yes --> F(取出 S 中的结点)
  	F-->H(加入拓扑排序)
  	H-->G(将该点连接的点的入度-1)
  	G-->K{"该点入度为0？"}
  	K--yes-->L(将该点入栈)
  	K--no-->E
  	L-->E
  	G-->E
  	D--yes-->I(返回 true)
  	D--no-->J(返回 false)
  	I & J-->Stop
  ```

- 关键路径

  ```mermaid
  flowchart TD
  	Start-->a("声明 ve, vl 数组")
  	a-->b("获取拓扑排序顺便获取 ve")
  	b-->c("初始化 vl 为拓扑排序最后一个结点的 ve")
  	c-->d{"拓扑排序中有结点？"}
  	d--yes-->e{"当前结点有后继结点？"}
  	e--yes-->f("当前结点的最晚发生时间 = min{后继结点最晚发生时间 - 权值}")
  	f-->e
  	e--no-->d
  	d--no-->g{"拓扑排序中有结点？"}
  	g--yes-->h{"当前结点有后继结点？"}
  	h--yes-->i("计算 e 和 l")
  	i-->j{"e == l？"}
  	j--yes-->k{"输出两个结点"}
  	j--no-->h
  	k-->h
  	h--no-->g
  	g--no-->Stop
  ```

  

## 边集数组

无实现，仅 Kruskal 算法中使用定义