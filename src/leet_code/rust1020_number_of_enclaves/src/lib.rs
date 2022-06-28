struct Solution;

impl Solution {
    fn explore(grid: &mut Vec<Vec<i32>>, i: i32, j: i32, m: i32, n: i32) {
        let mut stack = vec![(i, j)];
        while let Some((i, j)) = stack.pop() {
            if i.min(j) >= 0 && i < m && j < n && grid[i as usize][j as usize] == 1 {
                grid[i as usize][j as usize] = 0;
                stack.push((i - 1, j));
                stack.push((i + 1, j));
                stack.push((i, j - 1));
                stack.push((i, j + 1));
            }
        }
    }

    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        for i in 0..m {
            if grid[i][0] == 1 {
                Self::explore(&mut grid, i as i32, 0, m as i32, n as i32)
            }
            if n > 1 && grid[i][n - 1] == 1 {
                Self::explore(&mut grid, i as i32, n as i32 - 1, m as i32, n as i32)
            }
        }
        for j in 1..n - 1 {
            if grid[0][j] == 1 {
                Self::explore(&mut grid, 0, j as i32, m as i32, n as i32)
            }
            if m > 1 && grid[m - 1][j] == 1 {
                Self::explore(&mut grid, m as i32 - 1, j as i32, m as i32, n as i32)
            }
        }
        grid.iter()
            .skip(1)
            .take(m - 2)
            .fold(0, |count, row| {
                count + row.iter()
                    .skip(1)
                    .take(n - 2)
                    .filter(|&&e| e == 1)
                    .count()
            }) as i32
    }
}

#[cfg(test)]
mod number_of_enclaves_tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let result = Solution::num_enclaves(vec![
            vec![0, 0, 0, 0],
            vec![1, 0, 1, 0],
            vec![0, 1, 1, 0],
            vec![0, 0, 0, 0],
        ]);
        assert_eq!(result, 3);
    }

    #[test]
    fn test2() {
        let result = Solution::num_enclaves(vec![
            vec![0, 1, 1, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 0, 0],
        ]);
        assert_eq!(result, 0);
    }

    #[test]
    fn test3() {
        let result = Solution::num_enclaves(vec![
            vec![0, 0, 0, 1, 1, 1, 0, 1, 0, 0],
            vec![1, 1, 0, 0, 0, 1, 0, 1, 1, 1],
            vec![0, 0, 0, 1, 1, 1, 0, 1, 0, 0],
            vec![0, 1, 1, 0, 0, 0, 1, 0, 1, 0],
            vec![0, 1, 1, 1, 1, 1, 0, 0, 1, 0],
            vec![0, 0, 1, 0, 1, 1, 1, 1, 0, 1],
            vec![0, 1, 1, 0, 0, 0, 1, 1, 1, 1],
            vec![0, 0, 1, 0, 0, 1, 0, 1, 0, 1],
            vec![1, 0, 1, 0, 1, 1, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 1, 1, 0, 0, 0, 1],
        ]);
        assert_eq!(result, 3);
    }
}
