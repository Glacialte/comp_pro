use proconio::{input, fastout};

fn main() {
    input!{
        n: usize,
        mut a: [i32; n],
    }
    a.sort();
    let mut alice = 0;
    let mut bob = 0;
    let mut switch = true;
    for i in (0..n).rev() {
        if switch {
            alice += a[i];
        } else {
            bob += a[i];
        }
        switch = !switch;
    }
    println!("{}", alice-bob);
}