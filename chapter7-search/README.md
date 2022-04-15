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
    	Rt((Root:2))-->L((L:1))
    	Rt-->R((R))
    	L-->LL((LL))
    	L-->LR((LR))
    ```

    - LL 型（在左子树的左子树插入导致不平衡）

      即在 LL 中插入一个结点，导致此时不平衡，对 Root 进行一次右旋即可

      ```mermaid
      
      ```

    - LR 型（在左子树的右子树插入导致不平衡）

      即在 LR 中插入一个结点，导致此时不平衡，先对 L 进行一次左旋，再对 Root 进行一次右旋即可
      
      ```mermaid
      
      ```
  
  - 右平衡旋转

      ```mermaid
      flowchart TD
      	Rt((Root:-2))-->L((L))
      	Rt-->R((R:1))
      	R-->RL((RL))
      	R-->RR((RR))
      ```
  
    - RR 型（在右子树的右子树插入导致不平衡）
      
        即在 RR 中插入一个结点，导致此时不平衡，对 Root 进行一次左旋即可
      
      ```mermaid
      
      ```
      
    - RL 型（在右子树的左子树插入导致不平衡）
      
        即在 RL 中插入一个结点，导致此时不平衡，先对 R 进行一次右旋，再对 Root 进行一次左旋即可
        
        ```mermaid
        ```
        
        
