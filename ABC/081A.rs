use proconio::{input, fastout};

fn main() {
    input!{
        s: String,
    }
    let mut ans: i32 = 0;
    for i in s.chars() {
        if i == '1' {
            ans += 1;
        }
    }
    println!("{}", ans);
}

// Vec型を利用
/*
use proconio::{input, fastout};

fn main() {
    let mut v: Vec<char> = vec!['0'; 3];
    let mut ans = 0;
    input!{
        s: String,
    }
    for i in 0..3 {
        v[i as usize] = s.chars().nth(i as usize).unwrap();
    }
    for i in v {
        if i == '1' {ans += 1};
    }
    println!("{}", ans);
}
*/