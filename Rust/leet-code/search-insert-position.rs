impl Solution {
    
  // search insert position to array.
  pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        
    // default insert is -1, if cannot find insert position,
    let mut position: i32 = -1;
        
    // iterative array to find insert position.
    for (i, &v) in nums.iter().enumerate() {
      // if iterator equal target or greater target,
      // position assign the i, then break.
      if v == target || v > target {
        // find out, assign the index to i.
        position = i as i32;        
        break;
      } else if v < target {
        // if target greater than v,
        // explain that the target value is behind.
        continue;
      }
    }
        
    // if no suitable insertion location is found.
    // set length of assignment array.
    return if position == -1 {
      nums.len() as i32
    } else {
      position
    }
  }
}
