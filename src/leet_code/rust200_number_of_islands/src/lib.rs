struct Solution;

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut ans = 0;
        let (m, n) = (grid.len(), grid[0].len());
        let mut stack = vec![];
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '1' {
                    ans += 1;
                    stack.push((i, j));
                    while let Some((ii, jj)) = stack.pop() {
                        grid[ii][jj] = '0';
                        if ii > 0 && grid[ii - 1][jj] == '1' {
                            stack.push((ii - 1, jj));
                        }
                        if ii < m - 1 && grid[ii + 1][jj] == '1'  {
                            stack.push((ii + 1, jj))
                        }
                        if jj > 0  && grid[ii][jj - 1] == '1' {
                            stack.push((ii, jj - 1));
                        }
                        if jj < n - 1 && grid[ii][jj + 1] == '1' {
                            stack.push((ii, jj + 1));
                        }
                    }
                }
            }
        }
        return ans;
    }
}

#[cfg(test)]
mod number_of_islands_tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let result = Solution::num_islands(vec![
            vec!['1', '1', '1', '1', '0'],
            vec!['1', '1', '0', '1', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '0', '0', '0'],
        ]);
        assert_eq!(result, 1);
    }

    #[test]
    fn test2() {
        let result = Solution::num_islands(vec![
            vec!['1', '1', '0', '0', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '1', '0', '0'],
            vec!['0', '0', '0', '1', '1'],
        ]);
        assert_eq!(result, 3);
    }

    #[test]
    fn test3() {
        let result = Solution::num_islands(vec![
            vec!['1', '1', '1'],
            vec!['0', '1', '0'],
            vec!['1', '1', '1'],
        ]);
        assert_eq!(result, 1);
    }
}
