# 查找

## 平衡二叉树

头文件：[avltree.h](avltree.h)

实现：

- 插入

  - 右旋

    ```mermaid
    flowchart TD
    	Rt((Root))-->L((L))
    	Rt-->R((R))
    	L-->LL((LL))
    	L-->LR((LR))
    ```
    
    ```mermaid
    flowchart TD
    	Start-->A( L 的左子树 LR 变成 Root 的左子树)
    	A-->B( Root 变成 L 的 右子树)
    	B-->Stop
    ```
    
    ```mermaid
    flowchart TD
    	L((L))-->LL((LL))
    	L-->Rt
    	Rt((Root))-->LR((LR))
    	Rt-->R((R))
    ```
    
  - 左旋：类似右旋

    ```mermaid
    flowchart TD
    	Rt((Root))-->L((L))
    	Rt-->R((R))
    	R-->RL((RL))
    	R-->RR((RR))
    ```

    ```mermaid
    flowchart TD
    	Start-->A( R 左子树 RL 变成 Root 的右子树)
    	A-->B( Root 变成 R 的左子树)
    	B-->Stop
    ```

    ```mermaid
    flowchart TD
    	R((R))-->Rt((Root))
    	R-->RR((RR))
    	Rt-->L((L))
    	Rt-->RL((RL))
    ```

  - 左平衡旋转

    ```mermaid
    flowchart TD
    	Rt((Root:2))-->L((L:1或-1))
    	Rt-->R((R))
    	L-->LL((LL))
    	L-->LR((LR))
    ```

    - LL 型（在左子树的左子树插入导致不平衡）

      即在 LL 中插入一个结点，导致此时不平衡，对 Root 进行一次右旋即可

      ```mermaid
      flowchart TD
      	L((L:0))-->LL((LL))
      	L-->Rt((Root:0))
      	Rt-->LR((LR))
      	Rt-->R((R))
      ```
  
    - LR 型（在左子树的右子树插入导致不平衡）
  
      即在 LR 中插入一个结点，导致此时不平衡，先对 L 进行一次左旋，再对 Root 进行一次右旋即可
      
      ```mermaid
      flowchart TD
      	LR((LR:0))-->L((L:1或0))
      	LR-->Rt((Root:0或-1))
      	L-->LL((LL))
      	L-->LRL((LRL))
      	Rt-->LRR((LRR))
      	Rt-->R
      ```
  
  - 右平衡旋转
  
      ```mermaid
      flowchart TD
      	Rt((Root:-2))-->L((L))
      	Rt-->R((R:1或-1))
      	R-->RL((RL))
      	R-->RR((RR))
      ```
  
    - RR 型（在右子树的右子树插入导致不平衡）
      
        即在 RR 中插入一个结点，导致此时不平衡，对 Root 进行一次左旋即可
      
      ```mermaid
      flowchart TD
      	R((R:0))-->Rt((Root:0))
      	R-->RR((RR))
      	Rt-->L((L))
      	Rt-->RL((RL))
      ```
      
    - RL 型（在右子树的左子树插入导致不平衡）
      
        即在 RL 中插入一个结点，导致此时不平衡，先对 R 进行一次右旋，再对 Root 进行一次左旋即可
        
        ```mermaid
        flowchart TD
        	RL((RL:0))-->Rt((Root:0或1))
        	RL-->R((R:-1或0))
        	Rt-->L((L))
        	Rt-->RLL((RLL))
        	R-->RLR((RLR))
        	R-->RR((RR))
        ```
        
    
  - 平衡插入
  
      ```mermaid
      flowchart TD
      	Start(Start)-->a{"当前树为空？"}
      	a--yes-->b["新建结点给树，taller 设为 true"]
      	b-->
      	a--no-->c{"当前结点数据 == 要插入数据？"}
      	c--no-->d["taller 设为 false"]
      	d-->false["返回 false"]
      	false-->stop(Stop)
      	c--yes-->e{"要插入数据 < 当前结点数据？"}
      	e--yes-->f{"递归调用传入左子树，返回值 == true？"}
      	f--no-->false
      	f--yes-->h{"taller == true？"}
      	h--no-->true["返回true"]
      	true-->stop
      	h--yes-->j{"当前树的平衡因子"}
      	j--左高-->i["左平衡旋转，taller 设为 false"]
      	j--平-->k["平衡因子设为左高（，taller 设为 true）"]
      	j--右高-->l["平衡因子设为平，taller 设为 false"]
      	i-->true
      	k-->true
      	l-->true
      	e--no-->m{"递归调用传入右子树，返回值 == true？"}
      	m--no-->false
      	m--yes-->o{"taller == ture？"}
      %% 此处m出bug
      	o--no-->true
      	o--yes-->p{"当前树的平衡因子"}
      	p--左高-->r["平衡因子设为平，taller 设为 false"]
      	p--平-->s["平衡因子设为右高（，taller 设为 true）"]
      	p--右高-->t["右平衡旋转，taller 设为 false"]
      	r & s & t --> true
      	
      ```
      
      
