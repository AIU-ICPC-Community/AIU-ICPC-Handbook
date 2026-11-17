import java.io.*;
import java.util.*;

public class Main {

    static class FastReader {
        private final InputStream stream;
        private final byte[] buffer = new byte[1 << 16];
        private int pointer = 0;
        private int length = 0;

        FastReader(InputStream stream) {
            this.stream = stream;
        }

        private int readByte() {
            if (pointer == length) {
                try {
                    length = stream.read(buffer);
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
                pointer = 0;
                if (length <= 0) return -1;
            }
            return buffer[pointer++];
        }

        private int nextNonSpace() {
            int c = readByte();
            while (c != -1 && c <= ' ') c = readByte();
            if (c == -1) throw new NoSuchElementException("End of input");
            return c;
        }

        int nextInt() {
            int c = nextNonSpace();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            int value = 0;
            while (c > ' ') {
                value = value * 10 + (c - '0');
                c = readByte();
            }
            return value * sign;
        }

        long nextLong() {
            int c = nextNonSpace();
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            long value = 0;
            while (c > ' ') {
                value = value * 10 + (c - '0');
                c = readByte();
            }
            return value * sign;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String next() {
            int c = nextNonSpace();
            StringBuilder word = new StringBuilder();
            while (c > ' ') {
                word.append((char) c);
                c = readByte();
            }
            return word.toString();
        }

        String nextLine() {
            StringBuilder line = new StringBuilder();
            int c = readByte();
            while (c != -1 && c != '\n') {
                if (c != '\r') line.append((char) c);
                c = readByte();
            }
            return line.toString();
        }
    }

    static FastReader in = new FastReader(System.in);
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    static void solve() {
        int n = in.nextInt();
        long sum = 0;
        for (int i = 0; i < n; i++) sum += in.nextLong();
        out.println(sum);
    }

    public static void main(String[] args) {
        int testCases = 1;
        // testCases = in.nextInt();
        while (testCases-- > 0) solve();
        out.flush();
    }
}
