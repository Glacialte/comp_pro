use proconio::{input, fastout};

fn main() {
    input!{
        n: usize,
        mut d: [i32; n],
    }
    d.sort();
    let mut dan = 1;
    for i in 0..n-1 {
        if d[i] < d[i+1] {dan+=1};
    }
    println!("{}", dan);
}