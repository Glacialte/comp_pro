use proconio::{input, fastout};

fn main() {
    input!{
        n: i32,
        y: i32,
    }
    for i in 0..n+1 {
        for j in 0..n-i+1 {
            let sum = 10000*i+5000*j+1000*(n-i-j);
            if sum == y {
                println!("{} {} {}", i, j, n-i-j);
                return;
            }
        }
    }
    println!("-1 -1 -1");
}