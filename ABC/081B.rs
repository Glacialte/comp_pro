use proconio::{input, fastout};

fn main() {
    input!{
        n: usize,
        mut a: [i32; n],
    }
    let mut ans = 1 << 30;
    for i in 0..n {
        let mut tmp = 0;
        while a[i] % 2 == 0 {
            a[i] /= 2;
            tmp += 1;
        }
        ans = if tmp < ans {tmp} else {ans};
    }
    println!("{}", ans);
}