struct Solution;

impl Solution {
    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut island;
        let (m, n) = (grid.len(), grid[0].len());
        let mut stack = vec![];
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 0 {
                    stack.push((i, j));
                    island = 1;
                    while let Some((ii, jj)) = stack.pop() {
                        if island == 1 && ii.min(jj) == 0 || ii == m - 1 || jj == n - 1 {
                            island = 0
                        }
                        grid[ii][jj] = 1;
                        if ii > 0 && grid[ii - 1][jj] == 0 {
                            stack.push((ii - 1, jj));
                        }
                        if ii < m - 1 && grid[ii + 1][jj] == 0 {
                            stack.push((ii + 1, jj))
                        }
                        if jj > 0 && grid[ii][jj - 1] == 0 {
                            stack.push((ii, jj - 1));
                        }
                        if jj < n - 1 && grid[ii][jj + 1] == 0 {
                            stack.push((ii, jj + 1));
                        }
                    }
                    ans += island;
                }
            }
        }
        return ans;
    }
}

#[cfg(test)]
mod number_of_closed_islands_tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let result = Solution::closed_island(vec![
            vec![1, 1, 1, 1, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0, 1, 1, 0],
            vec![1, 0, 1, 0, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0, 1, 0, 1],
            vec![1, 1, 1, 1, 1, 1, 1, 0],
        ]);
        assert_eq!(result, 2);
    }

    #[test]
    fn test2() {
        let result = Solution::closed_island(vec![
            vec![0, 0, 1, 0, 0],
            vec![0, 1, 0, 1, 0],
            vec![0, 1, 1, 1, 0],
        ]);
        assert_eq!(result, 1);
    }

    #[test]
    fn test3() {
        let result = Solution::closed_island(vec![
            vec![1, 1, 1, 1, 1, 1, 1],
            vec![1, 0, 0, 0, 0, 0, 1],
            vec![1, 0, 1, 1, 1, 0, 1],
            vec![1, 0, 1, 0, 1, 0, 1],
            vec![1, 0, 1, 1, 1, 0, 1],
            vec![1, 0, 0, 0, 0, 0, 1],
            vec![1, 1, 1, 1, 1, 1, 1],
        ]);
        assert_eq!(result, 2);
    }

    #[test]
    fn test4() {
        let result = Solution::closed_island(vec![
            vec![0, 0, 1, 1, 0, 1, 0, 0, 1, 0],
            vec![1, 1, 0, 1, 1, 0, 1, 1, 1, 0],
            vec![1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
            vec![0, 1, 1, 0, 0, 0, 0, 1, 0, 1],
            vec![0, 0, 0, 0, 0, 0, 1, 1, 1, 0],
            vec![0, 1, 0, 1, 0, 1, 0, 1, 1, 1],
            vec![1, 0, 1, 0, 1, 1, 0, 0, 0, 1],
            vec![1, 1, 1, 1, 1, 1, 0, 0, 0, 0],
            vec![1, 1, 1, 0, 0, 1, 0, 1, 0, 1],
            vec![1, 1, 1, 0, 1, 1, 0, 1, 1, 0],
        ]);
        assert_eq!(result, 5);
    }
}
