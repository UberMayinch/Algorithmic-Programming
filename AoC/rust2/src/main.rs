use std::fs;

fn main() {
    println!("Hello, world!");
    let mut x = fs::read_to_string("input.txt").expect("should have been able to read file");


}
