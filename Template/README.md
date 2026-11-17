# Templates

Starting points for contests. Copy the file, rename it the way the judge expects, and remove what you do not need.

---

## C++

`cpp/main.cpp`

```bash
g++ -std=c++17 -O2 main.cpp -o main
./main
```

* While `ONLINE_JUDGE` is not defined, the program reads `in.txt` and writes `out.txt`, so you can test locally without typing input. Every judge defines `ONLINE_JUDGE`; if one does not, delete that block before submitting.
* It reads a single test case. Uncomment `cin >> t;` to read several.
* `#define int long long` turns every `int` into a 64-bit integer. It removes overflow bugs, but doubles the memory of every `vector<int>`, so drop it on memory-heavy problems.

---

## Java

`java/Main.java`

```bash
javac Main.java
java Main < in.txt
```

* The class must stay `Main` and the file must stay `Main.java`. A public class inside a file with another name is a compile error.
* `in.nextInt()`, `in.nextLong()`, `in.nextDouble()`, `in.next()` and `in.nextLine()` behave like `Scanner`, but read raw bytes instead of regular expressions. On 5 million integers they are roughly 4x faster than `BufferedReader` + `StringTokenizer` and 20x faster than `Scanner`.
* It reads a single test case. Uncomment `testCases = in.nextInt();` to read several.
* `nextInt()` returns an `int`. Use `nextLong()` for values above `2^31`, including anything near `10^18`.
* Always print with `out.println(...)` instead of `System.out.println(...)` inside a loop. `out` is flushed automatically at the end of `main`.
