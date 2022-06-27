struct Solution;

impl Solution {
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        let old_color = image[sr as usize][sc as usize];
        if old_color == new_color {
            return image;
        }
        let (m, n) = (image.len(), image[0].len());
        let mut stack = vec![(sr as usize, sc as usize)];
        while let Some((i, j)) = stack.pop() {
            image[i][j] = new_color;
            if i > 0 && image[i - 1][j] == old_color {
                stack.push((i - 1, j));
            }
            if i < m - 1 && image[i + 1][j] == old_color {
                stack.push((i + 1, j))
            }
            if j > 0 && image[i][j - 1] == old_color {
                stack.push((i, j - 1));
            }
            if j < n - 1 && image[i][j + 1] == old_color {
                stack.push((i, j + 1));
            }
        }
        image
    }
}

#[cfg(test)]
mod flood_fill_tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let result = Solution::flood_fill(vec![
            vec![1, 1, 1],
            vec![1, 1, 0],
            vec![1, 0, 1],
        ], 1, 1, 2);
        assert_eq!(result, [
            [2, 2, 2],
            [2, 2, 0],
            [2, 0, 1]
        ]);
    }

    #[test]
    fn test2() {
        let result = Solution::flood_fill(vec![
            vec![0, 0, 0],
            vec![0, 0, 0],
        ], 0, 0, 0);
        assert_eq!(result, [
            [0, 0, 0],
            [0, 0, 0]
        ]);
    }
}
