struct Solution;
impl Solution {
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        let old_color = image[sr as usize][sc as usize];
        if old_color == new_color {
            return image;
        }
        let mut stack = vec![(sr as usize, sc as usize)];
        while let Some((i, j)) = stack.pop() {
            if image[i][j] == old_color {
                image[i][j] = new_color;
                if i > 0 {
                    stack.push((i - 1, j));
                }
                if i < image.len() - 1 {
                    stack.push((i + 1, j))
                }
                if j > 0 {
                    stack.push((i, j - 1));
                }
                if j < image[0].len() - 1 {
                    stack.push((i, j + 1));
                }
            }
        }
        image
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let result = Solution::flood_fill(vec![vec![1,1,1],vec![1,1,0],vec![1,0,1]], 1, 1, 2);
        assert_eq!(result, [[2,2,2],[2,2,0],[2,0,1]]);
    }

    #[test]
    fn test2() {
        let result = Solution::flood_fill(vec![vec![0,0,0],vec![0,0,0]], 0, 0, 0);
        assert_eq!(result, [[0,0,0],[0,0,0]]);
    }
}
