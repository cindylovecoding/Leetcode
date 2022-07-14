preorder(root, left, right)

[3,9,20,15,7]

inorder(left, root, right)

[9,3,15,20,7]

從preorder可以知道第一個元素是root.

在inorder中找到對應的root，root左邊是左子樹，右邊是右子樹。

用遞迴處理左右子樹，直到處理不了就是沒有元素為止。

演算法:
1. 取preorder的第一個元素創建current root。

2. 在inorder中找到root對應的位置。
  a. 如何找到對應位置? 一個一個找O(n)
  
  b. 能否加速? 利用 HashMap 在 O(n) 複雜度下先處理成 {element : index}，之後每次都只需要O(1)時間來找。
    i. [15,20,7] -> {15: 0,20: 1,7: 2
    
3. 把preorder和inorder中對應的左子樹和右子樹的subarray分離出來
  a. 分離方法: 在inorder中找到對應的root，root左邊是左子樹，右邊是右子樹。 preodrder按照inorder同理劃分
  
  b. 分離形式:  
    i. 直接複製subarray -> O(n)
    
    ii. 用2 pointers 來限制邊界 -> O(1) (base case: left pointer > right pointer)
    
4. 遞迴left subtree

5. 遞迴right subtree

6. Base Case: 現在要處理的子樹是空的 ( preorder = inorder = [])
