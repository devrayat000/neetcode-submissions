// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//     pub val: i32,
//     pub left: Option<Rc<RefCell<TreeNode>>>,
//     pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         TreeNode {
//             val,
//             left: None,
//             right: None,
//         }
//     }
// }

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut tmp = [k, 0];
        Self::dfs(&root, &mut tmp);
        tmp[1]
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, tmp: &mut [i32; 2]) {
        if let Some(n) = node {
            let n = n.borrow();
            Self::dfs(&n.left, tmp);
            if tmp[0] == 0 { return; }

            tmp[0] -= 1;
            if tmp[0] == 0 {
                tmp[1] = n.val;
                return;
            }

            Self::dfs(&n.right, tmp);
        }
    }
}
