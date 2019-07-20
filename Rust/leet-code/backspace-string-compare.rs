impl Solution {
    
    pub fn backspace_compare(s: String, t: String) -> bool {
        // closure function is return string of skip `#`.
        fn parse_string(s: String) -> String {
            // string to char list with iterator.
            let mut chars = s.chars().peekable();
            // a new string storage in heap.
            let mut result = String::new();
            
            // loop list.
            while let character = chars.next() {
                if character == None {
                    break;
                } else if character == Some('#') {
                    // delete last char of string then continue.
                    result.pop();
                } else {
                    // push this char to result string.
                    result.push(character.unwrap());
                }
            }
            
            return result;
        }
        
        return parse_string(s) == parse_string(t);
    }
}
